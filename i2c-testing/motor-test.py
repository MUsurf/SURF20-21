# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT

"""Simple test for a standard servo on channel 0 and a continuous rotation servo on channel 1."""
import time
from adafruit_servokit import ServoKit
import adafruit_motor.servo

# Set channels to the number of servo channels on your kit.
# 8 for FeatherWing, 16 for Shield/HAT/Bonnet.
kit = ServoKit(channels=8)

#kit.servo[1].angle = 90
kit.continuous_servo[1].throttle = 1
print("servo initialized")
time.sleep(1)

#kit.servo[1].angle = 180
kit.continuous_servo[1].throttle = -1
print("servo set to 180")
time.sleep(1)

#kit.servo[1].angle = 0
kit.continuous_servo[1].throttle = 1
print("servo set to 0")
time.sleep(3)

kit.continuous_servo[1].throttle = 0
#print("Servo back at 90")

