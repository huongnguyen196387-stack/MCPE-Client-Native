#include "hud.h"
#include "imgui.h"

namespace HUDModule {
    bool showKeystrokes = true;
    bool showCPS = true;
    bool showArmorStatus = true;
    bool showFPSCounter = true;

    void Init() {
        // Initialize HUD stats
    }

    void RenderHUD() {
        // Overlay FPS Counter
        if (showFPSCounter) {
            ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always);
            ImGui::Begin("FPS HUD", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove);
            ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.5f, 1.0f), "FPS: %.1f", ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // Overlay Keystrokes & CPS
        if (showKeystrokes) {
            ImGui::SetNextWindowPos(ImVec2(10, 60), ImGuiCond_Always);
            ImGui::Begin("Keystrokes HUD", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove);
            ImGui::Text(" [ W ] ");
            ImGui::Text("[A] [S] [D]");
            if (showCPS) {
                ImGui::Text("CPS: 12 | 10");
            }
            ImGui::End();
        }
    }

    void DrawSettings() {
        ImGui::TextDisabled("--- HUD & On-Screen Overlay Settings ---");
        ImGui::Checkbox("Show FPS Counter", &showFPSCounter);
        ImGui::Checkbox("Show Keystrokes UI", &showKeystrokes);
        ImGui::Checkbox("Show CPS Display", &showCPS);
        ImGui::Checkbox("Show Armor & Durability HUD", &showArmorStatus);
    }
}
