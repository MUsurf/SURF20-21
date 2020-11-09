import pyglet
from pyglet.gl import *
from pymavlink import mavutil
import time

joysticks = pyglet.input.get_joysticks()
assert joysticks, 'No joystick device is connected'
joystick = joysticks[0]
joystick.open()
master = mavutil.mavlink_connection("/dev/ttyACM0", baud=115200)
master.wait_heartbeat()

input_array = [1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500]

window = pyglet.window.Window()
main_batch = pyglet.graphics.Batch()

master.mav.command_long_send(
    master.target_system,
    master.target_component,
    mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
    0,
    1, 0, 0, 0, 0, 0, 0)

def set_rc_channel_pwm(channel_id, pwm=1500):
    rc_channel_values = [65535 for _ in range(8)]
    rc_channel_values[channel_id - 1] = pwm
    master.mav.rc_channels_override_send(
        master.target_system,
        master.target_component,
        *rc_channel_values)



@window.event
def on_draw():
    #breakdown of channels:
        #1: pitch = input_array[0]
        #2: Roll = input_array[1]
        #3: Throttle = input_array[2]
        #4: Yaw = input_array[3]
        #5: Forward = input_array[4]
        #6: Lateral = input_array[5]
        #7: camera pan = input_array[6]
        #8: Camera Tilt = input_array[7]
        #9, 10, 11: lights 1 lights 2 and video switch = etc. etc.
#so what this part of script does it get all inputs into array then run all the RC command functions using our calculated inputs

#BUT, im not sure how this will work if we're sending multiple channels at the same time, like if we send pitch and yaw will it work? idk guess we'll see...

    get_input(input_array)
    set_rc_channel_pwm(1, input_array[0])
    set_rc_channel_pwm(2, input_array[1])
    set_rc_channel_pwm(3, input_array[2])
    set_rc_channel_pwm(4, input_array[3])
    set_rc_channel_pwm(5, input_array[4])
    set_rc_channel_pwm(6, input_array[5])
    set_rc_channel_pwm(7, input_array[6])
    set_rc_channel_pwm(8, input_array[7])


def get_input(inputs):
        #up_down = 1500 + (joystick.hat_y*250)

    pitch = 1500 + (int(joystick.buttons[3]) * 200) - (int(joystick.buttons[1]) * 200)
    inputs[0] = pitch

    roll = 1500 + (round(clamp(joystick.ry,0,1) * 400)) - (round(clamp(joystick.rx,0,1)*400))
    inputs[1] = roll

    yaw = 1500 - (int(joystick.buttons[4]) * 200) + (int(joystick.buttons[5]) * 200)
    inputs[3] = yaw

    if(joystick.y> 0.09 or joystick.y < -0.09):
        forward_back = 1500 - (round(joystick.y*400))
    else:
        forward_back = 1500
    inputs[4] = forward_back

    if(joystick.z > 0.09 or joystick.z < -0.09):
        right_left = 1500 + (round(joystick.z*250))
    else:
        right_left = 1500
    inputs[5] = right_left

def clamp(num, min_value, max_value):
   return max(min(num, max_value), min_value)


pyglet.clock.schedule(lambda dt: None)

pyglet.app.run()
