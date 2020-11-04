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
    #running a bunch of different values, if all motors running at different speeds, it works!

    print(joystick.y)
    set_rc_channel_pwm(1, 1500)
    set_rc_channel_pwm(2, 1500)
    set_rc_channel_pwm(3, 1500)
    set_rc_channel_pwm(4, 1500)
    set_rc_channel_pwm(5, 1600)
    set_rc_channel_pwm(6, 1500)
    set_rc_channel_pwm(7, 1500)
    set_rc_channel_pwm(8, 1500)


    


pyglet.clock.schedule(lambda dt: None)

pyglet.app.run()
