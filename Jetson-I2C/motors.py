#Author: Jacob Voshage

# Notable values: 
#	240 -> max reverse throttle
#   320 -> neutral throttle (off)
#	410 -> max forward throttle

from __future__ import division
import time

# Import the PCA9685 module.
import Adafruit_PCA9685

# Initialise the PCA9685 using the default address (0x40).
esc = Adafruit_PCA9685.PCA9685()

# Set frequency to 50hz, good for esc
esc.set_pwm_freq(50)

#Available functions. See Adafruit_PCA9685/PCA9685.py
# esc.set_pwm(motor,0,pulse)
# esc.set_all_pwm(0,pulse)	

#Arm all motors
esc.set_all_pwm(0,320)

