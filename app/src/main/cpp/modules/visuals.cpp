#include "visuals.h"
#include "imgui.h"

namespace VisualsModule {
    bool fullbright = true;
    bool customZoom = false;
    float zoomFOV = 30.0f;
    bool motionBlur = false;
    float motionBlurAmount = 0.4f;
    bool freelook = false;

    void Init() {
        // Setup hooks for Gamma, FOV, and Motion Blur
    }

    void DrawSettings() {
        ImGui::TextDisabled("--- Visual & Graphics Settings ---");
        ImGui::Checkbox("Fullbright (Gamma 1000)", &fullbright);
        ImGui::Checkbox("Enable Custom Zoom", &customZoom);
        if (customZoom) {
            ImGui::SliderFloat("Zoom FOV", &zoomFOV, 10.0f, 70.0f, "%.0f deg");
        }
        ImGui::Checkbox("Enable Motion Blur", &motionBlur);
        if (motionBlur) {
            ImGui::SliderFloat("Blur Intensity", &motionBlurAmount, 0.1f, 0.9f, "%.2f");
        }
        ImGui::Checkbox("Freelook / 360 Camera", &freelook);
    }
}
