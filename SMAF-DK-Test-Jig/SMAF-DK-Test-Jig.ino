/**
* @file SMAF-DK-Test-Jig.ino
* @brief Main Arduino sketch for the SMAF-DK-Test-Jig project.
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

const int neoPixel = 4;    // ADC1-CH0
const int buzzer = 5;      // ADC1-CH4
const int userButton = 6;  // ADC1-CH5
const int gpio01 = 1;      // SDA
const int gpio02 = 2;      // SCL
const int gpio07 = 7;      // ADC1-CH6
const int gpio08 = 8;      // ADC1-CH7
const int gpio09 = 9;      // ADC1-CH8
const int gpio10 = 10;     // ADC1-CH9
const int gpio11 = 11;     // ADC2-CH0
const int gpio12 = 12;     // ADC2-CH1
const int gpio13 = 13;     // ADC2-CH2
const int gpio14 = 14;     // ADC2-CH3
const int gpio15 = 15;     // U0RTS
const int gpio16 = 16;     // U0CTS
const int gpio17 = 17;     // U1TXD
const int gpio18 = 18;     // U0RXD
const int gpio21 = 21;     // IO21
const int gpio33 = 33;     // IO33
const int gpio34 = 34;     // IO34
const int gpio39 = 39;     // MTCK
const int gpio40 = 40;     // MTDO
const int gpio41 = 41;     // MTDI
const int gpio42 = 42;     // MTMS
const int gpio47 = 47;     // IO47
const int txd = 43;        // IO43, U0TXD
const int rxd = 44;        // IO44, U0RXD

/**
* @brief Constructs an instance of the AudioVisualNotifications class.
*
* Initializes an instance of the AudioVisualNotifications class with the provided configurations.
* The NeoPixel pin should be set up as OUTPUT before calling this constructor.
*
* @param neoPixelPin The pin connected to the NeoPixel LED strip.
* @param neoPixelCount The number of NeoPixels in the LED strip.
* @param neoPixelBrightness The brightness level of the NeoPixels (0-255).
* @param speakerPin The pin connected to the speaker for audio feedback.
*/
AudioVisualNotifications notifications(neoPixel, 2, 40, buzzer);

/**
* @brief Initializes the SMAF-DK-Test-Jig and runs once at the beginning.
*
* This function is responsible for the initial setup of the SMAF-DK-Test-Jig.
* It is executed once when the Arduino board starts or is reset.
*
*/
void setup() {
  // Initialize serial communication at a baud rate of 115200.
  Serial.begin(115200);

  // Set all defined pins to input.
  pinMode(userButton, INPUT);
  pinMode(gpio01, INPUT);
  pinMode(gpio02, INPUT);
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
  pinMode(gpio47, INPUT);
  // pinMode(txd, INPUT);
  // pinMode(rxd, INPUT);

  // Initialize visualization library neo pixels.
  // This does not light up neo pixels.
  notifications.initializeVisualNotifications();
  notifications.clearAllVisualNotifications();
  notifications.individualPixelControl(0, 0, 0, 255);
  notifications.individualPixelControl(1, 0, 255, 0);

  // Play intro melody on speaker if enabled in preferences.
  notifications.introAudioNotification();
}

/**
* @brief Main execution loop for the MAF-DK-Test-Jig.
*
* This function runs repeatedly in a loop after the initial setup.
* It is the core of your Arduino program, where continuous tasks and operations should be placed.
* Be mindful of keeping the loop efficient and avoiding long blocking operations.
*
*/
void loop() {
  if (digitalRead(userButton) == LOW) debug(SCS, "User button detected.");
  if (digitalRead(gpio01) == HIGH) debug(SCS, "GPIO-01 detected.");
  if (digitalRead(gpio02) == HIGH) debug(SCS, "GPIO-02 detected.");
  if (digitalRead(gpio07) == HIGH) debug(SCS, "GPIO-07 detected.");
  if (digitalRead(gpio08) == HIGH) debug(SCS, "GPIO-08 detected.");
  if (digitalRead(gpio09) == HIGH) debug(SCS, "GPIO-09 detected.");
  if (digitalRead(gpio10) == HIGH) debug(SCS, "GPIO-10 detected.");
  if (digitalRead(gpio11) == HIGH) debug(SCS, "GPIO-11 detected.");
  if (digitalRead(gpio12) == HIGH) debug(SCS, "GPIO-12 detected.");
  if (digitalRead(gpio13) == HIGH) debug(SCS, "GPIO-13 detected.");
  if (digitalRead(gpio14) == HIGH) debug(SCS, "GPIO-14 detected.");
  if (digitalRead(gpio15) == HIGH) debug(SCS, "GPIO-15 detected.");
  if (digitalRead(gpio16) == HIGH) debug(SCS, "GPIO-16 detected.");
  if (digitalRead(gpio17) == HIGH) debug(SCS, "GPIO-17 detected.");
  if (digitalRead(gpio18) == HIGH) debug(SCS, "GPIO-18 detected.");
  if (digitalRead(gpio21) == HIGH) debug(SCS, "GPIO-21 detected.");
  if (digitalRead(gpio33) == HIGH) debug(SCS, "GPIO-33 detected.");
  if (digitalRead(gpio34) == HIGH) debug(SCS, "GPIO-34 detected.");
  if (digitalRead(gpio39) == HIGH) debug(SCS, "GPIO-39 detected.");
  if (digitalRead(gpio40) == HIGH) debug(SCS, "GPIO-40 detected.");
  if (digitalRead(gpio41) == HIGH) debug(SCS, "GPIO-41 detected.");
  if (digitalRead(gpio42) == HIGH) debug(SCS, "GPIO-42 detected.");
  if (digitalRead(gpio47) == HIGH) debug(SCS, "GPIO-47 detected.");
}
