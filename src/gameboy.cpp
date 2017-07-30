#include "gameboy.h"

unsigned short opcode;

SDL_Window *window;
SDL_Renderer *renderTarget;
Rom currentRom;

unsigned char ram[64000];
unsigned char vram[64000];
unsigned char gfx[256][256];
unsigned short stack[32];

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

void GameBoy::initialize(){
    isRunning = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Hello World!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    renderTarget = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderTarget,255,255,255,255);
    for (int i = 0; i < 64000; i++){
        ram[i] = 0;
        vram[i] = 0;
    }
    for (int i = 0; i < 256; i++){
        for(int j = 0; j < 256; j++){
            gfx[i][j] = 0;
        }
    }
    pc = 0x100;
    sp = 0;
}

void GameBoy::loadFile(const char* fileName){
    currentRom.createFromFile(fileName);
}

void GameBoy::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
        isRunning = false;
    }
}

void GameBoy::render(){
    std::cout << "Rendering!" << std::endl;
    SDL_RenderClear(renderTarget);
    SDL_RenderPresent(renderTarget);
}

void GameBoy::cleanup(){
    currentRom.clean();
    SDL_DestroyRenderer(renderTarget);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void op_0x0(){
    pc +=2;
} 

void op_0x1(){
    cb.whole = (opcode & 0x000F);
    pc += 2;
} 

void op_0x2(){
    cb.whole = fa.low;
    pc += 2;
} 

void op_0x3(){
    cb.whole++;
    pc +=2;
}

void op_0x4(){
    cb.low++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_0x5(){
    cb.low--;
    if(cb.low == 0){
        flagreg_z = true;
    }
    flagreg_n = false;
    pc += 2;
} 

void op_0x6(){ // LD nn.n = Put value nn into n | B,n
    cb.low = (opcode & 0x000F);
    pc += 2;
}

void op_0x7(){
    pc += 2;
}

void op_0x8(){
    pc += 2;
}

void op_0x9(){
    lh.whole += cb.whole;
    flagreg_n = 0;
    pc += 2;
}

void op_0xA(){
    fa.low = cb.whole;
    pc += 2;
}

void op_0xB(){
    cb.whole--;
    pc +=2;
}

void op_0xC(){
    cb.high++;
    if(cb.high == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_0xD(){
    cb.high--;
    if(cb.high == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    pc += 2;
}

void op_0xE(){ // LD nn.n = Put value nn into n | C,n
    cb.high = (opcode & 0x000F);
    pc +=2;
}

void op_0xF(){

}

void op_1x0(){

}

void op_1x1(){
    ed.whole = (opcode & 0x000F);
    pc += 2;
}

void op_1x2(){
    ed.whole = fa.low;
    pc +=2;
}

void op_1x3(){
    ed.whole++;
    pc += 2;
}

void op_1x4(){
    ed.low++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_1x5(){
    ed.low--;
    if(ed.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    pc += 2;
}

void op_1x6(){  // LD nn.n = Put value nn into n | D,n
    ed.high = (opcode & 0x000F);
    pc += 2;
}

void op_1x7(){}

void op_1x8(){}

void op_1x9(){
    lh.whole += ed.whole;
    flagreg_n = 0;
    pc += 2;
}

void op_1xA(){
    fa.low = ed.whole;
    pc += 2;
}

void op_1xB(){
    ed.whole--;
    pc += 2;
}

void op_1xC(){
    ed.high++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_1xD(){
    ed.low--;
    if(ed.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    pc +=2;
}

void op_1xE(){}

void op_1xF(){}

void op_2x0(){}

void op_2x1(){
    lh.whole = (opcode & 0x000F);
    pc += 2;
}

void op_2x2(){
    lh.whole = fa.low;
    lh.whole++;
    pc +=2;
}

void op_2x3(){
    lh.whole++;
    pc +=2;
}

void op_2x4(){
    lh.low++;
    if(lh.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_2x5(){
    lh.low--;
    if(lh.low == 0){
        flagreg_z = true;
    }
    flagreg_n = false;
    pc += 2;
}

void op_2x6(){ // LD nn.n = Put value nn into n | H,n
    lh.low = (opcode & 0x000F);
    pc +=2;
}

void op_2x7(){}

void op_2x8(){}

void op_2x9(){
    lh.whole += lh.whole;
    flagreg_n = false;
    pc += 2;
}

void op_2xA(){
    fa.whole = lh.whole;
    pc += 2;
}

void op_2xB(){
    lh.whole--;
    pc += 2;
}

void op_2xC(){
    lh.high++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_2xD(){
    lh.high--;
    if(lh.high == 0){
        flagreg_z = true;
    }
    flagreg_n = true;
}

void op_2xE(){ // LD nn.n = Put value nn into n | L,n
    lh.high = (opcode & 0x000F);
    pc += 2;
}

void op_2xF(){
    //fa.low ~= fa.low;
    pc +=2;
}

void op_3x0(){
    unsigned short upper = (cb.low & 0x00F0) >> 4;
    unsigned short lower = (cb.low & 0x000F);

    fa.low = (lower << 4) | upper;

    if(cb.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_n = false;
    flagreg_h = false;

    pc +=2;
}

void op_3x1(){
    sp = (opcode & 0x000F);
    pc += 2;
}

void op_3x2(){
    lh.whole = fa.low;
    lh.whole--;
    pc += 2;
}

void op_3x3(){
    sp++;
    pc += 2;
}

void op_3x4(){
    lh.whole++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_3x5(){
    lh.whole--;
    if(lh.whole == 0){
        flagreg_z = true;
    }
    flagreg_n = false;
    pc += 2;
}

void op_3x6(){}

void op_3x7(){
    flagreg_c = true;
    flagreg_n = false;
    flagreg_h = false;
}

void op_3x8(){}

void op_3x9(){
    lh.whole += sp;
    flagreg_z = false;
    pc += 2;
}

void op_3xA(){
    fa.low = lh.whole;
    lh.whole--;
    pc += 2;
}

void op_3xB(){
    sp--;
    pc += 2;
}

void op_3xC(){
    fa.low++;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = 1;
    if(flagreg_c == 1){
        flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    pc += 2;
}

void op_3xD(){
    fa.low--;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_n = false;
    pc += 2;
}

void op_3xE(){}

void op_3xF(){
    if(flagreg_c){
        flagreg_c = false;
    }else{
        flagreg_c = true;
    }
    pc += 2;
}

void op_4x0(){
    cb.low = cb.low;
    pc += 2;
}

void op_4x1(){
    cb.low = cb.high;
    pc += 2;
}

void op_4x2(){
    cb.low = ed.low;
    pc += 2;
}

void op_4x3(){
    cb.low = ed.high;
    pc += 2;
}

void op_4x4(){
    cb.low = lh.high;
    pc += 2;
}

void op_4x5(){
    cb.low = lh.low;
    pc += 2;
}

void op_4x6(){
    cb.low = lh.whole;
    pc += 2;
}

void op_4x7(){}

void op_4x8(){}

void op_4x9(){
    cb.high = cb.high;
    pc += 2;
}

void op_4xA(){
    cb.high = fa.low;
    pc += 2;
}

void op_4xB(){
    cb.high = ed.high;
    pc += 2;
}

void op_4xC(){
    cb.high = lh.high;
    pc += 2;
}

void op_4xD(){
    cb.high = lh.high;
    pc += 2;
}

void op_4xE(){
    cb.high = lh.whole;
    pc += 2;
}

void op_4xF(){
    cb.high = fa.low;
    pc += 2;
}

void op_5x0(){
    ed.low = cb.low;
    pc += 2;
}

void op_5x1(){
    ed.low = cb.high;
    pc += 2;
}

void op_5x2(){
    ed.low = ed.low;
    pc += 2;
}

void op_5x3(){
    ed.low = ed.high;
    pc += 2;
}

void op_5x4(){
    ed.low = lh.low;
    pc += 2;
}

void op_5x5(){
    ed.low = lh.high;
    pc += 2;
}

void op_5x6(){
    ed.low = lh.whole;
    pc += 2;
}

void op_5x7(){
    ed.low = fa.high;
    pc += 2;
}

void op_5x8(){
    ed.high = cb.low;
    pc += 2;
}

void op_5x9(){
    ed.high = cb.high;
    pc += 2;
}

void op_5xA(){
    ed.high = ed.low;
    pc += 2;
}

void op_5xB(){
    ed.high = ed.high;
    pc += 2;
}

void op_5xC(){
    ed.high = cb.high;
    pc += 2;
}

void op_5xD(){
    ed.high = lh.high;
    pc += 2;
}

void op_5xE(){
    ed.high = lh.whole;
    pc += 2;
}

void op_5xF(){
    ed.high = fa.low;
    pc += 2;
}

void op_6x0(){
    lh.low = cb.low;
    pc += 2;
}

void op_6x1(){
    lh.low = cb.high;
    pc += 2;
}

void op_6x2(){
    lh.low = ed.low;
    pc += 2;
}

void op_6x3(){
    lh.low = ed.high;
    pc += 2;
}

void op_6x4(){
    lh.low = lh.low;
    pc += 2;
}

void op_6x5(){
    lh.low = lh.high;
    pc += 2;
}

void op_6x6(){
    lh.low = lh.whole;
    pc += 2;
}

void op_6x7(){
    lh.low = fa.low;
    pc += 2;
}

void op_6x8(){
    lh.high = cb.low;
    pc += 2;
}

void op_6x9(){
    lh.high = cb.low;
    pc += 2;
}

void op_6xA(){
    lh.high = ed.low;
    pc += 2;
}

void op_6xB(){
    lh.high = ed.high;
    pc += 2;
}

void op_6xC(){
    lh.high = lh.low;
    pc += 2;
}

void op_6xD(){
    lh.high = lh.high;
    pc += 2;
}

void op_6xE(){
    lh.high = lh.whole;
    pc += 2;
}

void op_6xF(){
    lh.high = fa.low;
    pc += 2;
}

void op_7x0(){
    lh.whole = cb.low;
    pc += 2;
}

void op_7x1(){
    lh.whole = cb.high;
    pc += 2;
}

void op_7x2(){
    lh.whole = ed.low;
    pc += 2;
}

void op_7x3(){
    lh.whole = ed.high;
    pc += 2;
}

void op_7x4(){
    lh.whole = lh.high;
    pc += 2;
}

void op_7x5(){
    lh.whole = lh.low;
    pc += 2;
}

void op_7x6(){
    lh.whole = (opcode & 0x000F);
    pc += 2;
}

void op_7x7(){
    lh.whole = fa.low;
    pc += 2;
}

void op_7x8(){
    cb.low = fa.low;
    pc += 2;
}

void op_7x9(){
    cb.high = fa.low;
    pc += 2;
}

void op_7xA(){
    ed.low = fa.low;
    pc += 2;
}

void op_7xB(){
    ed.high = fa.low;
    pc += 2;
}

void op_7xC(){
    lh.low = fa.low;
    pc += 2;
}

void op_7xD(){
    lh.high = fa.low;
    pc += 2;
}

void op_7xE(){
    fa.low = lh.whole;
    pc += 2;
}

void op_7xF(){
    fa.low = fa.low;
    pc += 2;
}

void op_8x0(){
    fa.low += cb.low;
    pc += 2;
}

void op_8x1(){
    fa.low += cb.high;
    pc += 2;
}

void op_8x2(){
    fa.low += ed.low;
    pc += 2;
}

void op_8x3(){
    fa.low += ed.high;
    pc += 2;
}

void op_8x4(){
    fa.low += lh.low;
    pc += 2;
}

void op_8x5(){
    fa.low += lh.high;
    pc += 2;
}

void op_8x6(){
    fa.low += lh.whole;
    pc += 2;
}

void op_8x7(){
    fa.low += fa.low;
    pc += 2;
}

void op_8x8(){
    fa.low += flagreg_c + cb.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8x9(){
    fa.low += flagreg_c + cb.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xA(){
    fa.low += flagreg_c + ed.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xB(){
    fa.low += flagreg_c + ed.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xC(){
    fa.low += flagreg_c + lh.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xD(){
    fa.low += flagreg_c + lh.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xE(){
    fa.low += flagreg_c + lh.whole;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_8xF(){
    fa.low += flagreg_c + cb.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = (opcode & 0b0000000000000100) >> 2;
    flagreg_c = (opcode & 0b0000000001000000) >> 6;
    pc += 2;
}

void op_9x0(){
    fa.low -= cb.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x1(){
    fa.low -= cb.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x2(){
    fa.low -= ed.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x3(){
    fa.low -= ed.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x4(){
    fa.low -= lh.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x5(){
    fa.low -= lh.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x6(){
    fa.low -= lh.whole;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    pc += 2;
}

void op_9x7(){
    fa.low -= fa.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc += 2;
}

void op_9x8(){
    fa.low -= cb.low + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9x9(){
    fa.low -= cb.high + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xA(){
    fa.low -= ed.low + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xB(){
    fa.low -= ed.high + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xC(){
    fa.low -= lh.low + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xD(){
    fa.low -= lh.high + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xE(){
    fa.low -= lh.whole + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
}

void op_9xF(){
    fa.low -= fa.low + flagreg_c;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 1;
    if(flagreg_c == 0){
        flagreg_c = 1;
        flagreg_h = (opcode & 0x0004) >> 3;
    }
    pc +=2;
    
}

void op_Ax0(){
    fa.low &= cb.low;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax1(){
    fa.low &= cb.high;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax2(){
    fa.low &= ed.low;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax3(){
    fa.low &= ed.high;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax4(){
    fa.low &= lh.low;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax5(){
    fa.low &= lh.high;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax6(){
    fa.low &= lh.whole;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax7(){
    fa.low &= fa.low;
    if(fa.low == 0){
        flagreg_z = 0;
    }
    flagreg_n = 0;
    flagreg_h = 1;
    flagreg_c = 0;
    pc += 2;
}

void op_Ax8(){
    fa.low ^= cb.low;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc += 2;
}

void op_Ax9(){
    fa.low ^= cb.high;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc +=2;
}

void op_AxA(){
    fa.low ^= ed.low;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc += 2;
}

void op_AxB(){
    fa.low ^= ed.high;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc +=2;
}

void op_AxC(){
    fa.low ^= lh.low;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc += 2;
}

void op_AxD(){
    fa.low ^= lh.high;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc +=2;
}

void op_AxE(){
    fa.low ^= lh.whole;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc += 2;
}

void op_AxF(){
    fa.low ^= fa.low;
    if(fa.low == 0){
        flagreg_z = true;
    }
    flagreg_c = false;
    flagreg_h = false;
    flagreg_n = false;
    pc += 2;
}

void op_Bx0(){
    fa.low |= cb.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx1(){
    fa.low |= cb.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx2(){
    fa.low |= ed.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx3(){
    fa.low |= ed.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx4(){
    fa.low |= lh.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx5(){
    fa.low |= lh.high;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx6(){
    fa.low |= lh.whole;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx7(){
    fa.low |= fa.low;
    if(fa.low == 0){
        flagreg_z = 1;
    }
    flagreg_n = 0;
    flagreg_h = 0;
    flagreg_c = 0;
    pc += 2;
}

void op_Bx8(){
    if(fa.low == cb.low){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_Bx9(){
    if(fa.low == cb.high){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxA(){
    if(fa.low == ed.low){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxB(){
    if(fa.low == ed.high){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxC(){
    if(fa.low == lh.low){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxD(){
    if(fa.low == lh.high){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxE(){
    if(fa.low == lh.whole){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_BxF(){
    if(fa.low == fa.low){
        flagreg_z = 1;
        
    }else{
        flagreg_z = 0;
    }
    if(fa.low < fa.low){
        flagreg_c = 1;
    }
    flagreg_h = (opcode & 0x0004) >> 3;
    flagreg_n = 1;
}

void op_Cx0(){}

void op_Cx1(){
    cb.whole = stack[sp];
    sp -=2;
}

void op_Cx2(){}

void op_Cx3(){}

void op_Cx4(){}

void op_Cx5(){
    stack[sp] = cb.whole;
    sp +=2;
}

void op_Cx6(){
    pc += 2;
}

void op_Cx7(){
    pc += 2;
}

void op_Cx8(){
    pc += 2;
}

void op_Cx9(){
    pc += 2;
}

void op_CxA(){
    pc += 2;
}

void op_CxB(){
    pc += 2;
}

void op_CxC(){
    pc += 2;
}

void op_CxD(){
    pc += 2;
}

void op_CxE(){
    pc += 2;
}

void op_CxF(){
    pc += 2;
}

void op_Dx0(){
    pc += 2;
}

void op_Dx1(){
    ed.whole = stack[sp];
    sp -= 2;
}

void op_Dx2(){
    pc += 2;
}

void op_Dx3(){
    pc += 2;
}

void op_Dx4(){
    pc += 2;
}

void op_Dx5(){
    ed.whole = stack[sp];
    sp += 2;
    pc += 2;
}

void op_Dx6(){
    pc += 2;
}

void op_Dx7(){
    pc += 2;
}

void op_Dx8(){
    pc += 2;
}

void op_Dx9(){
    pc += 2;
}

void op_DxA(){
    pc += 2;
}

void op_DxB(){
    pc += 2;
}

void op_DxC(){
    pc += 2;
}

void op_DxD(){
    pc += 2;
}

void op_DxE(){
    pc += 2;
}

void op_DxF(){
    pc += 2;
}

void op_Ex0(){
    pc += 2;
}

void op_Ex1(){
    lh.whole = stack[sp];
    sp += 2;
    pc += 2;
}

void op_Ex2(){
    pc += 2;
}

void op_Ex3(){
    pc += 2;
}

void op_Ex4(){
    pc += 2;
}

void op_Ex5(){
    stack[sp] = lh.whole;
    sp +=2;
}

void op_Ex6(){
    pc += 2;
}

void op_Ex7(){
    pc += 2;
}

void op_Ex8(){
    sp += (opcode & 0x000F);
    pc += 2;
}

void op_Ex9(){
    pc += 2;
}

void op_ExA(){
    pc += 2;
}

void op_ExB(){
    pc += 2;
}

void op_ExC(){
    pc += 2;
}

void op_ExD(){
    pc += 2;
}

void op_ExE(){
    pc += 2;
}

void op_ExF(){
    pc += 2;
}

void op_Fx0(){
    pc += 2;
}

void op_Fx1(){
    fa.whole = stack[sp];
    sp -=2;
}

void op_Fx2(){
    pc += 2;
}

void op_Fx3(){
    pc += 2;
}

void op_Fx4(){
    pc += 2;
}

void op_Fx5(){
    stack[sp] = fa.whole;
    sp +=2;
    pc += 2;
}

void op_Fx6(){
    pc += 2;
}

void op_Fx7(){
    pc += 2;
}

void op_Fx8(){
    lh.whole = sp + (opcode & 0x000F);
    pc += 2;
}

void op_Fx9(){
    sp = lh.whole;
    pc += 2;
}

void op_FxA(){
    fa.low = (opcode & 0x00FF);
    pc += 2;
}

void op_FxB(){
    pc += 2;
}

void op_FxC(){
    pc += 2;
}

void op_FxD(){
    pc += 2;
}

void op_FxE(){
    pc += 2;
}

void op_FxF(){
    pc += 2;
}

void GameBoy::emulateCycle(){
    opcode = currentRom.data[pc] << 8 | currentRom.data[pc+1];
    switch((opcode & 0xF000) >> 12){
        case 0x0:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_0x0();break;
                case 0x1:op_0x1();break;
                case 0x2:op_0x2();break;
                case 0x3:op_0x3();break;
                case 0x4:op_0x4();break;
                case 0x5:op_0x5();break;
                case 0x6:op_0x6();break;
                case 0x7:op_0x7();break;
                case 0x8:op_0x8();break;
                case 0x9:op_0x9();break;
                case 0xA:op_0xA();break;
                case 0xB:op_0xB();break;
                case 0xC:op_0xC();break;
                case 0xD:op_0xD();break;
                case 0xE:op_0xE();break;
                case 0xF:op_0xF();break;
                default:break;
            }
        }break; 
        case 0x1:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_1x0();break;
                case 0x1:op_1x1();break;
                case 0x2:op_1x2();break;
                case 0x3:op_1x3();break;
                case 0x4:op_1x4();break;
                case 0x5:op_1x5();break;
                case 0x6:op_1x6();break;
                case 0x7:op_1x7();break;
                case 0x8:op_1x8();break;
                case 0x9:op_1x9();break;
                case 0xA:op_1xA();break;
                case 0xB:op_1xB();break;
                case 0xC:op_1xC();break;
                case 0xD:op_1xD();break;
                case 0xE:op_1xE();break;
                case 0xF:op_1xF();break;
                default:break;
            }
        }break;
        case 0x2:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_2x0();break;
                case 0x1:op_2x1();break;
                case 0x2:op_2x2();break;
                case 0x3:op_2x3();break;
                case 0x4:op_2x4();break;
                case 0x5:op_2x5();break;
                case 0x6:op_2x6();break;
                case 0x7:op_2x7();break;
                case 0x8:op_2x8();break;
                case 0x9:op_2x9();break;
                case 0xA:op_2xA();break;
                case 0xB:op_2xB();break;
                case 0xC:op_2xC();break;
                case 0xD:op_2xD();break;
                case 0xE:op_2xE();break;
                case 0xF:op_2xF();break;
                default:break;
            }
        }break;
        case 0x3:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_3x0();break;
                case 0x1:op_3x1();break;
                case 0x2:op_3x2();break;
                case 0x3:op_3x3();break;
                case 0x4:op_3x4();break;
                case 0x5:op_3x5();break;
                case 0x6:op_3x6();break;
                case 0x7:op_3x7();break;
                case 0x8:op_3x8();break;
                case 0x9:op_3x9();break;
                case 0xA:op_3xA();break;
                case 0xB:op_3xB();break;
                case 0xC:op_3xC();break;
                case 0xD:op_3xD();break;
                case 0xE:op_3xE();break;
                case 0xF:op_3xF();break;
                default:break;
            }
        }break;
        case 0x4:{
            switch((opcode & 0xF000) >> 8){
                case 0x0:op_4x0();break;
                case 0x1:op_4x1();break;
                case 0x2:op_4x2();break;
                case 0x3:op_4x3();break;
                case 0x4:op_4x4();break;
                case 0x5:op_4x5();break;
                case 0x6:op_4x6();break;
                case 0x7:op_4x7();break;
                case 0x8:op_4x8();break;
                case 0x9:op_4x9();break;
                case 0xA:op_4xA();break;
                case 0xB:op_4xB();break;
                case 0xC:op_4xC();break;
                case 0xD:op_4xD();break;
                case 0xE:op_4xE();break;
                case 0xF:op_4xF();break;
                default:break;
            }
        }break;
        case 0x5:{
            switch((opcode & 0xF000) >> 8){
                case 0x0:op_5x0();break;
                case 0x1:op_5x1();break;
                case 0x2:op_5x2();break;
                case 0x3:op_5x3();break;
                case 0x4:op_5x4();break;
                case 0x5:op_5x5();break;
                case 0x6:op_5x6();break;
                case 0x7:op_5x7();break;
                case 0x8:op_5x8();break;
                case 0x9:op_5x9();break;
                case 0xA:op_5xA();break;
                case 0xB:op_5xB();break;
                case 0xC:op_5xC();break;
                case 0xD:op_5xD();break;
                case 0xE:op_5xE();break;
                case 0xF:op_5xF();break;
                default:break;
            }
        }break;
        case 0x6:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_6x0();break;
                case 0x1:op_6x1();break;
                case 0x2:op_6x2();break;
                case 0x3:op_6x3();break;
                case 0x4:op_6x4();break;
                case 0x5:op_6x5();break;
                case 0x6:op_6x6();break;
                case 0x7:op_6x7();break;
                case 0x8:op_6x8();break;
                case 0x9:op_6x9();break;
                case 0xA:op_6xA();break;
                case 0xB:op_6xB();break;
                case 0xC:op_6xC();break;
                case 0xD:op_6xD();break;
                case 0xE:op_6xE();break;
                case 0xF:op_6xF();break;
                default:break;
            }
        }break;
        case 0x7:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_7x0();break;
                case 0x1:op_7x1();break;
                case 0x2:op_7x2();break;
                case 0x3:op_7x3();break;
                case 0x4:op_7x4();break;
                case 0x5:op_7x5();break;
                case 0x6:op_7x6();break;
                case 0x7:op_7x7();break;
                case 0x8:op_7x8();break;
                case 0x9:op_7x9();break;
                case 0xA:op_7xA();break;
                case 0xB:op_7xB();break;
                case 0xC:op_7xC();break;
                case 0xD:op_7xD();break;
                case 0xE:op_7xE();break;
                case 0xF:op_7xF();break;
                default:break;
            }
        }break;
        case 0x8:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_8x0();break;
                case 0x1:op_8x1();break;
                case 0x2:op_8x2();break;
                case 0x3:op_8x3();break;
                case 0x4:op_8x4();break;
                case 0x5:op_8x5();break;
                case 0x6:op_8x6();break;
                case 0x7:op_8x7();break;
                case 0x8:op_8x8();break;
                case 0x9:op_8x9();break;
                case 0xA:op_8xA();break;
                case 0xB:op_8xB();break;
                case 0xC:op_8xC();break;
                case 0xD:op_8xD();break;
                case 0xE:op_8xE();break;
                case 0xF:op_8xF();break;
                default:break;
            }
        }break;
        case 0x9:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_9x0();break;
                case 0x1:op_9x1();break;
                case 0x2:op_9x2();break;
                case 0x3:op_9x3();break;
                case 0x4:op_9x4();break;
                case 0x5:op_9x5();break;
                case 0x6:op_9x6();break;
                case 0x7:op_9x7();break;
                case 0x8:op_9x8();break;
                case 0x9:op_9x9();break;
                case 0xA:op_9xA();break;
                case 0xB:op_9xB();break;
                case 0xC:op_9xC();break;
                case 0xD:op_9xD();break;
                case 0xE:op_9xE();break;
                case 0xF:op_9xF();break;
                default:break;
            }
        }break;
        case 0xA:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Ax0();break;
                case 0x1:op_Ax1();break;
                case 0x2:op_Ax2();break;
                case 0x3:op_Ax3();break;
                case 0x4:op_Ax4();break;
                case 0x5:op_Ax5();break;
                case 0x6:op_Ax6();break;
                case 0x7:op_Ax7();break;
                case 0x8:op_Ax8();break;
                case 0x9:op_Ax9();break;
                case 0xA:op_AxA();break;
                case 0xB:op_AxB();break;
                case 0xC:op_AxC();break;
                case 0xD:op_AxD();break;
                case 0xE:op_AxE();break;
                case 0xF:op_AxF();break;
                default:break;
            }
        }break;
        case 0xB:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Bx0();break;
                case 0x1:op_Bx1();break;
                case 0x2:op_Bx2();break;
                case 0x3:op_Bx3();break;
                case 0x4:op_Bx4();break;
                case 0x5:op_Bx5();break;
                case 0x6:op_Bx6();break;
                case 0x7:op_Bx7();break;
                case 0x8:op_Bx8();break;
                case 0x9:op_Bx9();break;
                case 0xA:op_BxA();break;
                case 0xB:op_BxB();break;
                case 0xC:op_BxC();break;
                case 0xD:op_BxD();break;
                case 0xE:op_BxE();break;
                case 0xF:op_BxF();break;
                default:break;
            }
        }break;
        case 0xC:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Cx0();break;
                case 0x1:op_Cx1();break;
                case 0x2:op_Cx2();break;
                case 0x3:op_Cx3();break;
                case 0x4:op_Cx4();break;
                case 0x5:op_Cx5();break;
                case 0x6:op_Cx6();break;
                case 0x7:op_Cx7();break;
                case 0x8:op_Cx8();break;
                case 0x9:op_Cx9();break;
                case 0xA:op_CxA();break;
                case 0xB:op_CxB();break;
                case 0xC:op_CxC();break;
                case 0xD:op_CxD();break;
                case 0xE:op_CxE();break;
                case 0xF:op_CxF();break;
                default:break;
            }
        }break;
        case 0xD:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Dx0();break;
                case 0x1:op_Dx1();break;
                case 0x2:op_Dx2();break;
                case 0x3:op_Dx3();break;
                case 0x4:op_Dx4();break;
                case 0x5:op_Dx5();break;
                case 0x6:op_Dx6();break;
                case 0x7:op_Dx7();break;
                case 0x8:op_Dx8();break;
                case 0x9:op_Dx9();break;
                case 0xA:op_DxA();break;
                case 0xB:op_DxB();break;
                case 0xC:op_DxC();break;
                case 0xD:op_DxD();break;
                case 0xE:op_DxE();break;
                case 0xF:op_DxF();break;
                default:break;
            }
        }break;
        case 0xE:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Ex0();break;
                case 0x1:op_Ex1();break;
                case 0x2:op_Ex2();break;
                case 0x3:op_Ex3();break;
                case 0x4:op_Ex4();break;
                case 0x5:op_Ex5();break;
                case 0x6:op_Ex6();break;
                case 0x7:op_Ex7();break;
                case 0x8:op_Ex8();break;
                case 0x9:op_Ex9();break;
                case 0xA:op_ExA();break;
                case 0xB:op_ExB();break;
                case 0xC:op_ExC();break;
                case 0xD:op_ExD();break;
                case 0xE:op_ExE();break;
                case 0xF:op_ExF();break;
                default:break;
            }
        }break;
        case 0xF:{
            switch((opcode & 0x0F00) >> 8){
                case 0x0:op_Fx0();break;
                case 0x1:op_Fx1();break;
                case 0x2:op_Fx2();break;
                case 0x3:op_Fx3();break;
                case 0x4:op_Fx4();break;
                case 0x5:op_Fx5();break;
                case 0x6:op_Fx6();break;
                case 0x7:op_Fx7();break;
                case 0x8:op_Fx8();break;
                case 0x9:op_Fx9();break;
                case 0xA:op_FxA();break;
                case 0xB:op_FxB();break;
                case 0xC:op_FxC();break;
                case 0xD:op_FxD();break;
                case 0xE:op_FxE();break;
                case 0xF:op_FxF();break;
                default:break;
            }
        }break;


        default:break;
    }
}