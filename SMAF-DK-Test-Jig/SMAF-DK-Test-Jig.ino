/**
* SMAF-DK-Test-Jig.ino
* Main Arduino sketch for the SMAF-DK-Test-Jig project.
*
* @license MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "Helpers.h"
#include "AudioVisualNotifications.h"

const int neoPixel = 4;  // IO04, ADC1-CH0
const int speaker = 5;   // IO05, ADC1-CH4
const int gpio01 = 1;    // IO01, SDA
const int gpio02 = 2;    // IO02, SCL
const int gpio06 = 6;    // IO06, ADC1-CH5
const int gpio07 = 7;    // IO07, ADC1-CH6
const int gpio08 = 8;    // IO08, ADC1-CH7
const int gpio09 = 9;    // IO09, ADC1-CH8
const int gpio10 = 10;   // IO10, ADC1-CH9
const int gpio11 = 11;   // IO11, ADC2-CH0
const int gpio12 = 12;   // IO12, ADC2-CH1
const int gpio13 = 13;   // IO13, ADC2-CH2
const int gpio14 = 14;   // IO14, ADC2-CH3
const int gpio15 = 15;   // IO15, U0RTS, ADC2-CH4
const int gpio16 = 16;   // IO16, U0CTS, ADC2-CH5
const int gpio17 = 17;   // IO17, U1TXD, ADC2-CH6
const int gpio18 = 18;   // IO18, U0RXD, ADC2-CH7
const int gpio21 = 21;   // IO21
const int gpio33 = 33;   // IO33, SPIIO04
const int gpio34 = 34;   // IO34, SPIIO05
const int gpio39 = 39;   // IO39, MTCK
const int gpio40 = 40;   // IO40, MTDO
const int gpio41 = 41;   // IO41, MTDI
const int gpio42 = 42;   // IO42, MTMS
const int gpio43 = 43;   // IO43, U0TXD
const int gpio44 = 44;   // IO44, U0RXD
const int gpio47 = 47;   // IO47

/**
* Constructs an AudioVisualNotifications object with specified parameters.
* Initializes the NeoPixel and speaker pin settings for audio-visual notifications.
* 
* @param neoPixelPin The GPIO pin connected to the NeoPixel.
* @param neoPixelCount The number of NeoPixels in the strip.
* @param neoPixelBrightness The brightness level of the NeoPixels (0-255).
* @param speakerPin The GPIO pin connected to the speaker.
*/
AudioVisualNotifications notifications(neoPixel, 2, 40, speaker);

/**
* This function is responsible for the initial setup of the SMAF-DK-Test-Jig.
* It is executed once when the Arduino board starts or is reset.
*/
void setup() {
  // Initialize serial communication at a baud rate of 115200.
  Serial.begin(115200);

  // Set all defined pins to input.
  pinMode(gpio01, INPUT);
  pinMode(gpio02, INPUT);
  pinMode(gpio06, INPUT);
  pinMode(gpio07, INPUT);
  pinMode(gpio08, INPUT);
  pinMode(gpio09, INPUT);
  pinMode(gpio10, INPUT);
  pinMode(gpio11, INPUT);
  pinMode(gpio12, INPUT);
  pinMode(gpio13, INPUT);
  pinMode(gpio14, INPUT);
  pinMode(gpio15, INPUT);
  pinMode(gpio16, INPUT);
  pinMode(gpio17, INPUT);
  pinMode(gpio18, INPUT);
  pinMode(gpio21, INPUT);
  pinMode(gpio33, INPUT);
  pinMode(gpio34, INPUT);
  pinMode(gpio39, INPUT);
  pinMode(gpio40, INPUT);
  pinMode(gpio41, INPUT);
  pinMode(gpio42, INPUT);
  pinMode(gpio43, INPUT);
  pinMode(gpio44, INPUT);
  pinMode(gpio47, INPUT);

  // Initialize visualization library neo pixels.
  // This does not light up neo pixels.
  notifications.initializeVisualNotifications();
  notifications.clearAllVisualNotifications();
  notifications.initializePixel(0, 0, 0, 255);
  notifications.initializePixel(1, 0, 255, 0);

  // Play intro melody on speaker if enabled in preferences.
  notifications.introAudioNotification();
}

