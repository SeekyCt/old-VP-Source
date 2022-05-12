/*
InputData is the class that handles all controller inputs
Contributors:
  Seeky (main documentation)
  SwareJonge
  _tZ
*/

#pragma once
#include <common.h>
#include <kamek.h>

class InputState {
public:
  virtual void unknown_vtable();
  // vtable 808b2f2c
  u16 buttonActions; // bit flags:
    /* 
      0x1 = accelerate
      0x2 = brake + reverse (used for SSMT)
      0x4 = use item
      0x8 = hop + drift
      0x20 = rear-view camera
    */
  u16 buttonRaw; // bit flags, vary slightly by controller
    /*
    gcn:
      0x1 - d-pad left
      0x2 - d-pad right
      0x4 - d-pad down
      0x8 - d-pad up
      0x10 - Bumper (C / Z)
      0x20 - Right Trigger
      0x40 - Left Trigger
      0x100 - A
      0x200 - B
      0x400 - X
      0x800 - Y
      0x1000 - Start
    */
  float stickX; // -1.0 to 1.0
  float stickY; // -1.0 to 1.0
  u8 quantisedStickX; // 0-14
  u8 quantisedStickY; // 0-14
  u8 motionControlFlick; // 1 up, 2 down, 3 left, 4 right; includes the first frame of d-pad presses
  u8 motionControlFlick2; // not sure what the difference is from the other one
  u8 unknown_0x14[0x18-0x14];
}; // Total size 0x18

class ControllerHolder {
public:
  ControllerHolder(); // 80520f64 - inlined in RealControllerHolder()
  virtual ~ControllerHolder(); // 805222b4
  virtual int unknown1(); // 80521198
  virtual int unknown2(); // 80521110
  virtual int unknown3();// 805226f4
  virtual int unknown4();// 8051ce84
  virtual int  unknown5();// 8051ce8c
  virtual int  unknown6();// 80520ebc
  // vtable 808b2dd8
  u8 unknown_0x4[0x28-0x4];
  InputState inputStates[2]; // 0 is current frame, 1 is previous
  u8 unknown_0x58[0xd8-0x58];
}; // Total size 0xd8

class RealControllerHolder : ControllerHolder {
public:
  RealControllerHolder(); // 805220bc
  virtual ~RealControllerHolder(); // 805222f4
  virtual int  unknown1(); // 80521768
  virtual int unknown2(); // 80522708
  virtual int unknown4(); // 80522700
  virtual int unknown5(); // 805226f8
  virtual int unknown6(); // 80520ebc
  
  // vtable 808b2d90
  void * rkgInputBuffer; // 0x2774 byte buffer for storing a controller input section of an RKG file
  u8 unknown_0xdc[0xe8-0xdc];
  void * unknown_0xe8; // 0x1c class with constructor 80524ac4
}; // Total size 0xec

class VirtualControllerHolder : ControllerHolder {
  virtual ~VirtualControllerHolder(); // 8052279c
  virtual int unknown3(); // 805219ac
  
  // vtable 808b2db4
  u8 unknown_0xd8[0x180-0xd8];
}; // Total size 0x180

class InputData {
  static InputData * sInstance; // 809bd70c
  static InputData * getStaticInstance(); // 8052313c
  static void destroyStaticInstance(); // 8052318c
  InputData(); // 805232f0
  virtual ~InputData(); // 805231dc
  // vtable 808b2fc8
  RealControllerHolder realControllerHolders[4]; // Stores inputs from a real controller at the same console
  VirtualControllerHolder virtualControllerHolders[12]; // Stores inputs for all the other players in a race (I think the ones with a matching realControllerHolder go unused)
  u8 unknown_0x15b4[0x415c-0x15b4];
}; // Total size 0x415c