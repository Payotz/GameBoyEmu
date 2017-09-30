#pragma once

void op_0x0(){
    GameBoy::cpu.pc +=2;
} 

void op_0x1(){
    GameBoy::cpu.cb.whole = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
} 

void op_0x2(){
    GameBoy::cpu.cb.whole = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
} 

void op_0x3(){
    GameBoy::cpu.cb.whole++;
    GameBoy::cpu.pc+=2;
}

void op_0x4(){
    GameBoy::cpu.cb.low++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_0x5(){
    GameBoy::cpu.cb.low--;
    if(GameBoy::cpu.cb.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
} 

void op_0x6(){ // LD nn.n = Put value nn into n | B,n
    GameBoy::cpu.cb.low = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_0x7(){
    GameBoy::cpu.pc+=2;
}

void op_0x8(){
    GameBoy::cpu.sp = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_0x9(){
    GameBoy::cpu.lh.whole += GameBoy::cpu.cb.whole;
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000010000000000) >> 10;
    GameBoy::cpu.flagreg_c = (opcode & 0b0100000000000000) >> 14;
    GameBoy::cpu.pc+=2;
}

void op_0xA(){
    GameBoy::cpu.fa.low = GameBoy::cpu.cb.whole;
    GameBoy::cpu.pc+=2;
}

void op_0xB(){
    GameBoy::cpu.cb.whole--;
    GameBoy::cpu.pc+=2;
}

void op_0xC(){
    GameBoy::cpu.cb.high++;
    if(GameBoy::cpu.cb.high == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_0xD(){
    GameBoy::cpu.cb.high--;
    if(GameBoy::cpu.cb.high == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.pc+=2;
}

void op_0xE(){ // LD nn.n = Put value nn into n | C,n
    GameBoy::cpu.cb.high = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_0xF(){
    GameBoy::cpu.pc+=2;
}

void op_1x0(){
    GameBoy::cpu.pc+=2;
}

void op_1x1(){
    GameBoy::cpu.ed.whole = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_1x2(){
    GameBoy::cpu.ed.whole = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_1x3(){
    GameBoy::cpu.ed.whole++;
    GameBoy::cpu.pc+=2;
}

void op_1x4(){
    GameBoy::cpu.ed.low++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_1x5(){
    GameBoy::cpu.ed.low--;
    if(GameBoy::cpu.ed.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.pc+=2;
}

void op_1x6(){  // LD nn.n = Put value nn into n | D,n
    GameBoy::cpu.ed.low = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_1x7(){
    GameBoy::cpu.pc+=2;
}

void op_1x8(){
    GameBoy::cpu.pc += (opcode & 0x000F);
}

void op_1x9(){
    GameBoy::cpu.lh.whole += GameBoy::cpu.ed.whole;
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000010000000000) >> 10;
    GameBoy::cpu.flagreg_c = (opcode & 0b0100000000000000) >> 14;
    GameBoy::cpu.pc+=2;
}

void op_1xA(){
    GameBoy::cpu.fa.low = GameBoy::cpu.ed.whole;
    GameBoy::cpu.pc+=2;
}

void op_1xB(){
    GameBoy::cpu.ed.whole--;
    GameBoy::cpu.pc+=2;
}

void op_1xC(){
    GameBoy::cpu.ed.high++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_1xD(){
    GameBoy::cpu.ed.low--;
    if(GameBoy::cpu.ed.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.pc+=2;
}

void op_1xE(){
    GameBoy::cpu.ed.low = opcode & 0x000F;
    GameBoy::cpu.pc+=2;
}

void op_1xF(){
    GameBoy::cpu.pc+=2;
}

void op_2x0(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 0){
        GameBoy::cpu.pc += (opcode & 0x000F);
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_2x1(){
    GameBoy::cpu.lh.whole = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_2x2(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.fa.low;
    GameBoy::cpu.lh.whole++;
    GameBoy::cpu.pc+=2;
}

void op_2x3(){
    GameBoy::cpu.lh.whole++;
    GameBoy::cpu.pc+=2;
}

void op_2x4(){
    GameBoy::cpu.lh.low++;
    if(GameBoy::cpu.lh.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_2x5(){
    GameBoy::cpu.lh.low--;
    if(GameBoy::cpu.lh.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_2x6(){ // LD nn.n = Put value nn into n | H,n
    GameBoy::cpu.lh.low = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_2x7(){
    GameBoy::cpu.pc+=2;
}

void op_2x8(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 1){
        GameBoy::cpu.pc += (opcode & 0x000F);
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_2x9(){
    GameBoy::cpu.lh.whole += GameBoy::cpu.lh.whole;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_2xA(){
    GameBoy::cpu.fa.whole = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_2xB(){
    GameBoy::cpu.lh.whole--;
    GameBoy::cpu.pc+=2;
}

void op_2xC(){
    GameBoy::cpu.lh.high++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_2xD(){
    GameBoy::cpu.lh.high--;
    if(GameBoy::cpu.lh.high == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = true;
    GameBoy::cpu.pc+=2;
}

void op_2xE(){ // LD nn.n = Put value nn into n | L,n
    GameBoy::cpu.lh.high = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_2xF(){
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_c = 0;
    }else{
        GameBoy::cpu.flagreg_c = 1;   
    }
    
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.pc+=2;
}

void op_3x0(){
    unsigned short upper = (GameBoy::cpu.cb.low & 0x00F0) >> 4;
    unsigned short lower = (GameBoy::cpu.cb.low & 0x000F);

    GameBoy::cpu.fa.low = (lower << 4) | upper;

    if(GameBoy::cpu.cb.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.flagreg_h = false;

    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.pc += (opcode & 0x000F);
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_3x1(){
    GameBoy::cpu.sp = (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_3x2(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.fa.low;
    GameBoy::cpu.lh.whole--;
    GameBoy::cpu.pc+=2;
}

void op_3x3(){
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc+=2;
}

void op_3x4(){
    GameBoy::cpu.lh.whole++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_3x5(){
    GameBoy::cpu.lh.whole--;
    if(GameBoy::cpu.lh.whole == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_3x6(){
    //GameBoy::cpu.ed.low = std::static_cast<short>(GameBoy::cpu.lh.whole);
    GameBoy::cpu.pc+=2;
}

void op_3x7(){
    GameBoy::cpu.flagreg_c = true;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.pc+=2;
}

void op_3x8(){
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.pc += (opcode & 0x000F);
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_3x9(){
    GameBoy::cpu.lh.whole += GameBoy::cpu.sp;
    GameBoy::GameBoy::cpu.flagreg_z = false;
    GameBoy::cpu.pc+=2;
}

void op_3xA(){
    GameBoy::cpu.fa.low = GameBoy::cpu.lh.whole;
    GameBoy::cpu.lh.whole--;
    GameBoy::cpu.pc+=2;
}

void op_3xB(){
    GameBoy::cpu.sp--;
    GameBoy::cpu.pc+=2;
}

void op_3xC(){
    GameBoy::cpu.fa.low++;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.flagreg_h = (opcode & 0b000000000100) >> 2;
    }
    GameBoy::cpu.pc+=2;
}

void op_3xD(){
    GameBoy::cpu.fa.low--;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_3xE(){
    GameBoy::cpu.fa.low = opcode & 0x000F;
    GameBoy::cpu.pc+=2;
}

void op_3xF(){
    if(GameBoy::cpu.flagreg_c){
        GameBoy::cpu.flagreg_c = false;
    }else{
        GameBoy::cpu.flagreg_c = true;
    }
    GameBoy::cpu.pc+=2;
}

void op_4x0(){
    GameBoy::cpu.cb.low = GameBoy::cpu.cb.low;
    if ((GameBoy::cpu.cb.high & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x1(){
    GameBoy::cpu.cb.low = GameBoy::cpu.cb.high;
    if ((GameBoy::cpu.cb.low & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x2(){
    GameBoy::cpu.cb.low = GameBoy::cpu.ed.low;
    if ((GameBoy::cpu.ed.low & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x3(){
    GameBoy::cpu.cb.low = GameBoy::cpu.ed.high;
    if ((GameBoy::cpu.ed.high & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x4(){
    GameBoy::cpu.cb.low = GameBoy::cpu.lh.high;
    if ((GameBoy::cpu.lh.low & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x5(){
    GameBoy::cpu.cb.low = GameBoy::cpu.lh.low;
    if ((GameBoy::cpu.lh.high & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x6(){
    GameBoy::cpu.cb.low = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_4x7(){
    if ((GameBoy::cpu.fa.high & 0x000F) == 0x0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.pc+=2;
}

void op_4x8(){
    GameBoy::cpu.cb.high = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_4x9(){
    GameBoy::cpu.cb.high = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_4xA(){
    GameBoy::cpu.cb.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_4xB(){
    GameBoy::cpu.cb.high = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_4xC(){
    GameBoy::cpu.cb.high = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_4xD(){
    GameBoy::cpu.cb.high = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_4xE(){
    GameBoy::cpu.cb.high = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_4xF(){
    GameBoy::cpu.cb.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_5x0(){
    GameBoy::cpu.ed.low = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_5x1(){
    GameBoy::cpu.ed.low = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_5x2(){
    GameBoy::cpu.ed.low = GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
}

void op_5x3(){
    GameBoy::cpu.ed.low = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_5x4(){
    GameBoy::cpu.ed.low = GameBoy::cpu.lh.low;
    GameBoy::cpu.pc+=2;
}

void op_5x5(){
    GameBoy::cpu.ed.low = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_5x6(){
    GameBoy::cpu.ed.low = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_5x7(){
    GameBoy::cpu.ed.low = GameBoy::cpu.fa.high;
    GameBoy::cpu.pc+=2;
}

void op_5x8(){
    GameBoy::cpu.ed.high = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_5x9(){
    GameBoy::cpu.ed.high = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_5xA(){
    GameBoy::cpu.ed.high = GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
}

void op_5xB(){
    GameBoy::cpu.ed.high = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_5xC(){
    GameBoy::cpu.ed.high = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_5xD(){
    GameBoy::cpu.ed.high = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_5xE(){
    GameBoy::cpu.ed.high = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_5xF(){
    GameBoy::cpu.ed.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_6x0(){
    GameBoy::cpu.lh.low = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_6x1(){
    GameBoy::cpu.lh.low = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_6x2(){
    GameBoy::cpu.lh.low = GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
}

void op_6x3(){
    GameBoy::cpu.lh.low = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_6x4(){
    GameBoy::cpu.lh.low = GameBoy::cpu.lh.low;
    GameBoy::cpu.pc+=2;
}

void op_6x5(){
    GameBoy::cpu.lh.low = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_6x6(){
    GameBoy::cpu.lh.low = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_6x7(){
    GameBoy::cpu.lh.low = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_6x8(){
    GameBoy::cpu.lh.high = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_6x9(){
    GameBoy::cpu.lh.high = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_6xA(){
    GameBoy::cpu.lh.high = GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
}

void op_6xB(){
    GameBoy::cpu.lh.high = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_6xC(){
    GameBoy::cpu.lh.high = GameBoy::cpu.lh.low;
    GameBoy::cpu.pc+=2;
}

void op_6xD(){
    GameBoy::cpu.lh.high = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_6xE(){
    GameBoy::cpu.lh.high = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_6xF(){
    GameBoy::cpu.lh.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7x0(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
}

void op_7x1(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
}

void op_7x2(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
}

void op_7x3(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
}

void op_7x4(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
}

void op_7x5(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.lh.low;
    GameBoy::cpu.pc+=2;
}

void op_7x6(){
    GameBoy::cpu.pc+=2;
}

void op_7x7(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7x8(){
    GameBoy::cpu.cb.low = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7x9(){
    GameBoy::cpu.cb.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7xA(){
    GameBoy::cpu.ed.low = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7xB(){
    GameBoy::cpu.ed.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7xC(){
    GameBoy::cpu.lh.low = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7xD(){
    GameBoy::cpu.lh.high = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_7xE(){
    GameBoy::cpu.fa.low = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_7xF(){
    GameBoy::cpu.fa.low = GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
}

void op_8x0(){
    GameBoy::cpu.fa.low += GameBoy::cpu.cb.low;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x1(){
    GameBoy::cpu.fa.low += GameBoy::cpu.cb.high;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x2(){
    GameBoy::cpu.fa.low += GameBoy::cpu.ed.low;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x3(){
    GameBoy::cpu.fa.low += GameBoy::cpu.ed.high;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x4(){
    GameBoy::cpu.fa.low += GameBoy::cpu.lh.low;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x5(){
    GameBoy::cpu.fa.low += GameBoy::cpu.lh.high;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x6(){
    GameBoy::cpu.fa.low += GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x7(){
    GameBoy::cpu.fa.low += GameBoy::cpu.fa.low;
    GameBoy::cpu.pc+=2;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
}

void op_8x8(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8x9(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.cb.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xA(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.ed.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xB(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xC(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.lh.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xD(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.lh.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xE(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.lh.whole;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_8xF(){
    GameBoy::cpu.fa.low += GameBoy::cpu.flagreg_c + GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = (opcode & 0b0000000000000100) >> 2;
    GameBoy::cpu.flagreg_c = (opcode & 0b0000000001000000) >> 6;
    GameBoy::cpu.pc+=2;
}

void op_9x0(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x1(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.cb.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x2(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.ed.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x3(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x4(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x5(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x6(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.whole;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.pc+=2;
}

void op_9x7(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.fa.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9x8(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.cb.low + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9x9(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.cb.high + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xA(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.ed.low + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xB(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.ed.high + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xC(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.low + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xD(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.high + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xE(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.lh.whole + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
}

void op_9xF(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.fa.low + GameBoy::cpu.flagreg_c;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 1;
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.flagreg_c = 1;
        GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    }
    GameBoy::cpu.pc+=2;
    
}

void op_Ax0(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax1(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.cb.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax2(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.ed.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax3(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax4(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.lh.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax5(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.lh.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax6(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.lh.whole;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax7(){
    GameBoy::cpu.fa.low &= GameBoy::cpu.fa.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 1;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Ax8(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_Ax9(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.cb.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxA(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.ed.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxB(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxC(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.lh.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxD(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.lh.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxE(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.lh.whole;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_AxF(){
    GameBoy::cpu.fa.low ^= GameBoy::cpu.fa.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = true;
    }
    GameBoy::cpu.flagreg_c = false;
    GameBoy::cpu.flagreg_h = false;
    GameBoy::cpu.flagreg_n = false;
    GameBoy::cpu.pc+=2;
}

void op_Bx0(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.cb.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx1(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.cb.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx2(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.ed.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx3(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx4(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.lh.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx5(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.lh.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx6(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.lh.whole;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx7(){
    GameBoy::cpu.fa.low |= GameBoy::cpu.fa.low;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    GameBoy::cpu.flagreg_n = 0;
    GameBoy::cpu.flagreg_h = 0;
    GameBoy::cpu.flagreg_c = 0;
    GameBoy::cpu.pc+=2;
}

void op_Bx8(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.cb.low){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_Bx9(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.cb.high){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxA(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.ed.low){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxB(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.ed.high){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxC(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.lh.low){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxD(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.lh.high){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxE(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.lh.whole){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_BxF(){
    if(GameBoy::cpu.fa.low == GameBoy::cpu.fa.low){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
        
    }else{
        GameBoy::GameBoy::cpu.flagreg_z = 0;
    }
    if(GameBoy::cpu.fa.low < GameBoy::cpu.fa.low){
        GameBoy::cpu.flagreg_c = 1;
    }
    GameBoy::cpu.flagreg_h = (opcode & 0x0004) >> 3;
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_Cx0(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 0){
        GameBoy::cpu.pc = GameBoy::memory.stack[GameBoy::cpu.sp];
        GameBoy::cpu.sp--;
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Cx1(){
    GameBoy::cpu.cb.whole = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp -=2;
}

void op_Cx2(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 0)
        GameBoy::cpu.pc = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_Cx3(){
    GameBoy::cpu.pc = (opcode & 0x00FF);
}

void op_Cx4(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 0){
        GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
        GameBoy::cpu.sp++;
    }
    else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Cx5(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.cb.whole;
    GameBoy::cpu.sp +=2;
}

void op_Cx6(){
    GameBoy::cpu.pc+=2;
}

void op_Cx7(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0000;
}

void op_Cx8(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 1){
        GameBoy::cpu.pc = GameBoy::memory.stack[GameBoy::cpu.sp];
        GameBoy::cpu.sp--;
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Cx9(){
    GameBoy::cpu.pc = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp--;
}

void op_CxA(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 1)
    GameBoy::cpu.pc = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_CxB(){
    GameBoy::cpu.pc+=2;
}

void op_CxC(){
    if(GameBoy::GameBoy::cpu.flagreg_z == 1){
        GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
        GameBoy::cpu.sp++;
    }
    else{
        GameBoy::cpu.pc+=2;
    }
}

void op_CxD(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = (opcode & 0x00FF);
}

void op_CxE(){
    GameBoy::cpu.pc+=2;
}

void op_CxF(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0008;
}

void op_Dx0(){
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.pc = GameBoy::memory.stack[GameBoy::cpu.sp];
        GameBoy::cpu.sp--;
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Dx1(){
    GameBoy::cpu.ed.whole = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp -= 2;
    GameBoy::cpu.pc+=2;
}

void op_Dx2(){
    if(GameBoy::cpu.flagreg_c == 0)
    GameBoy::cpu.pc = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_Dx3(){
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::cpu.sp += GameBoy::cpu.fa.low;    
    }
    GameBoy::cpu.pc+=2;
}

void op_Dx4(){
    if(GameBoy::cpu.flagreg_c == 0){
        GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
        GameBoy::cpu.sp++;
    }
    else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Dx5(){
    GameBoy::cpu.ed.whole = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp += 2;
    GameBoy::cpu.pc+=2;
}

void op_Dx6(){
    GameBoy::cpu.pc+=2;
}

void op_Dx7(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0010;
}

void op_Dx8(){
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::cpu.pc = GameBoy::memory.stack[GameBoy::cpu.sp];
        GameBoy::cpu.sp--;
    }else{
        GameBoy::cpu.pc+=2;
    }
}

void op_Dx9(){
    GameBoy::cpu.pc+=2; //TODO page 118
}

void op_DxA(){
    if(GameBoy::cpu.flagreg_c == 1)
    GameBoy::cpu.pc = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_DxB(){
    GameBoy::cpu.pc+=2;
}

void op_DxC(){
    if(GameBoy::cpu.flagreg_c == 1){
        GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
        GameBoy::cpu.sp++;
    }
    else{
        GameBoy::cpu.pc+=2;
    }
}

void op_DxD(){
    GameBoy::cpu.pc+=2;
}

void op_DxE(){
    GameBoy::cpu.fa.low -= GameBoy::cpu.ed.high;
    if(GameBoy::cpu.fa.low == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 0;   
    }
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_DxF(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0018;
}

void op_Ex0(){
    GameBoy::cpu.pc+=2;
}

void op_Ex1(){
    GameBoy::cpu.lh.whole = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp += 2;
    GameBoy::cpu.pc+=2;
}

void op_Ex2(){
    GameBoy::cpu.fa.low = GameBoy::cpu.cb.high; 
    GameBoy::cpu.pc+=2;
}

void op_Ex3(){
    GameBoy::cpu.pc+=2;
}

void op_Ex4(){
    GameBoy::cpu.pc+=2;
}

void op_Ex5(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.lh.whole;
    GameBoy::cpu.sp +=2;
}

void op_Ex6(){
    GameBoy::cpu.fa.low = GameBoy::cpu.fa.low & (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_Ex7(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0020;
}

void op_Ex8(){
    GameBoy::cpu.sp += (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_Ex9(){
    GameBoy::cpu.pc = GameBoy::cpu.lh.whole;
}

void op_ExA(){
    GameBoy::cpu.fa.low == (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_ExB(){
    
    GameBoy::cpu.pc+=2;
}

void op_ExC(){
    GameBoy::cpu.pc+=2;
}

void op_ExD(){
    GameBoy::cpu.pc+=2;
}

void op_ExE(){
    GameBoy::cpu.fa.low ^= (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_ExF(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0028;
}

void op_Fx0(){
    GameBoy::cpu.pc+=2;
}

void op_Fx1(){
    GameBoy::cpu.fa.whole = GameBoy::memory.stack[GameBoy::cpu.sp];
    GameBoy::cpu.sp -=2;
}

void op_Fx2(){
    GameBoy::cpu.pc+=2;
}

void op_Fx3(){
    interruptMode = false;
    GameBoy::cpu.pc+=2;
}

void op_Fx4(){
    
    GameBoy::cpu.pc+=2;
}

void op_Fx5(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.fa.whole;
    GameBoy::cpu.sp +=2;
    GameBoy::cpu.pc+=2;
}

void op_Fx6(){
    GameBoy::cpu.fa.low |= (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_Fx7(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0030;
}

void op_Fx8(){
    GameBoy::cpu.lh.whole = GameBoy::cpu.sp + (opcode & 0x000F);
    GameBoy::cpu.pc+=2;
}

void op_Fx9(){
    GameBoy::cpu.sp = GameBoy::cpu.lh.whole;
    GameBoy::cpu.pc+=2;
}

void op_FxA(){
    GameBoy::cpu.fa.low = (opcode & 0x00FF);
    GameBoy::cpu.pc+=2;
}

void op_FxB(){
    interruptMode = true;
    GameBoy::cpu.pc+=2;
}

void op_FxC(){
    GameBoy::cpu.pc+=2;
}

void op_FxD(){
    GameBoy::cpu.pc+=2;
}

void op_FxE(){
    auto result = GameBoy::cpu.fa.low - (opcode & 0x000F);
    if(result == 0){
        GameBoy::GameBoy::cpu.flagreg_z = 1;
    }
    
    GameBoy::cpu.flagreg_n = 1;
    GameBoy::cpu.pc+=2;
}

void op_FxF(){
    GameBoy::memory.stack[GameBoy::cpu.sp] = GameBoy::cpu.pc;
    GameBoy::cpu.sp++;
    GameBoy::cpu.pc = 0x0038;
}