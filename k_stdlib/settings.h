#pragma once
#include <kamek.h>

enum VPGamemode{
    Normal = 0x0,
    BSS = 0x1,
    BBB = 0x2
};

struct Settings{
public:
    u8 mode;
    bool finalLapSpeedup;
    bool silentController;
    bool miiHeads;
};