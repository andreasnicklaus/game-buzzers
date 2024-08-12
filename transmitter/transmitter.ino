#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 8); // RX, TX
DFPlayerMini_Fast myMP3;

unsigned long soundtrack_last_played = 0;
int pause_between_soundtracks_ms = 1000;
const uint8_t volume = 30;

/*
* SOUNDTRACKS
0: Dog barking
1: Schlag den Star
2: Eureka, Ryan
3: It's so fluffy!
4: Wilhelm Scream
5: I'm Batman
6: Bazinga!
7: Voldemort Laugh
8: Avada Kedavra
9: I know!
10: Annabiotics
11: Who-Pa!
*/
const uint16_t soundtrack_number = 1;

RH_ASK driver;
//! change for every button
const char *rf_msg = "6";

int BUTTON_PIN = 10;
# define VCC2 3
# define GND2 2

void setup()
{
    Serial.begin(9600);

    pinMode(VCC2, OUTPUT);
    digitalWrite(VCC2, HIGH);
    pinMode(GND2, OUTPUT);
    digitalWrite(GND2, LOW);

    pinMode(BUTTON_PIN, INPUT);

    mySerial.begin(9600);
    myMP3.begin(mySerial, true);

    delay(1000);

    Serial.println("Setting volume to " + String(volume) + " out of 30");
    myMP3.volume(volume);
  
    Serial.println("Selected track is " + String(soundtrack_number + 1));
    // myMP3.play(soundtrack_number + 1);

    if (driver.init()) Serial.println("init successful");
    else Serial.println("init failed");
}

void sendDataPackage() {
  Serial.println("Sending: " + String(rf_msg));
  driver.send((uint8_t *)rf_msg, strlen(rf_msg));
  driver.waitPacketSent();
}

bool volumeSet = false;

void loop()
{    
    int buttonState = digitalRead(BUTTON_PIN);

    // button is pressed
    if (buttonState == LOW) {
      Serial.println("button is pressed");
      sendDataPackage();
      if (soundtrack_last_played == 0 or (millis() - soundtrack_last_played > pause_between_soundtracks_ms)) {
        myMP3.play(soundtrack_number + 1);
        soundtrack_last_played = millis();
      }
      
    }
}
