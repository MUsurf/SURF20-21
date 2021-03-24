import time
import board
import busio
import adafruit_bno055
import Adafruit_PCA9685

esc = Adafruit_PCA9685.PCA9685()
esc.set_pwm_freq(50)
esc.set_all_pwm(0,320)
time.sleep(1)
x = 0

i2c = busio.I2C(board.SCL, board.SDA)
sensor = adafruit_bno055.BNO055_I2C(i2c)

last_val = 0xFFFF

eulerRollSet = 0
errorRollPrev = 0
integralRoll = 0
T=0.02 #Time delay between each loop.
J=10 #Moment of Inertia around the roll axis.
L=0.1 #Moment Arm between motors and roll axis.
P=0.1 #Proportional Gain
I=0.1 #Integral Gain
D=0.1 #Derivative Gain

while True:
	eulerRollCurr = sensor.euler[1] #Euler angle from IMU. 
	errorRollCurr = (((eulerRollCurr - eulerRollSet) * 3.1415926535) / 180) #Current angle minus desired angle.
	#integralRoll = integralRoll + ((errorRollCurr * T) - (0.5 * T * (errorRollCurr - errorRollPrev))) #Numerical calculation of area under error curve.
	derivativeRoll = ((errorRollCurr - errorRollPrev) / T) #Rate of change of euler angle.
	angAccelRoll = (P * errorRollCurr) + (I * integralRoll) + (D * derivativeRoll)
	TorqueRoll = (angAccelRoll * J)
	ForceTotalRoll = (TorqueRoll / L)

	eulerPitchCurr = sensor.euler[2] #Euler angle from IMU. 
	errorPitchCurr = (((eulerPitchCurr - eulerPitchSet) * 3.1415926535) / 180) #Current angle minus desired angle.
	#integralPitch = integralPitch + ((errorPitchCurr * T) - (0.5 * T * (errorPitchCurr - errorPitchPrev))) #Numerical calculation of area under error curve.
	derivativePitch = ((errorPitchCurr - errorPitchPrev) / T) #Rate of change of euler angle.
	angAccelPitch = (P * errorPitchCurr) + (I * integralPitch) + (D * derivativePitch)
	TorquePitch = (angAccelPitch * J)
	ForceTotalPitch = (TorquePitch / L)

	Force1 = (ForceTotal / 2)
	Force6 = ((- 1 *ForceTotal)/2)
	if Force1 > 0:
		pWm1 = (((Force1 * 15.29575879) + 1525) * .25)
	else:
		pWm1 = (((Force1 * 22.49374674) + 1475) * .25)
	if Force6 > 0:
		pWm2 = (((Force6 * 15.29575879) + 1525) * .25)
	else:
		pWm2 = (((Force6 * 22.49374674) + 1475) * .25)
	esc.set_pwm(1,0,int(pWm1))
	esc.set_pwm(6,0,int(pWm2))

	errorRollPrev = errorRollCurr
	errorPitchPrev = errorPitchCurr

	#print("Error: %f" % errorCurr)
	#print("Derivative: %d" % derivative)
	#print("Integral: %d" % integral)
	#print("AngAccel: %d" % angAccel)
	#print("Force1: %f" % Force1)
	#print("Force2: %d" % Force2)
	#print("PWM Motor1 = %d" % pWm1)
	#print("PWM Motor2 = %d" % pWm2)
	time.sleep(T)
