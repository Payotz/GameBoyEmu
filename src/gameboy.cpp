#include "gameboy.h"

CPU GameBoy::cpu;
Memory GameBoy::memory;

SDL_Window *window;
SDL_Renderer *renderTarget;
Rom currentRom;

bool interruptMode;
unsigned short opcode;

#include "opcode.h"
#include "cb_opcode.h"

void evaluateCB(unsigned short opcode);

void GameBoy::initialize(){
    isRunning = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Hello World!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    renderTarget = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderTarget,255,255,255,255);
    for (int i = 0; i < 64000; i++){
        memory.ram[i] = 0;
        memory.vram[i] = 0;
    }
    for (int i = 0; i < 256; i++){
        for(int j = 0; j < 256; j++){
            memory.gfx[i][j] = 0;
        }
    }
    cpu.pc = 0x100;
    cpu.sp = 0;
    interruptMode = false;
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
    SDL_RenderClear(renderTarget);
    SDL_RenderPresent(renderTarget);
}

void GameBoy::cleanup(){
    currentRom.clean();
    SDL_DestroyRenderer(renderTarget);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GameBoy::emulateCycle(){
    opcode = currentRom.data[cpu.pc] << 8 | currentRom.data[cpu.pc+1];
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
            }
        }break;
        case 0x4:{
            switch((opcode & 0x0F00) >> 8){
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
            }
        }break;
        case 0x5:{
            switch((opcode & 0x0F00) >> 8){
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                case 0xB:evaluateCB(opcode);break;
                case 0xC:op_CxC();break;
                case 0xD:op_CxD();break;
                case 0xE:op_CxE();break;
                case 0xF:op_CxF();break;
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
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
                default:
                    std::cout << "Unknown Opcode : " << ((opcode & 0xFF00) >> 8) << std::endl;
                    break;
            }
        }break;


        default:
            std::cout << "Unknown Opcode : " << ((opcode & 0xF000) >> 12) << std::endl;
            break;
    }
    std::cout << "Program counter: " << GameBoy::cpu.pc << std::endl;
}

