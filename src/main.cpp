#include "gameboy.h"
#undef main
int main(int argc, char *argv[]){
    std::unique_ptr<GameBoy> gb = std::make_unique<GameBoy>();
    gb->initialize();
    gb->loadFile(argv[1]);
    while(gb->isRunning){
        gb->handleEvents();
        gb->emulateCycle();
        gb->render();
    }
    gb->cleanup();
    return 0;
}