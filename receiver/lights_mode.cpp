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
  this->mode = 0;
}

void Lights::tick() {
  if (this->mode == 0) this->identifyTick();
  if (this->mode == 1) this->flushTick();
  if (this->mode == 2) this->leftRightTick();
  if (this->mode == 3) this->alternateTick();
}

void Lights::identifyTick() {
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
          this->mode = 1;
        }
        else {
          this->timesBlinked += 1;
        }
      }
    }

  }
}

void Lights::flushTick() {
  if (this->lastAction == 0 or (millis() - this->lastAction) > this->waitMs) {
    this->lastAction = millis();
    
    if (timesBlinked % 3 == 0) {
      this->LED_1_STATE = 1;
      this->LED_2_STATE = 1;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;
    } else if (timesBlinked % 3 == 1) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 1;
      this->LED_4_STATE = 1;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;
    } else {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 1;
      this->LED_6_STATE = 1;
    }

    this->timesBlinked += 1;

    if (this->timesBlinked >= 12) {
      this->currentLedNumber = 1;
      this->timesBlinked = 0;
      this->mode = 2;
    }
  }
}

void Lights::leftRightTick() {
  if (this->lastAction == 0 or (millis() - this->lastAction) > this->waitMs) {
    this->lastAction = millis();
    
    if (timesBlinked % 2 == 0) {
      this->LED_1_STATE = 1;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 1;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 1;
      this->LED_6_STATE = 0;
    } else {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 1;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 1;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 1;
    }

    this->timesBlinked += 1;

    if (this->timesBlinked >= 8) {
      this->currentLedNumber = 1;
      this->timesBlinked = 0;
      this->mode = 3;
    }
  }
};

void Lights::alternateTick() {
  if (this->lastAction == 0 or (millis() - this->lastAction) > (this->waitMs / 2)) {
    this->lastAction = millis();
    
    this->LED_1_STATE = 0;
    this->LED_2_STATE = 0;
    this->LED_3_STATE = 0;
    this->LED_4_STATE = 0;
    this->LED_5_STATE = 0;
    this->LED_6_STATE = 0;

    if (this->currentLedNumber == 1) {
      this->LED_1_STATE = 1;
      this->currentLedNumber = 3;
    } else if (this->currentLedNumber == 3) {
      this->LED_3_STATE = 1;
      this->currentLedNumber = 5;
    } else if (this->currentLedNumber == 5) {
      this->LED_5_STATE = 1;
      this->currentLedNumber = 6;
    } else if (this->currentLedNumber == 6) {
      this->LED_6_STATE = 1;
      this->currentLedNumber = 4;
    } else if (this->currentLedNumber == 4) {
      this->LED_4_STATE = 1;
      this->currentLedNumber = 2;
    } else {
      this->LED_2_STATE = 1;
      this->currentLedNumber = 1;
    }

    if (this->timesBlinked >= 24) {
      this->LED_1_STATE = 0;
      this->LED_2_STATE = 0;
      this->LED_3_STATE = 0;
      this->LED_4_STATE = 0;
      this->LED_5_STATE = 0;
      this->LED_6_STATE = 0;

      this->currentLedNumber = 1;
      this->timesBlinked = 0;
      this->mode = 0;
    } else {
      this->timesBlinked += 1;
    }
  }
};