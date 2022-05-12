#include <kamek.h>
#include <racedata.h>
#include <raceinfo.h>
#include <menudata.h>
#include <settings.h>
#include <player.h>
#include <rknetcontroller.h>
#include <musichandler.h>
#include <common.h>
#include <item.h>
#include <base/c_stdlib.h>

// 0x807bb200 is the address for itemslot.bin loading

extern Racedata *racedata;
extern Raceinfo *raceinfo;
extern Settings settings;
extern Rknetcontroller *rknetcontroller;
extern PlayerHolder *player;
extern MusicHandler *musichandler;
extern "C"{
    u32 ARCConvertPathToEntryNum(UnkType *r3, char *tplPath);
}

u32 GetCustomRaceTPL(UnkType *r3, char *tplPath){
    if (settings.mode == BSS){
        if (strcmp(tplPath, "tt_item_kame_wing.tpl") == 0){
            tplPath = "tt_item_kame_wing_bss.tpl";
        }
    }
    else if (settings.mode == BBB){
        if (strcmp(tplPath, "tt_item_kame_green_3.tpl") == 0){
            tplPath = "tt_item_bomb_hei_3.tpl";
        }
        else if (strcmp(tplPath, "tt_item_killer.tpl") == 0){
            tplPath = "tt_item_killer_bomb.tpl";
        }
        else if (strcmp(tplPath, "tt_item_kinoko.tpl") == 0){
            tplPath = "tt_item_kinoko_bomb.tpl";
        }
    }
    return ARCConvertPathToEntryNum(r3, tplPath);
}

kmCall(0x80083e9c, &GetCustomRaceTPL);