///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//©Sashant Sankar
//Arduino leonardo based game controller for minecraft. ( the key mappings can be changed based on user's need)
//components: 1 Arduino Leonardo(https://docs.arduino.cc/hardware/leonardo/), Funduino joystick shield (https://funduinoshop.com/en/electronic-modules/keypads-and-buttons/joysticks/joystick-shield-v1.a-arduino-uno-compatible)
//Key mappings can be changed on line 16
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







#include <Mouse.h>
#include <Keyboard.h>
const char KEY_MAPPING[] = {'w', 'd', ' ', 'a', 'e'};
// Joystick pins
const int JOYSTICK_X = A0;
const int JOYSTICK_Y = A1;
const int JOYSTICK_BTN = 8; // Joystick button pin
const int RIGHTCLICKBTN = 7;
// Button pins
const int BUTTONS[] = {2, 3, 4, 5, 6}; // Adjust based on your shield
const int N_BUTTONS = sizeof(BUTTONS) / sizeof(BUTTONS[0]);

// Sensitivity settings
const int SENSITIVITY = 200; // Adjust cursor speed sensitivity
const int DEADZONE = 1;   // Ignore small movements

// Variables for joystick
int xValue = 0;
int yValue = 0;
int joystickBtnState = HIGH;
int rightclickstate = HIGH;
// Variables for buttons
int buttonState[N_BUTTONS] = {};

// Setup function
void setup() {
  // Initialize joystick
  pinMode(JOYSTICK_BTN, INPUT_PULLUP);

  // Initialize buttons
  for (int i = 0; i < N_BUTTONS; i++) {
    pinMode(BUTTONS[i], INPUT_PULLUP);
  }

  // Start Mouse emulation
  Mouse.begin();
}

// Loop function
void loop() {
  // Read joystick
  xValue = analogRead(JOYSTICK_X) - 512;
  yValue = analogRead(JOYSTICK_Y) - 512;

  // Ignore small movements
  if (abs(xValue) > DEADZONE || abs(yValue) > DEADZONE) {
    Mouse.move(xValue / SENSITIVITY, -yValue / SENSITIVITY); // Invert Y for natural movement
  }

  // Read joystick button
  int currentJoystickBtnState = digitalRead(JOYSTICK_BTN);
  if (currentJoystickBtnState == LOW && joystickBtnState == HIGH) {
    Mouse.press(MOUSE_LEFT);
  } else if (currentJoystickBtnState == HIGH && joystickBtnState == LOW) {
    Mouse.release(MOUSE_LEFT);
  }
  joystickBtnState = currentJoystickBtnState;

    // Read joystick button
  int currentrightclickstate = digitalRead(RIGHTCLICKBTN);
  if (currentrightclickstate == LOW && joystickBtnState == HIGH) {
    Mouse.press(MOUSE_RIGHT);
  } else if (currentrightclickstate == HIGH && rightclickstate == LOW) {
    Mouse.release(MOUSE_RIGHT);
  }
  rightclickstate = currentrightclickstate;


  // Read buttons and process input
  for (int i = 0; i < N_BUTTONS; i++) {
    int currentButtonState = digitalRead(BUTTONS[i]); // Read current button state
    if (currentButtonState == LOW && buttonState[i] == HIGH) {
      // Button was just pressed
      Keyboard.press(KEY_MAPPING[i]);
    } else if (currentButtonState == HIGH && buttonState[i] == LOW) {
      // Button was just released
      Keyboard.release(KEY_MAPPING[i]);
    }
    // Update the button state
    buttonState[i] = currentButtonState;
  }
  delay(10); // Small delay to prevent spamming inputs
}_