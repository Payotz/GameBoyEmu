#include "utilities.h"

void Rom::createFromFile(const char* fileName){
    name = new char[16];
    std::streampos size;
    std::ifstream input(fileName, std::ios::in|std::ios::binary|std::ios::ate);
    if(input.is_open()){
        size = input.tellg();
        data = new char[size];
        input.seekg(0,std::ios::beg);
        input.read(data,size);
    }
    input.close();

    for (int i = 134; i < 142; i++){
        name[i-134] = data[i]; 
    }
}

void Rom::clean(){
    delete[] data;
    delete[] name;
}