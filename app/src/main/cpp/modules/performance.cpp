#include "performance.h"
#include "imgui.h"

namespace PerformanceModule {
    bool enableRenderCulling = true;
    float renderDistanceLimit = 48.0f;
    bool disableParticles = false;
    bool unlockFPS = true;

    void Init() {
        // Setup hooks for Culling & FPS Uncap
    }

    void DrawSettings() {
        ImGui::TextDisabled("--- Performance & Optimization Settings ---");
        ImGui::Checkbox("Enable Entity Render Culling", &enableRenderCulling);
        if (enableRenderCulling) {
            ImGui::SliderFloat("Max Entity Render Distance", &renderDistanceLimit, 10.0f, 128.0f, "%.0f Blocks");
        }
        ImGui::Checkbox("Disable Particles (PvP Boost)", &disableParticles);
        ImGui::Checkbox("Unlock FPS / Disable VSync", &unlockFPS);
    }
}