void evaluateCB(unsigned short opcode){
    switch((opcode & 0x00F0) >> 4){
        case 0x0:
            switch(opcode & 0x000F){
                case 0x0: op_CB_0x0();break;
                case 0x1: op_CB_0x1();break;
                case 0x2: op_CB_0x2();break;
                case 0x3: op_CB_0x3();break;
                case 0x4: op_CB_0x4();break;
                case 0x5: op_CB_0x5();break;
                case 0x6: op_CB_0x6();break;
                case 0x7: op_CB_0x7();break;
                case 0x8: op_CB_0x8();break;
                case 0x9: op_CB_0x9();break;
                case 0xA: op_CB_0xA();break;
                case 0xB: op_CB_0xB();break;
                case 0xC: op_CB_0xC();break;
                case 0xD: op_CB_0xD();break;
                case 0xE: op_CB_0xE();break;
                case 0xF: op_CB_0xF();break;
                default: break;
            }break;
        case 0x1:
            switch(opcode & 0x000F){
                case 0x0: op_CB_1x0();break;
                case 0x1: op_CB_1x1();break;
                case 0x2: op_CB_1x2();break;
                case 0x3: op_CB_1x3();break;
                case 0x4: op_CB_1x4();break;
                case 0x5: op_CB_1x5();break;
                case 0x6: op_CB_1x6();break;
                case 0x7: op_CB_1x7();break;
                case 0x8: op_CB_1x8();break;
                case 0x9: op_CB_1x9();break;
                case 0xA: op_CB_1xA();break;
                case 0xB: op_CB_1xB();break;
                case 0xC: op_CB_1xC();break;
                case 0xD: op_CB_1xD();break;
                case 0xE: op_CB_1xE();break;
                case 0xF: op_CB_1xF();break;
                default: break;
            }break;
        case 0x2:
            switch(opcode & 0x000F){
                case 0x0: op_CB_2x0();break;
                case 0x1: op_CB_2x1();break;
                case 0x2: op_CB_2x2();break;
                case 0x3: op_CB_2x3();break;
                case 0x4: op_CB_2x4();break;
                case 0x5: op_CB_2x5();break;
                case 0x6: op_CB_2x6();break;
                case 0x7: op_CB_2x7();break;
                case 0x8: op_CB_2x8();break;
                case 0x9: op_CB_2x9();break;
                case 0xA: op_CB_2xA();break;
                case 0xB: op_CB_2xB();break;
                case 0xC: op_CB_2xC();break;
                case 0xD: op_CB_2xD();break;
                case 0xE: op_CB_2xE();break;
                case 0xF: op_CB_2xF();break;
                default: break;
            }break;
        case 0x3:
            switch(opcode & 0x000F){
                case 0x0: op_CB_3x0();break;
                case 0x1: op_CB_3x1();break;
                case 0x2: op_CB_3x2();break;
                case 0x3: op_CB_3x3();break;
                case 0x4: op_CB_3x4();break;
                case 0x5: op_CB_3x5();break;
                case 0x6: op_CB_3x6();break;
                case 0x7: op_CB_3x7();break;
                case 0x8: op_CB_3x8();break;
                case 0x9: op_CB_3x9();break;
                case 0xA: op_CB_3xA();break;
                case 0xB: op_CB_3xB();break;
                case 0xC: op_CB_3xC();break;
                case 0xD: op_CB_3xD();break;
                case 0xE: op_CB_3xE();break;
                case 0xF: op_CB_3xF();break;
                default: break;
            }break;
        case 0x4:
            switch(opcode & 0x000F){
                case 0x0: op_CB_4x0();break;
                case 0x1: op_CB_4x1();break;
                case 0x2: op_CB_4x2();break;
                case 0x3: op_CB_4x3();break;
                case 0x4: op_CB_4x4();break;
                case 0x5: op_CB_4x5();break;
                case 0x6: op_CB_4x6();break;
                case 0x7: op_CB_4x7();break;
                case 0x8: op_CB_4x8();break;
                case 0x9: op_CB_4x9();break;
                case 0xA: op_CB_4xA();break;
                case 0xB: op_CB_4xB();break;
                case 0xC: op_CB_4xC();break;
                case 0xD: op_CB_4xD();break;
                case 0xE: op_CB_4xE();break;
                case 0xF: op_CB_4xF();break;
                default: break;
            }break;
        case 0x5:
            switch(opcode & 0x0050F){
                case 0x0: op_CB_5x0();break;
                case 0x1: op_CB_5x1();break;
                case 0x2: op_CB_5x2();break;
                case 0x3: op_CB_5x3();break;
                case 0x4: op_CB_5x4();break;
                case 0x5: op_CB_5x5();break;
                case 0x6: op_CB_5x6();break;
                case 0x7: op_CB_5x7();break;
                case 0x8: op_CB_5x8();break;
                case 0x9: op_CB_5x9();break;
                case 0xA: op_CB_5xA();break;
                case 0xB: op_CB_5xB();break;
                case 0xC: op_CB_5xC();break;
                case 0xD: op_CB_5xD();break;
                case 0xE: op_CB_5xE();break;
                case 0xF: op_CB_5xF();break;
                default: break;
            }break;
        case 0x6:
            switch(opcode & 0x000F){
                case 0x0: op_CB_6x0();break;
                case 0x1: op_CB_6x1();break;
                case 0x2: op_CB_6x2();break;
                case 0x3: op_CB_6x3();break;
                case 0x4: op_CB_6x4();break;
                case 0x5: op_CB_6x5();break;
                case 0x6: op_CB_6x6();break;
                case 0x7: op_CB_6x7();break;
                case 0x8: op_CB_6x8();break;
                case 0x9: op_CB_6x9();break;
                case 0xA: op_CB_6xA();break;
                case 0xB: op_CB_6xB();break;
                case 0xC: op_CB_6xC();break;
                case 0xD: op_CB_6xD();break;
                case 0xE: op_CB_6xE();break;
                case 0xF: op_CB_6xF();break;
                default: break;
            }break;
        case 0x7:
            switch(opcode & 0x000F){
                case 0x0: op_CB_7x0();break;
                case 0x1: op_CB_7x1();break;
                case 0x2: op_CB_7x2();break;
                case 0x3: op_CB_7x3();break;
                case 0x4: op_CB_7x4();break;
                case 0x5: op_CB_7x5();break;
                case 0x6: op_CB_7x6();break;
                case 0x7: op_CB_7x7();break;
                case 0x8: op_CB_7x8();break;
                case 0x9: op_CB_7x9();break;
                case 0xA: op_CB_7xA();break;
                case 0xB: op_CB_7xB();break;
                case 0xC: op_CB_7xC();break;
                case 0xD: op_CB_7xD();break;
                case 0xE: op_CB_7xE();break;
                case 0xF: op_CB_7xF();break;
                default: break;
            }break;
        case 0x8:
            switch(opcode & 0x000F){
                case 0x0: op_CB_8x0();break;
                case 0x1: op_CB_8x1();break;
                case 0x2: op_CB_8x2();break;
                case 0x3: op_CB_8x3();break;
                case 0x4: op_CB_8x4();break;
                case 0x5: op_CB_8x5();break;
                case 0x6: op_CB_8x6();break;
                case 0x7: op_CB_8x7();break;
                case 0x8: op_CB_8x8();break;
                case 0x9: op_CB_8x9();break;
                case 0xA: op_CB_8xA();break;
                case 0xB: op_CB_8xB();break;
                case 0xC: op_CB_8xC();break;
                case 0xD: op_CB_8xD();break;
                case 0xE: op_CB_8xE();break;
                case 0xF: op_CB_8xF();break;
                default: break;
            }break;
        case 0x9:
            switch(opcode & 0x000F){
                case 0x0: op_CB_9x0();break;
                case 0x1: op_CB_9x1();break;
                case 0x2: op_CB_9x2();break;
                case 0x3: op_CB_9x3();break;
                case 0x4: op_CB_9x4();break;
                case 0x5: op_CB_9x5();break;
                case 0x6: op_CB_9x6();break;
                case 0x7: op_CB_9x7();break;
                case 0x8: op_CB_9x8();break;
                case 0x9: op_CB_9x9();break;
                case 0xA: op_CB_9xA();break;
                case 0xB: op_CB_9xB();break;
                case 0xC: op_CB_9xC();break;
                case 0xD: op_CB_9xD();break;
                case 0xE: op_CB_9xE();break;
                case 0xF: op_CB_9xF();break;
                default: break;
            }break;
        case 0xA:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Ax0();break;
                case 0x1: op_CB_Ax1();break;
                case 0x2: op_CB_Ax2();break;
                case 0x3: op_CB_Ax3();break;
                case 0x4: op_CB_Ax4();break;
                case 0x5: op_CB_Ax5();break;
                case 0x6: op_CB_Ax6();break;
                case 0x7: op_CB_Ax7();break;
                case 0x8: op_CB_Ax8();break;
                case 0x9: op_CB_Ax9();break;
                case 0xA: op_CB_AxA();break;
                case 0xB: op_CB_AxB();break;
                case 0xC: op_CB_AxC();break;
                case 0xD: op_CB_AxD();break;
                case 0xE: op_CB_AxE();break;
                case 0xF: op_CB_AxF();break;
                default: break;
            }break;
        case 0xB:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Bx0();break;
                case 0x1: op_CB_Bx1();break;
                case 0x2: op_CB_Bx2();break;
                case 0x3: op_CB_Bx3();break;
                case 0x4: op_CB_Bx4();break;
                case 0x5: op_CB_Bx5();break;
                case 0x6: op_CB_Bx6();break;
                case 0x7: op_CB_Bx7();break;
                case 0x8: op_CB_Bx8();break;
                case 0x9: op_CB_Bx9();break;
                case 0xA: op_CB_BxA();break;
                case 0xB: op_CB_BxB();break;
                case 0xC: op_CB_BxC();break;
                case 0xD: op_CB_BxD();break;
                case 0xE: op_CB_BxE();break;
                case 0xF: op_CB_BxF();break;
                default: break;
            }break;
        case 0xC:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Cx0();break;
                case 0x1: op_CB_Cx1();break;
                case 0x2: op_CB_Cx2();break;
                case 0x3: op_CB_Cx3();break;
                case 0x4: op_CB_Cx4();break;
                case 0x5: op_CB_Cx5();break;
                case 0x6: op_CB_Cx6();break;
                case 0x7: op_CB_Cx7();break;
                case 0x8: op_CB_Cx8();break;
                case 0x9: op_CB_Cx9();break;
                case 0xA: op_CB_CxA();break;
                case 0xB: op_CB_CxB();break;
                case 0xC: op_CB_CxC();break;
                case 0xD: op_CB_CxD();break;
                case 0xE: op_CB_CxE();break;
                case 0xF: op_CB_CxF();break;
                default: break;
            }break;
        case 0xD:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Dx0();break;
                case 0x1: op_CB_Dx1();break;
                case 0x2: op_CB_Dx2();break;
                case 0x3: op_CB_Dx3();break;
                case 0x4: op_CB_Dx4();break;
                case 0x5: op_CB_Dx5();break;
                case 0x6: op_CB_Dx6();break;
                case 0x7: op_CB_Dx7();break;
                case 0x8: op_CB_Dx8();break;
                case 0x9: op_CB_Dx9();break;
                case 0xA: op_CB_DxA();break;
                case 0xB: op_CB_DxB();break;
                case 0xC: op_CB_DxC();break;
                case 0xD: op_CB_DxD();break;
                case 0xE: op_CB_DxE();break;
                case 0xF: op_CB_DxF();break;
                default: break;
            }break;
        case 0xE:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Ex0();break;
                case 0x1: op_CB_Ex1();break;
                case 0x2: op_CB_Ex2();break;
                case 0x3: op_CB_Ex3();break;
                case 0x4: op_CB_Ex4();break;
                case 0x5: op_CB_Ex5();break;
                case 0x6: op_CB_Ex6();break;
                case 0x7: op_CB_Ex7();break;
                case 0x8: op_CB_Ex8();break;
                case 0x9: op_CB_Ex9();break;
                case 0xA: op_CB_ExA();break;
                case 0xB: op_CB_ExB();break;
                case 0xC: op_CB_ExC();break;
                case 0xD: op_CB_ExD();break;
                case 0xE: op_CB_ExE();break;
                case 0xF: op_CB_ExF();break;
                default: break;
            }break;
        case 0xF:
            switch(opcode & 0x000F){
                case 0x0: op_CB_Fx0();break;
                case 0x1: op_CB_Fx1();break;
                case 0x2: op_CB_Fx2();break;
                case 0x3: op_CB_Fx3();break;
                case 0x4: op_CB_Fx4();break;
                case 0x5: op_CB_Fx5();break;
                case 0x6: op_CB_Fx6();break;
                case 0x7: op_CB_Fx7();break;
                case 0x8: op_CB_Fx8();break;
                case 0x9: op_CB_Fx9();break;
                case 0xA: op_CB_FxA();break;
                case 0xB: op_CB_FxB();break;
                case 0xC: op_CB_FxC();break;
                case 0xD: op_CB_FxD();break;
                case 0xE: op_CB_FxE();break;
                case 0xF: op_CB_FxF();break;
                default: break;
            }break;
        default:break;
    }
}