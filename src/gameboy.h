#ifndef GAMEBOY__
#define GAMEBOY__

#include <SDL2/SDL.h>
#include "utilities.h"

enum STATE{
    POWERUP,
    STOP,
    LOWPOWER
};

struct GameBoy{
    public:
        
        bool isRunning;

        void initialize();
        void emulateCycle();
        void loadFile(const char* fileName);
        void handleEvents();
        void render();
        void cleanup();

};
#endif 