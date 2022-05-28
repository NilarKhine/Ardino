// Bluetooth Tutorial By Robo India
// Bluetooth module used - HC-06
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(2, 3); // (TXD, RXD) of HC-06
Servo myservo;

int pos = 0;
char BT_input; // to store input character received via BT.

void setup()  
{

  BlueTooth.begin(9600); 
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object
  pinMode(13,OUTPUT); 
}

void loop() 
{
  if (BlueTooth.available()>0)
 
  {
    BT_input=(BlueTooth.read());
    if (BT_input=='c'){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);  // waits 15ms for the servo to reach the position
    Serial.println("clockwise");
  }
    }
  
   
    else if (BT_input=='d'){
   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
   Serial.println("counterclockwise");
  }
    }
  }
   else if (BT_input=='?')
    {
      BlueTooth.println("Send 'c' to turn LED ON");
      BlueTooth.println("Send 'd' to turn LED OFF");
    }   
   // You may add other if else condition here. 
  } 




