#include <kamek.h>
#include <racedata.h>
#include <raceinfo.h>
#include <menudata.h>
#include <settings.h>
#include <player.h>
#include <rknetcontroller.h>
#include <musichandler.h>
#include <common.h>

extern Racedata *racedata;
extern Raceinfo *raceinfo;
extern Settings settings;
extern Rknetcontroller *rknetcontroller;
extern PlayerHolder *player;
extern MusicHandler *musichandler;
extern "C"{
    void SetMatIcon(UnkType *r3, char *materialName, char *iconPaneName);
}

asm void SetBlueShellLimit(){
    lis r12, settings.mode@ha
    lbz r12, settings.mode@l(r12)
    cmpwi r12, BSS
    bne skip
    li r0, 0x20
    stw	r0, 0x4(r3)

    skip:
    addi r3, r31, 0x2b8
}

kmCall(0x80790b7c, &SetBlueShellLimit);