#ifndef GAMEBOY__
#define GAMEBOY__

#include <SDL2/SDL.h>
#include "utilities.h"

enum STATE{
    POWERUP,
    STOP,
    LOWPOWER
};

struct Memory{
    unsigned char ram[64000];
    unsigned char vram[64000];
    unsigned char gfx[256][256];
    unsigned short stack[32];
};

struct CPU{
    unsigned short flagreg_z;
    unsigned short flagreg_n;
    unsigned short flagreg_h;
    unsigned short flagreg_c;

    struct Register fa;
    struct Register cb;
    struct Register ed;
    struct Register lh;

    unsigned short sp;
    unsigned short pc;
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

        static Memory memory;
        static CPU cpu;

};
#endif 