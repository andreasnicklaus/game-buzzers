#include "./monkey.h"

// STATE INDICATOR
// this->state
// 
// 0: buttons are open
// 1: buttons are closed, the last pressed button blinks

Monkey::Monkey() {
  this->reset();
};
Monkey::Monkey(
    bool button_1_active = false,
    bool button_2_active = false,
    bool button_3_active = false,
    bool button_4_active = false,
    bool button_5_active = false,
    bool button_6_active = false
  ) {
  this->reset();
  if (
    (not button_1_active) and
    (not button_2_active) and
    (not button_3_active) and
    (not button_4_active) and
    (not button_5_active) and
    (not button_6_active)
  ) {
    this->button_1_active = true;
    this->button_2_active = true;
    this->button_3_active = true;
    this->button_4_active = true;
    this->button_5_active = true;
    this->button_6_active = true;
  } else {
    this->button_1_active = button_1_active;
    this->button_2_active = button_2_active;
    this->button_3_active = button_3_active;
    this->button_4_active = button_4_active;
    this->button_5_active = button_5_active;
    this->button_6_active = button_6_active;
  }
};

void Monkey::receive_1() {
  this->button_1_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 1;
    this->LED_1_STATE = 1;
  }
};
void Monkey::receive_2() {
  this->button_2_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 2;
    this->LED_2_STATE = 1;
  }
};
void Monkey::receive_3() {
  this->button_3_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 3;
    this->LED_3_STATE = 1;
  }
};
void Monkey::receive_4() {
  this->button_4_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 4;
    this->LED_4_STATE = 1;
  }
};
void Monkey::receive_5() {
  this->button_5_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 5;
    this->LED_5_STATE = 1;
  }
};
void Monkey::receive_6() {
  this->button_6_active = true;
  if (this->state == 0) {
    this->lastChangedButton = 6;
    this->LED_6_STATE = 1;
  }
};
  
void Monkey::reset() {
  this->LED_1_STATE = 0;
  this->LED_2_STATE = 0;
  this->LED_3_STATE = 0;
  this->LED_4_STATE = 0;
  this->LED_5_STATE = 0;
  this->LED_6_STATE = 0;

  this->state = 0;
  this->lastChangedButton = 0;
  this->lastModeChange = 0;
  this->lastAction = 0;
};

void Monkey::tick() {
  if (this->state == 0) {
    if (
      (this->LED_1_STATE == 1 or (not this->button_1_active)) and
      (this->LED_2_STATE == 1 or (not this->button_2_active)) and
      (this->LED_3_STATE == 1 or (not this->button_3_active)) and
      (this->LED_4_STATE == 1 or (not this->button_4_active)) and
      (this->LED_5_STATE == 1 or (not this->button_5_active)) and
      (this->LED_6_STATE == 1 or (not this->button_6_active))
    ) this->state = 1;
  }

  else if (this->state == 1) {
    if (this->lastModeChange == 0) {
      this->lastModeChange = millis();
    } else if ((millis() - this->lastModeChange) > 3000) {
      this->reset();
    }

    if (this->lastAction == 0 or ((millis() - this->lastAction) > 200)) {
      if (this->lastChangedButton == 1) {
        if (this->LED_1_STATE == 0) this->LED_1_STATE = 1;
        else this->LED_1_STATE = 0;
      } 
      if (this->lastChangedButton == 2) {
        if (this->LED_2_STATE == 0) this->LED_2_STATE = 1;
        else this->LED_2_STATE = 0;
      } 
      if (this->lastChangedButton == 3) {
        if (this->LED_3_STATE == 0) this->LED_3_STATE = 1;
        else this->LED_3_STATE = 0;
      } 
      if (this->lastChangedButton == 4) {
        if (this->LED_4_STATE == 0) this->LED_4_STATE = 1;
        else this->LED_4_STATE = 0;
      } 
      if (this->lastChangedButton == 5) {
        if (this->LED_5_STATE == 0) this->LED_5_STATE = 1;
        else this->LED_5_STATE = 0;
      } 
      if (this->lastChangedButton == 6) {
        if (this->LED_6_STATE == 0) this->LED_6_STATE = 1;
        else this->LED_6_STATE = 0;
      }

      this->lastAction = millis();
    }

    
  }
};