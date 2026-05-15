#include "window/window.hpp"
#include "game/game.h"
#include <thread>
#include <iostream>

int main() {
    //ShowWindow(GetConsoleWindow(), SW_SHOW);

    Overlay overlay;

    overlay.SetupOverlay("not a fivem cheat");

    FiveM::Setup();

    while (overlay.shouldRun) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        overlay.StartRender();

        FiveM::ESP::RunESP();

        if (overlay.RenderMenu) {
            overlay.Render();
        }

        overlay.EndRender();
    }

    return 0;
}