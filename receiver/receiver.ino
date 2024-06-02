#include <RH_ASK.h>
// #include <SPI.h> // Not actualy used but needed to compile

#include "./game_mode.h"
#include "./init_mode.h"
#include "./lights_mode.h"
#include "./monkey.h"
#include "./quiz.h"

RH_ASK driver;

// Input pins
int RESET_INPUT_PIN = 8;
int MODE_INPUT_PIN = 9;

// button states
int resetButtonState = HIGH;
int modeButtonState = HIGH;

unsigned long last_mode_change = 0;

// Output pins
int LED_1_PIN = 5;
int LED_2_PIN = 7;
int LED_3_PIN = 6;
int LED_4_PIN = 2;
int LED_5_PIN = 4;
int LED_6_PIN = 3;
int MODE_LED_A_PIN = 10;
int MODE_LED_B_PIN = 13;

bool button_1_active = false;
bool button_2_active = false;
bool button_3_active = false;
bool button_4_active = false;
bool button_5_active = false;
bool button_6_active = false;

int mode = 1;
GameMode* gameMode = new Init();

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init()) Serial.println("init failed");

    pinMode(RESET_INPUT_PIN, INPUT_PULLUP);
    pinMode(MODE_INPUT_PIN, INPUT_PULLUP);

    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
    pinMode(LED_3_PIN, OUTPUT);
    pinMode(LED_4_PIN, OUTPUT);
    pinMode(LED_5_PIN, OUTPUT);
    pinMode(LED_6_PIN, OUTPUT);
    pinMode(MODE_LED_A_PIN, OUTPUT);
    pinMode(MODE_LED_B_PIN, OUTPUT);

    if (driver.init()) Serial.println("setup successful");

    test_blink_all();
    set_mode(0);

    Serial.println("setup finished");
}

void printReceivedMessage(uint8_t buf[12])
{
  Serial.print("Message: ");
  Serial.println((char*)buf);
}

void test_blink_all() {
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, HIGH);
  digitalWrite(LED_3_PIN, HIGH);
  digitalWrite(LED_4_PIN, HIGH);
  digitalWrite(LED_5_PIN, HIGH);
  digitalWrite(LED_6_PIN, HIGH);
  digitalWrite(MODE_LED_A_PIN, HIGH);
  digitalWrite(MODE_LED_B_PIN, HIGH);
  delay(200);
  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_4_PIN, LOW);
  digitalWrite(LED_5_PIN, LOW);
  digitalWrite(LED_6_PIN, LOW);
  digitalWrite(MODE_LED_A_PIN, LOW);
  digitalWrite(MODE_LED_B_PIN, LOW);
}

void next_mode() {
  if (mode == 0) set_mode(1);
  else if (mode == 1) set_mode(2);
  else if (mode == 2) set_mode(3);
  else if (mode == 3) set_mode(0);
  // else set_mode(mode + 1);
}

void set_mode(int new_mode) {
  if (millis() - last_mode_change < 200) return;

  Serial.println("Switching to mode " + String(new_mode));
  mode = new_mode;

  if (mode == 0) {
    Serial.println("Setting mode to: TEST");
    gameMode = new Init(button_1_active, button_2_active, button_3_active, button_4_active, button_5_active, button_6_active);
  } else if (mode == 1) {

    button_1_active = false;
    button_2_active = false;
    button_3_active = false;
    button_4_active = false;
    button_5_active = false;
    button_6_active = false;

    if (digitalRead(LED_1_PIN) == 1) button_1_active = true;
    if (digitalRead(LED_2_PIN) == 1) button_2_active = true;
    if (digitalRead(LED_3_PIN) == 1) button_3_active = true;
    if (digitalRead(LED_4_PIN) == 1) button_4_active = true;
    if (digitalRead(LED_5_PIN) == 1) button_5_active = true;
    if (digitalRead(LED_6_PIN) == 1) button_6_active = true;

    Serial.println("Setting mode to: MONKEY");
    gameMode = new Monkey(button_1_active, button_2_active, button_3_active, button_4_active, button_5_active, button_6_active);
  } else if (mode == 2) {
    Serial.println("Setting mode to: QUIZ");
    gameMode = new Quiz();
  } else if (mode == 3) {
    Serial.println("Setting mode to: LIGHTS");
    gameMode = new Lights();
  }

  last_mode_change = millis();
}

void loop()
{
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen))
    {
      printReceivedMessage(buf);

      if (strcmp ((char*) buf, (char*) "1") == 0) {
        button_1_active = true;
        gameMode->receive_1();
      }

      if (strcmp ((char*) buf, (char*) "2") == 0) {
        button_2_active = true;
        gameMode->receive_2();
      }

      if (strcmp ((char*) buf, (char*) "3") == 0) {
        button_3_active = true;
        gameMode->receive_3();
      }

      if (strcmp ((char*) buf, (char*) "4") == 0) {
        button_4_active = true;
        gameMode->receive_4();
      }

      if (strcmp ((char*) buf, (char*) "5") == 0) {
        button_5_active = true;
        gameMode->receive_5();
      }

      if (strcmp ((char*) buf, (char*) "6") == 0) {
        button_6_active = true;
        gameMode->receive_6();
      }

    }

    digitalWrite(LED_1_PIN, gameMode->LED_1_STATE);
    digitalWrite(LED_2_PIN, gameMode->LED_2_STATE);
    digitalWrite(LED_3_PIN, gameMode->LED_3_STATE);
    digitalWrite(LED_4_PIN, gameMode->LED_4_STATE);
    digitalWrite(LED_5_PIN, gameMode->LED_5_STATE);
    digitalWrite(LED_6_PIN, gameMode->LED_6_STATE);

    if (mode == 0) {
      digitalWrite(MODE_LED_A_PIN, LOW);
      digitalWrite(MODE_LED_B_PIN, LOW);
    } else if (mode == 1) {
      digitalWrite(MODE_LED_A_PIN, LOW);
      digitalWrite(MODE_LED_B_PIN, HIGH);
    } else if (mode == 2) {
      digitalWrite(MODE_LED_A_PIN, HIGH);
      digitalWrite(MODE_LED_B_PIN, LOW);
    } else if (mode == 3) {
      digitalWrite(MODE_LED_A_PIN, HIGH);
      digitalWrite(MODE_LED_B_PIN, HIGH);
    }

    // Serial.println(
    //   String(digitalRead(LED_1_PIN)) + String(digitalRead(LED_2_PIN)) + String(digitalRead(LED_3_PIN)) + String(digitalRead(LED_4_PIN)) + String(digitalRead(LED_5_PIN)) + String(digitalRead(LED_6_PIN)) + " - " + String(digitalRead(MODE_LED_A_PIN)) + String(digitalRead(MODE_LED_B_PIN)) + " - " +
    //   gameMode->state + " - " +
    //   gameMode->lastModeChange +  " - " + 
    //   String(millis() - gameMode->lastModeChange) + " - " +
    //   gameMode->lastAction +  " - " +
    //   String(millis() - gameMode->lastAction)
    // );
    gameMode->tick();

    int new_mode_buttonstate = digitalRead(MODE_INPUT_PIN);
    if (new_mode_buttonstate == LOW && modeButtonState == HIGH) next_mode();

    int new_reset_buttonstate = digitalRead(RESET_INPUT_PIN);
    if (new_reset_buttonstate == LOW && resetButtonState == HIGH) {
      test_blink_all();
      // setup();
      gameMode->reset();
    }

    resetButtonState = new_reset_buttonstate;
    modeButtonState = new_mode_buttonstate;
}