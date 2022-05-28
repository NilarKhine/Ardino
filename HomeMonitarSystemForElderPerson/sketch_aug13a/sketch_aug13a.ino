
#include <Stepper.h>
#include <SoftwareSerial.h>

#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048 
const int stepsPerRevolution = 600;  // change this to fit the number of steps per revolution
// for your motor
SoftwareSerial BlueTooth(2, 3); // (TXD, RXD) of HC-06
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 4, 6, 5, 7);

/*-----( Declare Variables )-----*/
int  Steps2Take;
char BT_input; // to store input character received via BT.

int stepCount = 6;  // number of steps the motor has taken


void setup() {
  // put your setup code here, to run once:
 BlueTooth.begin(9600); 
 Serial.begin(9600);
  myStepper1.setSpeed(10);
  pinMode(A1,OUTPUT);
 
   
}
//Start light system
void loop() 
{
  if (BlueTooth.available())
 
  {
    BT_input=(BlueTooth.read());
    if (BT_input=='a')
    {
      digitalWrite(A1, HIGH);
      BlueTooth.println("Now LED is ON");
    }
    else if (BT_input=='b')
    {
      digitalWrite(A1, LOW);
      BlueTooth.println("Now LED is OFF");
    }
   else if (BT_input=='?')
    {
      BlueTooth.println("Send 'a' to turn LED ON");
      BlueTooth.println("Send 'b' to turn LED OFF");
    }   
    if (BT_input=='e'){
 // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper1.step(stepsPerRevolution);
 
    }
  
  else if (BT_input=='f'){
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper1.step(-stepsPerRevolution);
  
}
 else if (BT_input=='?')
    {
      BlueTooth.println("Send 'e' to the upstair");
      BlueTooth.println("Send 'f' to the down stair");
    }
    if (BT_input=='c')
    {
  Steps2Take  =  STEPS_PER_OUTPUT_REVOLUTION ;  // Rotate CW 1 turn
  small_stepper.setSpeed(500);   
  small_stepper.step(Steps2Take);
  delay(1000);
    }
  else if (BT_input=='d')
    {
  Steps2Take  =  - STEPS_PER_OUTPUT_REVOLUTION;  // Rotate CCW 1 turn  
  small_stepper.setSpeed(500);  // 700 a good max speed??
  small_stepper.step(Steps2Take);
  delay(2000);
    }
    else if (BT_input=='?')
    {
      BlueTooth.println("Send 'a' to turn LED ON");
      BlueTooth.println("Send 'b' to turn LED OFF");
    }   
   // You may add other if else condition here. 
  }

}
 
  
