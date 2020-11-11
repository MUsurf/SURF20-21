from pymavlink import mavutil

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

#The polling method:
while True:
    try:
        adc1=master.mav.messages['AP_ADC'].adc1  # Note, you can access message fields as attributes!
        adc2=master.mav.messages['AP_ADC'].adc2
        adc3=master.mav.messages['AP_ADC'].adc3
        adc4=master.mav.messages['AP_ADC'].adc4
        adc5=master.mav.messages['AP_ADC'].adc5
        adc6=master.mav.messages['AP_ADC'].adc6

        print(adc1 adc2 adc3 adc4 adc5 adc6 )
    except:
        print('No ADC message received')
