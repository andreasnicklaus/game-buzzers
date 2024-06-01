#include "./init_mode.h"

int debounce = 500;

Init::Init() {
  this->reset();
};
Init::Init(
  bool button_1_active,
  bool button_2_active,
  bool button_3_active,
  bool button_4_active,
  bool button_5_active,
  bool button_6_active
) {
  this->reset();
  this->LED_1_STATE = button_1_active;
  this->LED_2_STATE = button_2_active;
  this->LED_3_STATE = button_3_active;
  this->LED_4_STATE = button_4_active;
  this->LED_5_STATE = button_5_active;
  this->LED_6_STATE = button_6_active;
};

void Init::receive_1() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_1_STATE == 0) {this->LED_1_STATE = 1;}
    else {this->LED_1_STATE = 0;}
  }
};
void Init::receive_2() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_2_STATE == 0) {this->LED_2_STATE = 1;}
    else {this->LED_2_STATE = 0;}
  }
};
void Init::receive_3() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_3_STATE == 0) {this->LED_3_STATE = 1;}
    else {this->LED_3_STATE = 0;}
  }
};
void Init::receive_4() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_4_STATE == 0) {this->LED_4_STATE = 1;}
    else {this->LED_4_STATE = 0;}
  }
};
void Init::receive_5() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_5_STATE == 0) {this->LED_5_STATE = 1;}
    else {this->LED_5_STATE = 0;}
  }
};
void Init::receive_6() {
  if (this->lastAction == 0 or millis() -  this->lastAction >= debounce) {
    if (this->LED_6_STATE == 0) {this->LED_6_STATE = 1;}
    else {this->LED_6_STATE = 0;}
  }
};
  
void Init::reset() {
  this->LED_1_STATE = 0;
  this->LED_2_STATE = 0;
  this->LED_3_STATE = 0;
  this->LED_4_STATE = 0;
  this->LED_5_STATE = 0;
  this->LED_6_STATE = 0;

  this->lastAction = 0;
}

void Init::tick() {}