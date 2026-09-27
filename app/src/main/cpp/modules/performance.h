#ifndef PERFORMANCE_H
#define PERFORMANCE_H

namespace PerformanceModule {
    extern bool enableRenderCulling;
    extern float renderDistanceLimit;
    extern bool disableParticles;
    extern bool unlockFPS;

    void Init();
    void DrawSettings();
}

#endif
