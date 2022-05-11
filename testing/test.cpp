#include <kamek.h>
#include <menudata.h>
#include <player.h>

extern MenuData *menudata;
extern PlayerHolder *player;
extern "C" void osreport(const char * format, ...);

bool testFunction(bool hasItem, u32 *itemHolderPlayers){
    
    osreport("PlayerSub10BikeRealLocal: %x", sizeof(PlayerSub10BikeRealLocal));
    osreport("PlayerSub10BikeRemote: %x", sizeof(PlayerSub10BikeRemote));
    osreport("PlayerSub10Bike: %x", sizeof(PlayerSub10Bike));
    osreport("PlayerSub10RealLocal: %x", sizeof(PlayerSub10RealLocal));
    osreport("PlayerSub10Remote: %x", sizeof(PlayerSub10Remote));
    osreport("PlayerSub10: %x", sizeof(PlayerSub10));
    osreport("PlayerZipper: %x", sizeof(PlayerZipper));
    osreport("PlayerTrickBike: %x", sizeof(PlayerTrickBike));
    osreport("PlayerTrick: %x", sizeof(PlayerTrick));
    osreport("PlayerBoost: %x", sizeof(PlayerBoost));
    
    return hasItem;
}

kmBranch(0x807eeed0, &testFunction);