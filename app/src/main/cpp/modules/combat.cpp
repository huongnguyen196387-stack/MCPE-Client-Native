#include "combat.h"
#include "imgui.h"

namespace CombatModule {
    bool autoClicker = false;
    int targetCPS = 12;
    bool triggerBot = false;
    bool fastPlace = false;

    void Init() {
        // Setup hooks for Input & Attack logic
    }

    void DrawSettings() {
        ImGui::TextDisabled("--- Combat & PvP Utility Settings ---");
        ImGui::Checkbox("Auto Clicker", &autoClicker);
        if (autoClicker) {
            ImGui::SliderInt("Target CPS", &targetCPS, 1, 25);
        }
        ImGui::Checkbox("Triggerbot", &triggerBot);
        ImGui::Checkbox("Fast Place / Fast Use", &fastPlace);
    }
}
