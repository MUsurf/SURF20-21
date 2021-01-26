#!/usr/bin/env python
# ----------------------------------------------------------------------------
# pyglet
# Copyright (c) 2006-2008 Alex Holkner
# Copyright (c) 2008-2020 pyglet contributors
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions 
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright 
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#  * Neither the name of pyglet nor the names of its
#    contributors may be used to endorse or promote products
#    derived from this software without specific prior written
#    permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# ----------------------------------------------------------------------------

'''
SURF comment
This code is meant to test what numbers will be returned when different joystick buttons are pressed
Number Meanings for the black XBox controller:
    joystick.y = vertical directions for the top left joystick (up = -1.0)(down = 1.0)
    joystick.x = horizontal directions for the top left joystick (left = -1.0)(right = 1.0)
    joystick.z = top left wing button (pushed down = 1.0)(all the way up = -1.0)
'''



import pyglet
from pyglet.gl import *

joysticks = pyglet.input.get_joysticks() #returns an array representing all joysticks connected
assert joysticks, 'No joystick device is connected'
joystick = joysticks[0] #if there is only one joystick, then it will be stored at index 0
joystick.open()

window = pyglet.window.Window()
main_batch = pyglet.graphics.Batch()

#Labels


@window.event
def on_draw():
    print(joystick.y)
    print(joystick.x)
    print(joystick.z)
    print(joystick.rz) 


pyglet.clock.schedule(lambda dt: None)

pyglet.app.run()
