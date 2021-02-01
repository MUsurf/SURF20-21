import pyglet
from pyglet.gl import *
from pymavlink import mavutil
import time

joysticks = pyglet.input.get_joysticks()
assert joysticks, 'No joystick device is connected'
joystick = joysticks[0]
joystick.open()


input_array = [1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500]

window = pyglet.window.Window()
main_batch = pyglet.graphics.Batch()





@window.event
def on_draw():
    #breakdown of channels:
        #1: pitch = input_array[0] ('forward flip or backward flip')
        #2: Roll = input_array[1] ('cartweel to either side, or roll')
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


    #print(input_array)
    print(joystick.ry)
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
    if(joystick.buttons[2]):
        input_array = [1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500]

def clamp(num, min_value, max_value):
   return max(min(num, max_value), min_value)


pyglet.clock.schedule(lambda dt: None)

pyglet.app.run()
