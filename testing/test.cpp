#include <kamek.h>
#include <racedata.h>
#include <raceinfo.h>
#include <menudata.h>
#include <settings.h>
#include <player.h>
#include <rknetcontroller.h>
#include <musichandler.h>
#include <common.h>
#include <base/c_stdlib.h>
#include <item.h>

extern MenuData *menudata;
extern PlayerHolder *player;
extern PlayerModel *playermodel;
extern "C" void OSReport(const char * format, ...);

bool testFunction(bool hasItem, u32 *itemHolderPlayers){
    
    
    OSReport("PlayerModel: %d", playermodel->trickDirection);
    OSReport("PlayerModel: %d", playermodel->isHq);
    OSReport("PlayerModel: %d", playermodel->isNotFocusedInLiveView);
    OSReport("PlayerModel: %x", sizeof(PlayerModel));
    
    return hasItem;
}

kmBranch(0x807eeed0, &testFunction);