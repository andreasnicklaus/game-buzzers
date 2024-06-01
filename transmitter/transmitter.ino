#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

//! change for every button
const char *rf_msg = "2";

const boolean debugging = true;

int BUTTON_PIN = 10;

# define VCC2 3
# define GND2 2

void setup()
{
    if (debugging) Serial.begin(9600);

    pinMode(VCC2, OUTPUT);
    digitalWrite(VCC2, HIGH);
    pinMode(GND2, OUTPUT);
    digitalWrite(GND2, LOW);

    pinMode(BUTTON_PIN, INPUT);

    // delay(200);
    if (driver.init()) Serial.println("init successful");
    else Serial.println("init failed");
}

void sendDataPackage() {
  Serial.println("Sending: " + String(rf_msg));
  driver.send((uint8_t *)rf_msg, strlen(rf_msg));
  driver.waitPacketSent();
}

void loop()
{    
    int buttonState = digitalRead(BUTTON_PIN);

    // button is pressed
    if (buttonState == LOW) {
      // Serial.println("button is pressed");
      sendDataPackage();
    }
}