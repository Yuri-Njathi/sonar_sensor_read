#include "mbed.h"

/**
    This source code is used to connect a MaxSonar detector. It is written to allow multiple sonar's. 
    If you want the sonar to constantly poll constantly either: don't attach the pin, or delete the code relating to 'Enable'
    
    This code is public domain.
**/

AnalogIn Sensor(A0);   //Analog port that is connected to the MaxSonar range detector
Serial serialPort(USBTX,USBRX);    //To talk back to your computer

int main() {
    float adc, volts, in;
    
    while (1) {        
        wait_us(25);//Wait 20uS + 5uS safety margin
        adc = Sensor.read();    //Read the sensor value
        volts = ( adc * 3.3 );          // convert to volts
        in = volts / 0.0032 * 0.3937;    // 3.3V supply: 3.2mV per cm * CM -> IN conversion factor
        
        serialPort.printf(" %8.2f \n", in);

        wait(0.5);
    }
}
