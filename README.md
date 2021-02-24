# SURF20-21
## About
We are working on creating a completely autonomous submarine to compete in the 2021 [Robosub](https://robonation.org/programs/robosub/) competition. We are using an onboard Nvidia Jetson TX2 in combonation with the Adafruit 16 channel PWM I2C board (PCA9685) in order to control and process the 8 motors, 2 cameras, 2 hydrophones and sensors that are onboard. 

For more information about our club, visit our [website](http://mizzousurf.com). 

## To Do List
- [X] Control the motors via Python
  - See [Adafruit_Python](https://github.com/adafruit/Adafruit_Python_PCA9685). This has pretty much all of the information needed to control the motors from the Jetson using python over I2C.
- [ ] Joystick Control
  - We should be able to control the motors using an Xbox controller. Currently, we are trying to use the [pyglet library](https://github.com/pyglet/pyglet) for python. 
  - Eventually the joystick control has to work through the tethered connection. Meaning, the joystick will be connected to the surface computer which will the connected to the sub via an ethernet cable. The joystick commands have to be sent from this surface computer to the Jetson onboard the sub.
- [ ] Read sensor data from the BCO055 9 axis Gyroscope
- [ ] Read sensor data from depth sensor
- [ ] Camera image recognition (Optional)

## Important Links
- [Controlling the PCA9685 using I2C in python](https://github.com/adafruit/Adafruit_Python_PCA9685)

## Useful Commands
Check what devices are connected to I2C on the Jetson
```
sudo i2cdetect -y -r 1
```

## PCA9685 library Setup
```
sudo apt-get install git build-essential python-dev
cd ~
git clone https://github.com/adafruit/Adafruit_Python_PCA9685.git
cd Adafruit_Python_PCA9685
sudo pip3 install adafruit-pca9685
```
Open this file:
```
sudo nano /usr/local/lib/python3.6/dist-packages/Adafruit_GPIO/I2C.py 
```
And change this line:
```
raise RuntimeError('Could not determine default I2C bus for platform.')
```
with 
```
return 1
```
The reason this is necessary is because the library tries to detect what device it is running on and the Jetson TX2 is not an option. The Jetson uses bus 1 so thats why we return 1.


