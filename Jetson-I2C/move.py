from __future__ import division
import time
import Adafruit_PCA9685
import math

esc = Adafruit_PCA9685.PCA9685()
esc.set_pwm_freq(50)
esc.set_all_pwm(0,320)


def getPWMList(radianDirection, totalPWMSpeed):
	#motor 3
	frontRight = cos(radianDirection - (math.pi/4))
	#motor 4
	backRight = sin(radianDirection - (math.pi/4))
	#motor 5
	backLeft = cos(radianDirection - (5*math.pi/4))
	#motor 8
	frontLeft = sin(radianDirection - (5*math.pi/4))
	return [frontRight,backRight,backLeft,frontLeft]


speedList = getPWMList(0, 340)
print(speedList)
#esc.set_pwm(0,0,speedList[0])
#esc.set_pwm(1,0,speedList[1])
#esc.set_pwm(2,0,speedList[2])
#esc.set_pwm(3,0,speedList[3])
#time.sleep(5)
#esc.set_all_pwm(0,320)

