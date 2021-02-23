import board
import busio
import adafruit_pca9685
i2c = busio.I2C(board.SCL, board.SDA)

pca = adafruit_pca9685.PCA9685(i2c)
led_channel = pca.channels[15]
led_channel.duty_cycle = 0xffff
print("ok")
input()
