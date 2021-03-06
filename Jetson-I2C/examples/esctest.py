# Simple demo of of the PCA9685 PWM servo/LED controller library.
# This will move channel 4 and 5 to positions based on your input

from __future__ import division
import time

# Import the PCA9685 module.
import Adafruit_PCA9685


# Uncomment to enable debug output.
#import logging
#logging.basicConfig(level=logging.DEBUG)

# Initialise the PCA9685 using the default address (0x40).
pwm = Adafruit_PCA9685.PCA9685()

# Set frequency to 60hz, good for servos.
pwm.set_pwm_freq(50)

print('Moving esc on channel 4, press Ctrl-C to quit...')

#arm motor
pwm.set_pwm(4,0,320)
pwm.set_pwm(5,0,320)
time.sleep(1)

while True:
    i=input("enter PWM pulse in us: ")
    pwm.set_pwm(4,0,int(i))
    pwm.set_pwm(5,0,int(i))
    time.sleep(1)