/**
* This function runs repeatedly in a loop after the initial setup.
* It is the core of your Arduino program, where continuous tasks and operations should be placed.
* Be mindful of keeping the loop efficient and avoiding long blocking operations.
*/
void loop() {
  // IO01, SDA
  if (digitalRead(gpio01) == HIGH) {
    debug(SCS, "GPIO-01 detected.");
  }

  // IO02, SCL
  if (digitalRead(gpio02) == HIGH) {
    debug(SCS, "GPIO-02 detected.");
  }

  // IO06, ADC1-CH5
  if (digitalRead(gpio06) == LOW) {
    debug(SCS, "GPIO-06 detected.");

    // Play maintenance melody on speaker if enabled in preferences.
    notifications.maintenanceAudioNotification();
  }

  // IO07, ADC1-CH6
  if (digitalRead(gpio07) == HIGH) {
    debug(SCS, "GPIO-07 detected.");
  }

  // IO08, ADC1-CH7
  if (digitalRead(gpio08) == HIGH) {
    debug(SCS, "GPIO-08 detected.");
  }

  // IO09, ADC1-CH8
  if (digitalRead(gpio09) == HIGH) {
    debug(SCS, "GPIO-09 detected.");
  }

  // IO10, ADC1-CH9
  if (digitalRead(gpio10) == HIGH) {
    debug(SCS, "GPIO-10 detected.");
  }

  // IO11, ADC2-CH0
  if (digitalRead(gpio11) == HIGH) {
    debug(SCS, "GPIO-11 detected.");
  }

  // IO12, ADC2-CH1
  if (digitalRead(gpio12) == HIGH) {
    debug(SCS, "GPIO-12 detected.");
  }

  // IO13, ADC2-CH2
  if (digitalRead(gpio13) == HIGH) {
    debug(SCS, "GPIO-13 detected.");
  }

  // IO14, ADC2-CH3
  if (digitalRead(gpio14) == HIGH) {
    debug(SCS, "GPIO-14 detected.");
  }

  // IO15, U0RTS, ADC2-CH4
  if (digitalRead(gpio15) == HIGH) {
    debug(SCS, "GPIO-15 detected.");
  }

  // IO16, U0CTS, ADC2-CH5
  if (digitalRead(gpio16) == HIGH) {
    debug(SCS, "GPIO-16 detected.");
  }

  // IO17, U1TXD, ADC2-CH6
  if (digitalRead(gpio17) == HIGH) {
    debug(SCS, "GPIO-17 detected.");
  }

  // IO18, U0RXD, ADC2-CH7
  if (digitalRead(gpio18) == HIGH) {
    debug(SCS, "GPIO-18 detected.");
  }

  // IO21
  if (digitalRead(gpio21) == HIGH) {
    debug(SCS, "GPIO-21 detected.");
  }

  // IO33, SPIIO04
  if (digitalRead(gpio33) == HIGH) {
    debug(SCS, "GPIO-33 detected.");
  }

  // IO34, SPIIO05
  if (digitalRead(gpio34) == HIGH) {
    debug(SCS, "GPIO-34 detected.");
  }

  // IO39, MTCK
  if (digitalRead(gpio39) == HIGH) {
    debug(SCS, "GPIO-39 detected.");
  }

  // IO40, MTDO
  if (digitalRead(gpio40) == HIGH) {
    debug(SCS, "GPIO-40 detected.");
  }

  // IO41, MTDI
  if (digitalRead(gpio41) == HIGH) {
    debug(SCS, "GPIO-41 detected.");
  }

  // IO42, MTMS
  if (digitalRead(gpio42) == HIGH) {
    debug(SCS, "GPIO-42 detected.");
  }

  // IO43, U0TXD
  if (digitalRead(gpio43) == HIGH) {
    debug(SCS, "GPIO-43 detected.");
  }

  // IO44, U0RXD
  if (digitalRead(gpio44) == HIGH) {
    debug(SCS, "GPIO-44 detected.");
  }

  // IO47
  if (digitalRead(gpio47) == HIGH) {
    debug(SCS, "GPIO-47 detected.");
  }
}