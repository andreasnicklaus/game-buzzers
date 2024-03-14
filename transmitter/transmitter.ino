#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//! change for every button
int BUTTON_NUMBER = 1;
const char *msg = "1";

int BUTTON_PIN = 10;
int RESET_PIN = 9;

int LED_PIN = 2;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init()) Serial.println("init failed");

    pinMode(BUTTON_PIN, INPUT);
    pinMode(RESET_PIN, INPUT);

    pinMode(LED_PIN, OUTPUT);

    if (driver.init()) Serial.println("init successful");
}

void loop()
{
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);

    // TODO: implement transmission logic for failure and reset timer
}