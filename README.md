# SURF20-21
## About
We are working on creating a completely autonomous submarine to compete in the 2021 [Robosub](https://robonation.org/programs/robosub/) competition. We are using an onboard Nvidia Jetson TX2 in combonation with a Pixhawk in order to control and process the 8 motors, 2 cameras, 2 hydrophones and sensors that are onboard. 

For more information about our club, visit our [website](http://mizzousurf.com). 

## To Do List
- [ ] Joystick Control
  - We should be able to control the motors using an Xbox controller. Currently, we are trying to use the [pyglet library](https://github.com/pyglet/pyglet) for python. 
  - The joystick control has to work through the tethered connection. Meaning, the joystick will be connected to the surface computer which will the connected to the sub via an ethernet cable. The joystick commands have to be sent from this surface computer to the Jetson onboard the sub.
- [ ] Control the motors via Python
  - See [pymavlink](https://www.ardusub.com/developers/pymavlink.html). This has pretty much all of the information needed to control the sub from the Jetson using python.
  - There are currently two thoughts on how to control the motors. Either we can use the "Send Manual Control" function or the "Send RC" function. More research is needed to know how to do this.
- [ ] Read sensor data from the Pixhawk
  - There should be a gyroscope and accelerometer onboard the pixhawk and we will definitely need to be able to access this data for autonomous operation.
  - There is a high chance that we may plug other sensors and devices into the pixhawk via the ADC ports or the I2C port. We should be able to read and communicate with these devices from a python script running on the Jetson.
- [ ] Camera image recognition

## Important Links
- [Sending and recieving messages through pymavlink](https://mavlink.io/en/mavgen_python/)
- [Message names and attributes](https://mavlink.io/en/messages/ardupilotmega.html)

## Pixhawk Setup
The Pixhawk is setup using QGroundControl.
- Firmware: ChibiOS, Sub, Pixhawk1 - 4.0.2
- Calibrate sensors as instructed on QGroundControl
- In the frame tab, select "Vectored-6DOF"
