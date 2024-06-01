#ifndef QUIZ_H
#define QUIZ_H

#include "./game_mode.h"

class Quiz : public GameMode
{
private:
  bool blinking = false;
  int blinkingButton = 0;
  int blinkCount = 0;
  void startBlink(int led);
public:
  String name = "Quiz";
  Quiz();
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