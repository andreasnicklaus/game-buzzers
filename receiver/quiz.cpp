#include "./quiz.h"

int blink_times = 8;
int blink_delay = 250;

Quiz::Quiz() {
  this->reset();
};

void Quiz::receive_1() {
  this->startBlink(1);
};
void Quiz::receive_2() {
  this->startBlink(2);
};
void Quiz::receive_3() {
  this->startBlink(3);
};
void Quiz::receive_4() {
  this->startBlink(4);
};
void Quiz::receive_5() {
  this->startBlink(5);
};
void Quiz::receive_6() {
  this->startBlink(6);
};

void Quiz::startBlink(int led) {
  if (this->blinking == false) {
    this->blinking = true;
    this->blinkingButton = led;
  }
}
  
void Quiz::reset() {
  this->LED_1_STATE = 0;
  this->LED_2_STATE = 0;
  this->LED_3_STATE = 0;
  this->LED_4_STATE = 0;
  this->LED_5_STATE = 0;
  this->LED_6_STATE = 0;

  this->blinking = false;
  this->blinkingButton = 0;
  this->blinkCount = 0;
}

void Quiz::tick() {
  if (this->blinking and (this->lastAction == 0 or (millis() - this->lastAction) >= blink_delay)) {
    this->lastAction = millis();
    
    if (this->blinkingButton == 1) {
      if (this->LED_1_STATE == 0) {
        this->LED_1_STATE = 1;
      } else {
        this->LED_1_STATE = 0;
        this->blinkCount += 1;
      }
    }
    
    else if (this->blinkingButton == 2) {
      if (this->LED_2_STATE == 0) {
        this->LED_2_STATE = 1;
      } else {
        this->LED_2_STATE = 0;
        this->blinkCount += 1;
      }
    }
    
    else if (this->blinkingButton == 3) {
      if (this->LED_3_STATE == 0) {
        this->LED_3_STATE = 1;
      } else {
        this->LED_3_STATE = 0;
        this->blinkCount += 1;
      }
    }
    
    else if (this->blinkingButton == 4) {
      if (this->LED_4_STATE == 0) {
        this->LED_4_STATE = 1;
      } else {
        this->LED_4_STATE = 0;
        this->blinkCount += 1;
      }
    }
    
    else if (this->blinkingButton == 5) {
      if (this->LED_5_STATE == 0) {
        this->LED_5_STATE = 1;
      } else {
        this->LED_5_STATE = 0;
        this->blinkCount += 1;
      }
    }
    
    else if (this->blinkingButton == 6) {
      if (this->LED_6_STATE == 0) {
        this->LED_6_STATE = 1;
      } else {
        this->LED_6_STATE = 0;
        this->blinkCount += 1;
      }
    }

    if (this->blinkCount >= blink_times) {
      this->reset();
    }
  }
}