#ifndef HUD_H
#define HUD_H

namespace HUDModule {
    extern bool showKeystrokes;
    extern bool showCPS;
    extern bool showArmorStatus;
    extern bool showFPSCounter;

    void Init();
    void RenderHUD();
    void DrawSettings();
}

#endif
