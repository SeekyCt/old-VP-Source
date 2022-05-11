#pragma once

enum VPGamemode{
    Normal = 0x0,
    BSS = 0x1,
    BBB = 0x2
};

enum VPSOM{
    TopLeft = 0x0,
    TopRight = 0x1,
    BottomLeft = 0x2,
    BottomRight = 0x3
};

struct Settings{
public:
    u8 mode;
    u8 som;
    bool finalLapSpeedup;
    bool silentController;
    bool miiHeads;
};