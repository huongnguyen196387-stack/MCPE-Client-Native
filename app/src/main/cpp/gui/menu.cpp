#include "menu.h"
#include "imgui.h"
#include "../modules/performance.h"
#include "../modules/visuals.h"
#include "../modules/combat.h"
#include "../modules/hud.h"

namespace ClientMenu {
    bool showMenu = true;
    int currentTab = 0;

    void Render() {
        if (!showMenu) return;

        ImGui::SetNextWindowSize(ImVec2(650, 420), ImGuiCond_FirstUseEver);
        ImGui::Begin("MCPE Custom Client v1.0 | Mod Menu", &showMenu, ImGuiWindowFlags_NoCollapse);

        // Sidebar Navigation
        if (ImGui::Button("Visuals", ImVec2(120, 35))) currentTab = 0;
        ImGui::SameLine();
        if (ImGui::Button("Combat/PvP", ImVec2(120, 35))) currentTab = 1;
        ImGui::SameLine();
        if (ImGui::Button("HUD & UI", ImVec2(120, 35))) currentTab = 2;
        ImGui::SameLine();
        if (ImGui::Button("Performance", ImVec2(120, 35))) currentTab = 3;

        ImGui::Separator();

        if (currentTab == 0) {
            VisualsModule::DrawSettings();
        } else if (currentTab == 1) {
            CombatModule::DrawSettings();
        } else if (currentTab == 2) {
            HUDModule::DrawSettings();
        } else if (currentTab == 3) {
            PerformanceModule::DrawSettings();
        }

        ImGui::End();
    }
}
