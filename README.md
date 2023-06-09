# FabricBot
A remote-controlled bot which designed to pass an obstacle course.  
This repo aggregates all the files needed to build it yourself.

![](https://github.com/dkofanov/FabricBot/blob/upload/MEDIA/IMG_2812.jpg?raw=true)
![](https://github.com/dkofanov/FabricBot/blob/upload/MEDIA/photo_2023-06-09_06-25-05.jpg?raw=true)
![](https://github.com/dkofanov/FabricBot/blob/upload/MEDIA/IMG_2813.jpg?raw=true)

The key trait of the bot is a steering wheels system. As soon as there is no differential, each of the wheels is attached to a separate motor and "inner-outer" wheels rotating difference is obtained programmatically.
## Points to pay attention
* Servo shouldn't be powered from the Arduino board, doing this will cause the board to restart on each turn (and to loss control).
* 3D-printed wheels are quite slippery, you may want to cover edges in hot glue or chose other shape/material.
* The rear of the bot definitely lacks something of ball-wheel kind. Without it bot tends to hook everything below it.

## Materials and components
* Chasis and wheels are 3D-printed (STLs are in the repo)
* 5x bearings 10x5x4
* 2x DC motors
* H-bridge (e.g. Amperka Motor Shield)
* Servo
* 2x Arduino UNO (bot + transmitter)
* Batteries
* Receiver-transmitter pair
* Joystick
