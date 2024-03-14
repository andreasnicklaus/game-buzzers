#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

// Input pins
int RESET_INPUT_PIN = 8;
int MODE_INPUT_PIN = 9;

// button states
int resetButtonState = 0;
int modeButtonState = 0;

// Output pins
int LED_1_PIN = 2;
int LED_2_PIN = 3;
int LED_3_PIN = 4;
int LED_4_PIN = 5;
int LED_5_PIN = 6;
int LED_6_PIN = 7;
int MODE_LED_A_PIN = 10;
int MODE_LED_B_PIN = 13;

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init()) Serial.println("init failed");

    pinMode(RESET_INPUT_PIN, INPUT);
    pinMode(MODE_INPUT_PIN, INPUT);

    pinMode(LED_1_PIN, OUTPUT);
    pinMode(LED_2_PIN, OUTPUT);
    pinMode(LED_3_PIN, OUTPUT);
    pinMode(LED_4_PIN, OUTPUT);
    pinMode(LED_5_PIN, OUTPUT);
    pinMode(LED_6_PIN, OUTPUT);
    pinMode(MODE_LED_A_PIN, OUTPUT);
    pinMode(MODE_LED_B_PIN, OUTPUT);

    if (driver.init()) Serial.println("setup successful");
}

void printReceivedMessage(uint8_t buf[12])
{
  Serial.print("Message: ");
  Serial.println((char*)buf);
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      printReceivedMessage(buf);

      // TODO: implement game logic based on selected game mode
    }
}