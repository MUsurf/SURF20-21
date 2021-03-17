#Author: Jacob Voshage
#Function to do list:
#go forward
#go backward
#turn left
#turn right
#pitch up
#pitch down
#roll left
#roll right
#ascend
#descend

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
time.sleep(1)
x = 0
STOP = 320
COUNTERCWSTART=327
CWSTART=313

'''
while(x < 10):
	esc.set_all_pwm(0, 320-x)
	print(320-x)
	x += 1
	time.sleep(1)

time.sleep(3)


while(x > 0):
	esc.set_all_pwm(0, 320-x)
	print(320-x)
	x -= 1
	time.sleep(1)
'''

esc.set_all_pwm(0, 345)
time.sleep(10)
esc.set_all_pwm(0, 320)




