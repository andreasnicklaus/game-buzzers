#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <Arduino.h>

class GameMode
{
public:
  String name;
  int LED_1_STATE = 0;
  int LED_2_STATE = 0;
  int LED_3_STATE = 0;
  int LED_4_STATE = 0;
  int LED_5_STATE = 0;
  int LED_6_STATE = 0;
  int state = 0;
  unsigned long lastAction = 0;
  unsigned long lastModeChange = 0;
  virtual void receive_1() = 0;
  virtual void receive_2() = 0;
  virtual void receive_3() = 0;
  virtual void receive_4() = 0;
  virtual void receive_5() = 0;
  virtual void receive_6() = 0;
  virtual void reset() = 0;
  virtual void tick() = 0;
};

#endif