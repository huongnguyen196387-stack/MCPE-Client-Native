#include <jni.h>
#include <android/log.h>
#include <thread>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"

#include "gui/menu.h"
#include "modules/performance.h"
#include "modules/visuals.h"
#include "modules/combat.h"
#include "modules/hud.h"

#define LOG_TAG "MCPE_Client"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static bool g_Initialized = false;

// Hook Function for eglSwapBuffers
typedef EGLBoolean (*eglSwapBuffers_t)(EGLDisplay dpy, EGLSurface surface);
eglSwapBuffers_t orig_eglSwapBuffers = nullptr;

EGLBoolean hooked_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    if (!g_Initialized) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(1920.0f, 1080.0f); // Default scale

        ImGui_ImplOpenGL3_Init("#version 300 es");
        g_Initialized = true;
        LOGI("ImGui Context & GLES3 initialized successfully!");
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    // Render HUD Overlays (Keystrokes, CPS, Armor Status)
    HUDModule::RenderHUD();

    // Render Main ClickGUI Menu
    ClientMenu::Render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (orig_eglSwapBuffers) {
        return orig_eglSwapBuffers(dpy, surface);
    }
    return EGL_TRUE;
}

void client_main_thread() {
    LOGI("MCPE Native Client loading thread started...");
    
    // Initialize Hooks & Modules
    PerformanceModule::Init();
    VisualsModule::Init();
    CombatModule::Init();
    HUDModule::Init();

    LOGI("All MCPE Client Modules initialized!");
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("JNI_OnLoad called by game process.");
    std::thread(client_main_thread).detach();
    return JNI_VERSION_1_6;
}
