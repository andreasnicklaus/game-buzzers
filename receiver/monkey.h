#ifndef MONKEY_H
#define MONKEY_H

#include "./game_mode.h"

class Monkey : public GameMode
{
private:
  int lastChangedButton;
  bool button_1_active = false;
  bool button_2_active = false;
  bool button_3_active = false;
  bool button_4_active = false;
  bool button_5_active = false;
  bool button_6_active = false;
public:
  String name = "Monkey";
  Monkey();
  Monkey(
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