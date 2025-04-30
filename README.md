# Arduino_Joystick_shield_game-_controller
This project makes the arduino ( with an ATMEGA32U4 chip) work as a game controller of a macropad with the joystick shield. 


Required materials 
- An Arduino Leonardo
   - This is because the leonardo has headers for the joystick controller to just work as a shield
   - link : https://docs.arduino.cc/hardware/leonardo/

-funduino joystick shield
   - This is the shield for the arduino that has the buttons and the joystick connected.
   - The pins for the connections are:
           - Buttons: 2,3,4,5,6,8
           - Potentiometers: A0,A1
   -https://funduinoshop.com/en/electronic-modules/keypads-and-buttons/joysticks/joystick-shield-v1.a-arduino-uno-compatible

All you have to do is connect the shield on the leonardo and upload the code ! it is that simple!

I will be updating the code to make the sensitivity smoother and make the key mappings more straight forward.

In this case the four main buttons are mapped as :
-A - 'w'

-B - 'd'

-C - 'space'

-D - 'a'

-E - 'e'

-F - 'right click ( from the mouse.h library)'

-Joystick button - 'left click'

The mappings can be changed in the KEY_MAPPING const int. 


