/* Arduino Multi Switch v0.1-alpha
 * https://github.com/ledeniz/arduino-multi-switch
 *
 * Author: Deniz Erdogan
 *
 * Based on https://github.com/arduino-libraries/MIDIUSB/blob/master/examples/MIDIUSB_write/MIDIUSB_write.ino
 * Based on https://github.com/ledeniz/midi-footswitch-converter
 * Licensed under GPLv3: https://www.gnu.org/licenses/gpl-3.0.en.html
 */

#include <Arduino.h>
#include <MIDIUSB.h>
#include <Keyboard.h>

#include "switch.h"

Switch s1 = Switch();

void setup() {
  Serial.begin(9600);

  s1.time = 23;

  delay(1000);

  Keyboard.print("blah"); delay(10);
  Keyboard.press(KEY_RETURN); delay(10);
  Keyboard.releaseAll();
}

void loop() {
  Serial.println(s1.time);
  delay(2000);
  midiEventPacket_t event = {0x0B, 0xB0 | 0, 64, 100};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}
