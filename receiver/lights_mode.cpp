#include "./lights_mode.h"

Lights::Lights() {
  
  this->reset();
};

void Lights::receive_1() {};
void Lights::receive_2() {};
void Lights::receive_3() {};
void Lights::receive_4() {};
void Lights::receive_5() {};
void Lights::receive_6() {};
  
void Lights::reset() {
  this->LED_1_STATE = 0;
  this->LED_2_STATE = 0;
  this->LED_3_STATE = 0;
  this->LED_4_STATE = 0;
  this->LED_5_STATE = 0;
  this->LED_6_STATE = 0;

  this->currentLedNumber = 1;
  this->timesBlinked = 0;
  this->lastAction = 0;
}

void Lights::tick() {
  if (this->lastAction == 0 or (millis() - this->lastAction) > this->waitMs) {
    this->lastAction = millis();

    if (this->currentLedNumber == 1) {
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;

      if (this->LED_1_STATE == 0) {
        this->LED_1_STATE = 1;
      }
      else {
        this->LED_1_STATE = 0;
        if (this->timesBlinked >= 0) {
          this->currentLedNumber = 2;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

    else if (this->currentLedNumber == 2) {
      this->LED_1_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;

      if (this->LED_2_STATE == 0) {
        this->LED_2_STATE = 1;
      }
      else {
        this->LED_2_STATE = 0;
        if (this->timesBlinked >= 1) {
          this->currentLedNumber = 3;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

    else if (this->currentLedNumber == 3) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;

      if (this->LED_3_STATE == 0) {
        this->LED_3_STATE = 1;
      }
      else {
        this->LED_3_STATE = 0;
        if (this->timesBlinked >= 2) {
          this->currentLedNumber = 4;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

    else if (this->currentLedNumber == 4) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;

      if (this->LED_4_STATE == 0) {
        this->LED_4_STATE = 1;
      }
      else {
        this->LED_4_STATE = 0;
        if (this->timesBlinked >= 3) {
          this->currentLedNumber = 5;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

    else if (this->currentLedNumber == 5) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_6_STATE = 0;

      if (this->LED_5_STATE == 0) {
        this->LED_5_STATE = 1;
      }
      else {
        this->LED_5_STATE = 0;
        if (this->timesBlinked >= 4) {
          this->currentLedNumber = 6;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

    else if (this->currentLedNumber == 6) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;

      if (this->LED_6_STATE == 0) {
        this->LED_6_STATE = 1;
      }
      else {
        this->LED_6_STATE = 0;
        if (this->timesBlinked >= 5) {
          this->currentLedNumber = 1;
          this->timesBlinked = 0;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

  }

}