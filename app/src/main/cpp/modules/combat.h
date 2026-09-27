#ifndef COMBAT_H
#define COMBAT_H

namespace CombatModule {
    extern bool autoClicker;
    extern int targetCPS;
    extern bool triggerBot;
    extern bool fastPlace;

    void Init();
    void DrawSettings();
}

#endif
