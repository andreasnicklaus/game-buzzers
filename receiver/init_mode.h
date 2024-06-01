#ifndef INIT_H
#define INIT_H

#include "./game_mode.h"

class Init : public GameMode
{
public:
  String name = "Initialization";
  Init();
  Init(
    bool button_1_active,
    bool button_2_active,
    bool button_3_active,
    bool button_4_active,
    bool button_5_active,
    bool button_6_active
  );
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