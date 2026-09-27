#ifndef VISUALS_H
#define VISUALS_H

namespace VisualsModule {
    extern bool fullbright;
    extern bool customZoom;
    extern float zoomFOV;
    extern bool motionBlur;
    extern float motionBlurAmount;
    extern bool freelook;

    void Init();
    void DrawSettings();
}

#endif
