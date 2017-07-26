#ifndef UTILITIES__
#define UTILITIES__
#include <fstream>
#include <iostream>
#include <cstring>

struct Register{
    union{
        struct{
            unsigned short high[8];
            unsigned short low[8];
        };
        unsigned short whole[16];
    };
};

struct Rom{
    char *name;
    char *data;

    void createFromFile(const char* fileName);
    void clean();
};

#endif