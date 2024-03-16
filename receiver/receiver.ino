#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

// Input pins
int RESET_INPUT_PIN = 8;
int MODE_INPUT_PIN = 9;

// button states
int resetButtonState = LOW;
int modeButtonState = LOW;

// Output pins
int LED_1_PIN = 2;
int LED_2_PIN = 3;
int LED_3_PIN = 4;
int LED_4_PIN = 5;
int LED_5_PIN = 6;
int LED_6_PIN = 7;
int MODE_LED_A_PIN = 10;
int MODE_LED_B_PIN = 13;

int mode = 1;

void setup()
{
    Serial.begin(9600);	// Debugging only
    // if (!driver.init()) Serial.println("init failed");

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

    // if (driver.init()) Serial.println("setup successful");
    Serial.println("setup successful");

    test_blink_all();
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
  Serial.println("Switching to mode " + String(new_mode));
  mode = new_mode;

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

}

void loop()
{
    // uint8_t buf[12];
    // uint8_t buflen = sizeof(buf);
    // if (driver.recv(buf, &buflen)) // Non-blocking
    // {
    //   printReceivedMessage(buf);

    //   // TODO: implement game logic based on selected game mode
    // }

    int new_mode_buttonstate = digitalRead(MODE_INPUT_PIN);
    if (new_mode_buttonstate == LOW && modeButtonState == HIGH) next_mode();

    int new_reset_buttonstate = digitalRead(RESET_INPUT_PIN);
    if (new_reset_buttonstate == LOW && resetButtonState == HIGH) setup();

    resetButtonState = new_reset_buttonstate;
    modeButtonState = new_mode_buttonstate;
}