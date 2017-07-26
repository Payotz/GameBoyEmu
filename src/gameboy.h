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
    unsigned char ram[64000];
    unsigned char vram[64000];
    unsigned char gfx[256][256];
    unsigned short stack[32];

    bool flagreg_z;
    bool flagreg_n;
    bool flagreg_h;
    bool flagreg_c;

    Register fa;
    Register cb;
    Register ed;
    Register lh;

    unsigned short sp;
    unsigned short pc;

    bool isRunning;

    void initialize();
    void emulateCycle();
    void loadFile(const char* fileName);
    void handleEvents();
    void render();
    void cleanup();

};
#endif 