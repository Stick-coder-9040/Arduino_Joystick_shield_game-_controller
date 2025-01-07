# Arduino_Joystick_shield_game-_controller
This project makes the arduino ( with an ATMEGA32U4 chip) work as a game controller of a macropad with the joystick shield. 


Required materials 
- an arduino leonardo
   - this is because the leonardo has headers for the joystick controller to just work as a shield
   - link : https://docs.arduino.cc/hardware/leonardo/

-funduino joystick shield
   - this is the shield for the arduino that has the buttons and the joystick connected.
   - the pins for the connections are:
           - buttons: 2,3,4,5,6,8
           - potentiometers: A0,A1
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

the mappings can be changed in the KEY_MAPPING const int. 

more updates coming soon !
