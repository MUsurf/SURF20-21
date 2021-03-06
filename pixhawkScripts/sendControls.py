"""
Example of how to send MANUAL_CONTROL messages to the autopilot using
pymavlink.
This message is able to fully replace the joystick inputs.
"""

# Import mavutil
from pymavlink import mavutil
import time
import pyglet
from pyglet.gl import *


# Create the connection
master = mavutil.mavlink_connection("/dev/ttyACM0", baud=115200)
print('connection made')

# Wait a heartbeat before sending commands
master.wait_heartbeat()
print('heartbeat received')

#get joystick info and open
'''joysticks = pyglet.input.get_joysticks()
assert joysticks, 'no joystick connected'
joystick = joysticks[0]
joystick.open()'''

# Send a positive x value, negative y, negative z,
# positive rotation and no button.
# https://mavlink.io/en/messages/common.html#MANUAL_CONTROL
# Warning: Because of some legacy workaround, z will work between [0-1000]
# where 0 is full reverse, 500 is no output and 1000 is full throttle.
# x,y and r will be between [-1000 and 1000].

master.mav.command_long_send(
    master.target_system,
    master.target_component,
    mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
    0,
    1, 0, 0, 0, 0, 0, 0)
print('vehicle armed')


master.mav.manual_control_send(
    master.target_system,
    1000,
    0,
    0,
    0,
    0)
input()

#first we see if engines will even turn on before trying to control them with controller

#guide for man control: target, roll, pitch, yaw, thrust, roll_manual, pitch_manual, yaw_manual, thrust_manual
#so its just an infinite loop sending different controls depending on left stick position. Should work. 
'''while(True):
    
    print(joystick.y)
    if(joystick.buttons[3]):
        print("button pressed")
    if(joystick.y >= 0.09):
        master.mav.manual_control_send(
            master.target_system,
            500,
            500,
            500+(joystick.y*-500),
            500,
            0)
        print(500+(joystick.y*-500))
    elif(joystick.y <= -0.09):
        master.mav.manual_control_send(
            master.target_system,
            500,
            500,
            500+(joystick.y*-500),
            500,
            0)
        print(500+(joystick.y*-500))
    else:
        master.mav.manual_control_send(
            master.target_system,
            500,
            -500,
            500,
            500,
            0)
        
'''

# To active button 0 (first button), 3 (fourth button) and 7 (eighth button)
# It's possible to check and configure this buttons in the Joystick menu of QGC
# buttons = 1 + 1 << 3 + 1 << 7
# master.mav.manual_control_send(
#     master.target_system,
#     0,
#     0,
#     500, # 500 means neutral throttle
#     0,
#     buttons)
