/*
 * Android to Arduino
 * by moty22.co.uk
 * 26/4/20
 *  
*/

#include <OneWire.h>
#include <DallasTemperature.h>

unsigned char inByte=0, outByte;         //
byte tempB[8];

#define ONE_WIRE_BUS A5  // Data wire is plugged into pin A5 on the Arduino

OneWire oneWire(A5);    // Setup a oneWire instance to communicate with any OneWire devices 
DallasTemperature sensors(&oneWire);    // Pass our oneWire reference to Dallas Temperature.

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  sensors.begin();    //ds18b20
    // initialize outputs 8-11 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //for switches pullup inputs
//  pinMode(2, INPUT_PULLUP);
//  pinMode(3, INPUT_PULLUP);
//  pinMode(4, INPUT_PULLUP);
//  pinMode(5, INPUT_PULLUP);
}

void loop() {
  
        delay(500);

         sensors.requestTemperatures(); // Send the command to get temperatures
         float temp = sensors.getTempCByIndex(0);
         int tempInt=(int)(temp*100.0);
    
        Serial.write((unsigned char)digitalRead(2));    //send inputs
        Serial.write((unsigned char)digitalRead(3));
        Serial.write((unsigned char)digitalRead(4));
        Serial.write((unsigned char)digitalRead(5));
        
        Serial.write(lowByte(analogRead(A0)));  //send low byte of 10 bits analogue read
        Serial.write(highByte(analogRead(A0))); //send high byte of 10 bits analogue read
        Serial.write(lowByte(analogRead(A1)));
        Serial.write(highByte(analogRead(A1)));

        Serial.write(lowByte(tempInt));     //send temperature
        Serial.write(highByte(tempInt));

        delay(500);
           
        if (Serial.available() > 0) {
            // read the incoming byte:
          inByte = Serial.read();
          PORTB = inByte; //update digital outputs 8-11

       }
     
      
}


