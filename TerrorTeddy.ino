/*
 * Code written by Wessel Bakker
 * Group 9 - sprint 1 CMGT year 1
 */
#include <Servo.h>
int sensorPin = A0; // select the input pin for LDR
int redLight = 13; //select output pin for LED
int sensorValue = 0; // variable to store the value coming from the sensor
int dwaarde;   //initialize threshold value
Servo servo;   //initialize servo

void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(redLight, OUTPUT); //sets port for LED as output
servo.attach(8);   //connects the servo to a pin
sensorValue = analogRead(sensorPin); 
dwaarde = sensorValue -30;    //sets threshold value to current light intensity
servo.write(0);
}

void loop() {
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the serial monitor

if(sensorValue<dwaarde){
  digitalWrite(redLight, HIGH); //turn on red eyes
  mouth(); //run code to move the mouth
}else{
  digitalWrite(redLight, LOW); //turn off eyes
}
  delay(100);
}

//this controls the movement of the mouth
void mouth() {
  int angle;
  int position;
  int minAngle = 0; //the furthest the servo move one way (0-180)
  int maxAngle = 20; //the furthest the servo moves the other way (0-180)

  //mouth opens
  for(int angle=minAngle; angle<=maxAngle && position==0; angle = angle+1){ //to open the mouth slower than usual
   servo.write(angle);
   delay(5); 
  }
  position = 1;
  delay(100);

  //mouth closes
  for(int angle=maxAngle; angle>=minAngle && position==1; angle = angle-1){ //to close the mouth slower than usual
  servo.write(angle);
  delay(5);
  }
  position = 0;
}

