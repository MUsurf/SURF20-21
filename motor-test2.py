import time
from adafruit_servokit import ServoKit
kit = ServoKit(channels=16)
pca.frequency = 50
kit.servo[0].set_pulse_width_range(500, 1500)

kit.servo[0].angle = 90
time.sleep(2)
kit.servo[0].angle = 150
time.sleep(2)
kit.servo[0].angle = 30
time.sleep(2)
kit.servo[0].angle = 90
