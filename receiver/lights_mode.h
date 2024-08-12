#ifndef LIGHTS_H
#define LIGHTS_H

#include "./game_mode.h"

class Lights : public GameMode
{
private:
  int waitMs = 300;
  int currentLedNumber = 1;
  int timesBlinked = 0;
  int mode = 0;
  void identifyTick();
  void flushTick();
  void leftRightTick();
  void alternateTick();
public:
  String name = "Lights";
  Lights();
  void receive_1() override;
  void receive_2() override;
  void receive_3() override;
  void receive_4() override;
  void receive_5() override;
  void receive_6() override;
  void reset() override;
  void tick() override;
};

#endif