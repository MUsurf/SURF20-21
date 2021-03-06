# This is Mason's stuff. He wanted to delete it, but Maria wouldn't let him. Don't worry about it.


from pymavlink import mavutil
import time

master = mavutil.mavlink_connection("/dev/ttyACM0", baud=115200)
master.wait_heartbeat()

master.mav.command_long_send(
    master.target_system,
    master.target_component,
    mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
    0,
    1, 0, 0, 0, 0, 0, 0)
#Init finished -- will need to be replaced with calling arm.py but im lazy

#master.mav.ap_adc_encode()

master.mav.request_data_stream_send(master.target_system, master.target_component, mavutil.mavlink.MAV_DATA_STREAM_ALL, 9600, 1)

count = 0

#The polling method:
while True:
    master.recv_msg()
    try:
        adc1=master.messages['AP_ADC'].adc1  # Note, you can access message fields as attributes!
        adc2=master.messages['AP_ADC'].adc2
        adc3=master.messages['AP_ADC'].adc3
        adc4=master.messages['AP_ADC'].adc4
        adc5=master.messages['AP_ADC'].adc5
        adc6=master.messages['AP_ADC'].adc6

        print(adc1, adc2, adc3, adc4, adc5, adc6)
    except:
        print('No ADC message received (' + str(count) + ')')
        time.sleep(1)
        count+=1
