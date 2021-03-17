import board
import busio
import time
import Adafruit_PCA9685
import adafruit_bno055

STOP = 320
esc = Adafruit_PCA9685.PCA9685()
esc.set_pwm_freq(50)
esc.set_all_pwm(0, STOP)

i2c = busio.I2C(board.SCL, board.SDA)
sensor = adafruit_bno055.BNO055_I2C(i2c)

# FUNCTIONS:
# sensor.acceleration
# sensor.magnetic
# sensor.gyro
# sensor.euler
# sensor.quaternion
# sensor.linear_acceleration
# sensor.gravity

LEFT = 6
RIGHT = 2 
FRONT_L = 7
FRONT_R = 0
BACK_L = 4
BACK_R = 3

esc.set_all_pwm(0, STOP)
while(True):
    print(sensor.euler)
    time.sleep(1)
    if sensor.euler[1] < 0:     # if gyro is rolling
        esc.set_pwm(LEFT, 0, 335)
        esc.set_pwm(RIGHT, 0, 320)
    else:
        esc.set_pwm(RIGHT, 0, 335)
        esc.set_pwm(LEFT, 0, 320)
    if sensor.euler[2] < 0:     # if gyro is pitching
        esc.set_pwm(BACK_L, 0, 335)
        esc.set_pwm(FRONT_L, 0, 320)
    else:
        esc.set_pwm(BACK_L, 0, 320)
        esc.set_pwm(FRONT_L, 0, 335)
