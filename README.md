<div align="center">
<img src="assets/images/buzzer.png" width="200"/>

<h1 align="center">Game Buzzers</h1>

![3D printed](https://img.shields.io/badge/Done-0b0?style=for-the-badge&logo=checkmarx&logoColor=white&label=status)
![top languages](https://img.shields.io/github/languages/top/andreasnicklaus/game-buzzers?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![3D printed](https://img.shields.io/badge/3D--Printed-c66?style=for-the-badge&logo=blueprint&logoColor=white)

</div>

## :sunflower: Description and Motivation

Project `Game Buzzers` includes the embedded code in buzzers and a control terminal for multiple game modes.

My favorite card game is 'Monkey', a game of mental multitasking and quick reactions. A part of the game is everybody putting in their hand and the last one to put their hand in the middle of table loses. This part of the game is prone to injury with competitive players. The game mode 'monkey' replaces this part of the game.
In addition, I love playing quizes with my friends and family. The game mode 'quiz' allows contestants to buzz in to anwser questions.

For this project, I learned to code for Arduino and in C++ and I learned soldering and a bit of electrical curcuitry and 3D modelling. It's not perfect by a long shot, but it works.


## :bookmark: Table of Contents

- [:sunflower: Description and Motivation](#sunflower-description-and-motivation)
- [:bookmark: Table of Contents](#bookmark-table-of-contents)
- [:building\_construction: Building and Installation](#building_construction-building-and-installation)
  - [:wrench: Building: Parts and Soldering](#wrench-building-parts-and-soldering)
  - [:screwdriver: Installation: Compiling and Flashing](#screwdriver-installation-compiling-and-flashing)
- [:arrow\_forward: Usage](#arrow_forward-usage)
  - [:nut\_and\_bolt: Components](#nut_and_bolt-components)
  - [:high\_brightness: Modes](#high_brightness-modes)
- [:+1: Collaborators](#1-collaborators)
- [:scroll: License](#scroll-license)

## :building_construction: Building and Installation

What are the steps required to install your project? Provide a step-by-step description of how to get the development environment running.

*Hint: The part list and code expects one controller terminal and 6 buzzer buttons.*

### 	:wrench: Building: Parts and Soldering

1. Buy (or search from a drawer) the following electrical parts:
   1. 6 Arduino Nano ([example part](https://www.amazon.de/dp/B0CPTZKRP3?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   2. 1 Arduino Micro ([example part](https://www.reichelt.de/de/de/arduino-micro-atmega32u4-microusb-arduino-micro-p130166.html?PROVID=2788&gad_source=1&gclid=Cj0KCQjwsPCyBhD4ARIsAPaaRf3ZUSLnkehNaqaTkQEhOhHEiTTxGXjOe1krdQb59aUsY_n1jT3tHzEaAtqJEALw_wcB&&r=1))
   3. 7 round ON/OFF-switches ([example part](https://www.amazon.de/dp/B09TKVSHRF?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   4. 6 big dome buttons ([example part](https://www.amazon.de/dp/B008FZJ2WE?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   5. 2 small buttons ([example part](https://www.berrybase.de/kurzhubtaster-vertikale-printmontage-6x6mm-h-5-0mm))
   6. 8 LEDs ([example part](https://www.amazon.de/dp/B0BC85WDTM?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   7. 6 radio transmitter-receiver pairs ([example part](https://www.amazon.de/dp/B01H2D2RH6?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   8. 7 9V batteries ([example part](https://www.amazon.de/dp/B0CQLYW79X?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   9. 7 9V battery jumper wires ([example part](https://www.amazon.de/dp/B0BGPG3NCY?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   10. Jumper wires ([example part](https://www.amazon.de/dp/B01EV70C78?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   11. Resistors ([example part](https://www.amazon.de/dp/B09KGLG8CM?psc=1&ref=ppx_yo2ov_dt_b_product_details))
   12. DFPlayer Mini ([example part](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299))
   13. Micro-SD cards ([example part](https://www.reichelt.de/microsdhc-speicherkarte-32gb-sandisk-ultra-sdsqua4032ggn6ma-p297179.html))
   14. Speakers ([example part](https://www.amazon.de/dp/B09PL6XFHC?psc=1&ref=ppx_yo2ov_dt_b_product_details))
2. Solder parts according to the curcuit diagram below
3. Build or buy 3D-printed or other casings
   1. 1 terminal: `cases/terminal/Controller_Box.stl` and `cases/terminal/Controller_Deckel.stl`
   2. 6 buttons: `cases/button/Button_Box.stl` and `cases/button/Button_Deckel.stl`
4. Insert the soldered parts into the cases according to the user interface below (a little filing or glueing might be necessary)

**Graphical circuit diagram:**

![](diagrams/graphical%20circuit%20diagram.png)

**User Interface:**

![](diagrams/user%20interface.png)

### :screwdriver: Installation: Compiling and Flashing

1. Clone this repository `git clone https://github.com/andreasnicklaus/game-buzzers.git`
2. Install the ([Arduino IDE](https://www.arduino.cc/en/software))
3. Connect the terminal via USB and flash the terminal code from [receiver](./receiver) on the controller ([How to upload code with the Arduino IDE](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE))
   1. Remap the LED connections in [receiver/receiver.ino](receiver/receiver.ino) with the help of the [init mode](#modes)
   ```ino
   // Output pins (change if the order is wrong)
   int LED_1_PIN = 5;
   int LED_2_PIN = 7;
   int LED_3_PIN = 6;
   int LED_4_PIN = 2;
   int LED_5_PIN = 4;
   int LED_6_PIN = 3;
   ```
   2. After remapping, reupload the code
2. For each button:
   1. Edit in [transmitter/transmitter.ino](./transmitter/transmitter.ino) `rf_msg` to give each button a unique number 1-6.
   ```ino
   //! change for every button
   const char *rf_msg = "1";
   ```
   2. Connect the button via USB and flash the transmitter code from [transmitter](./transmitter) ([How to upload code with the Arduino IDE](https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE))

## :arrow_forward: Usage

### :nut_and_bolt: Components

**Terminal**

1. ON/OFF-switch on the side turns the terminal box on and off
2. 2 top mode indicator LEDs show the current active mode, see [modes](#modes)
3. Right mode switch button cycles through the modes, see [modes](#modes)
4. Left reset button resets the current active game mode, indicated through all LEDs lighting up. I the reset button does not fix the current issue, turn the box off and on again.
5. 6 button indicator LEDs for each button

**Button**

1. ON/OFF-switch on the side turns the button box on and off
2. Big dome button to send the signal to the to the terminal box, indicated by the button lighting up

### :high_brightness: Modes

| L                      | R                      | Mode        |
| ---------------------- | ---------------------- | ----------- |
| off :black_circle:     | :black_circle: off     | Init Mode   |
| off :black_circle:     | :large_blue_circle: on | Monkey Mode |
| on :large_blue_circle: | :black_circle: off     | Quiz Mode   |
| on :large_blue_circle: | :large_blue_circle: on | Lights Mode |

1. **Init Mode**: Register active buttons or remove a button from active usage by pressing the button. Each indicator light will show a button as active by lighting up or switching off. Reset removes all registered active buttons.
2. **Monkey Mode**: Find the last pressed active buttons. Indicator LEDs light up for pressed buttons. The indicator LED for the last pressed button blinks. After a few seconds, the round resets. Reset starts a new round. Needs registration through the init mode.
3. **Quiz Mode**: Find the first pressed button. The indicator LED for the first pressed button blinks and resets after a few seconds. Reset starts a new round earlier. Does *not* need registration of active buttons through the init mode.
4. **Lights Mode**: Starts a light show to identify the LEDs. LED 1 blinks one time, LED 2 blinks twice and so on. Reset restarts the light show. Does not need the buttons to work.

## :+1: Collaborators

- [Andreas Nicklaus](https://github.com/andreasnicklaus) <br/> [![](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/andreasnicklaus/) [![](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/andreasnicklaus) [![](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/andreasnicklaus)

## :scroll: License

See [LICENSE](LICENSE) for the license of this project.

