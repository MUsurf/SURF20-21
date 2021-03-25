/*
 * Known working settings:
 * Board:      Teensy 4.1
 * MCU Freq:   720MHz
 * Optimizer:  Fastest, Faster
 * Result: 860~875kS/s
 * 
 * This doesnt result in exactly 1MS/s, but it should still be plenty for the 25kHz-40kHz
 * range of signals we are looking for anyways. If you really wanted to get as close to 1MS/s
 * As you could, you should probably drop the SPI library altogether and program every piece.
 * Also overclocking a bit helps, however much higher than 720MHz you will probably want a heatsink.
 */


#include <SPI.h>

#define CS_PIN 10
#define MAX_BUFF_SIZE 4096

// Scope tested for this value. This is probably only valid for the settings used in the comments. 
// If you start getting weird spikes in the data, increase this time until it goes away
#define WAIT_TIME 560

int16_t result = 0;
int16_t buff[MAX_BUFF_SIZE] = {0};

SPISettings hydrophoneA(60000000, MSBFIRST, SPI_MODE1);  // 60MHz, MSB first, Read data on falling edge of SCLK. SPI mode may be wrong. try 0 if not 1

FASTRUN void printBuff();
FASTRUN inline void fillBuff() __attribute__((always_inline));

void setup() {
    Serial.begin(9600);

    pinMode(CS_PIN, OUTPUT);
    digitalWriteFast(CS_PIN, LOW); // Disable on start
    SPI.begin();

    delay(200); // Probably should recalibrate here
}
FASTRUN void loop() {
    fillBuff();

    printBuff();

    delay(1000);  
}


void fillBuff() {
    noInterrupts();
    for(uint16_t i = 0; i < MAX_BUFF_SIZE; i++) {
        digitalWriteFast(CS_PIN, HIGH); // Initiate conversion start
        SPI.beginTransaction(hydrophoneA);
        delayNanoseconds(WAIT_TIME);
        
        digitalWriteFast(CS_PIN, LOW); // Enable the ADC output
        
        buff[i] = SPI.transfer16(0x00); // Just send a zero since ADC doesn't actually read data from MCU;
        SPI.endTransaction();
    }
    interrupts();
}

// Use serial monitor to view the waveform
void printBuff() {
    for(uint16_t i = 0; i < MAX_BUFF_SIZE; i++) {
        Serial.println(buff[i]);
    }
}
