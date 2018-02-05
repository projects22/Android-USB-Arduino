/*
 * Android to Arduino
 * 
 *  
*/

unsigned char inByte=0, outByte=48;         //

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    // initialize outputs 8-11 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
    
   if (Serial.available() > 0) {
          // read the incoming byte:
        inByte = Serial.read();
        PORTB = inByte; //update digital outputs 8-11
 
        delay(100);
        outByte = 48 + (unsigned char)digitalRead(2) + ((unsigned char)digitalRead(3)<<1) + ((unsigned char)digitalRead(4)<<2) + ((unsigned char)digitalRead(5)<<3);  //read inputs on pins 2-5
        Serial.write(outByte);
 
   }
     
  delay(900);
}


