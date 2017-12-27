#pragma once

#include <fstream>
#include <iostream>
#include <memory>
struct Register{
    union{
        struct{
            unsigned short high;
            unsigned short low;
        };
        unsigned short whole;
    };
};

struct Rom{
    char *name;
    char *data;

    void createFromFile(const char* fileName);
    void clean();
};
