/*
 * Known working settings:
 * Board:      Teensy 4.1
 * MCU Freq:   720MHz
 * Optimizer:  Fastest
 * 
 * 
 * This doesnt result in exactly 1MS/s, but it should still be plenty for the 25kHz-40kHz
 * range of signals we are looking for anyways. This should be about 747kS/s
 * If you really wanted to get as close to 1MS/s
 * As you could, you should probably drop the SPI library altogether and program every piece.
 * Also overclocking a bit helps, however much higher than 720MHz you will probably want a heatsink.
 */


#include <SPI.h>

#define CS_PIN 10
#define MAX_BUFF_SIZE 8192

// ADC Timings in ns for 1Msps
#define T_CYCLE  1000
#define T_ACQ    290 // T_QUIET and T_EN included in here @DVIO = 3.3V
#define T_QUIET  (10)
#define T_EN     10
// Scope tested for the 30ns offset
#define T_CNV    (710 + 30)

int16_t buff[MAX_BUFF_SIZE] = {0};

void printBuff();
void fillBuff();
int16_t readHydrophone();

void setup() {
    Serial.begin(9600);

    pinMode(CS_PIN, OUTPUT);
    digitalWriteFast(CS_PIN, LOW); // Disable on start
    SPI.begin();

    delay(200); // Probably should recalibrate here
}

void loop() {
    fillBuff();

    printBuff();

    delay(1000);  
}

// ADC Outputs a 16 bit binary twos complement.
int16_t readHydrophone() {
    static int16_t result = 0;
    
    SPI.beginTransaction(SPISettings(60000000, MSBFIRST, SPI_MODE1));  // 60MHz, MSB first, Read data on falling edge of SCLK. SPI mode may be wrong. try 0 if not 1
    //delayNanoseconds(T_QUIET);
    digitalWriteFast(CS_PIN, HIGH); // Initiate conversion start
    delayNanoseconds(T_CNV);
    
    digitalWriteFast(CS_PIN, LOW); // Enable the ADC output
    //delayNanoseconds(T_EN);
    
    result = SPI.transfer16(0x00); // Just send a zero since ADC doesn't actually read data from MCU
    SPI.endTransaction();
    
    //delayNanoseconds(T_QUIET);
  
    return result;
}


void fillBuff() { // Should probably not use the global var here but oh well
    for(uint16_t i = 0; i < MAX_BUFF_SIZE; i++) {
        buff[i] = readHydrophone();
    }
}

// Use serial monitor to view the waveform
void printBuff() { // Should probably not use the global var here but oh well
    for(uint16_t i = 0; i < MAX_BUFF_SIZE; i++) {
        Serial.println(buff[i]);
    }
}
