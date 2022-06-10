#include <CapacitiveSensor.h>


CapacitiveSensor ledCapSensor = CapacitiveSensor(4,2); //*Defining the sensor used for the led lights
CapacitiveSensor   buzzCapSensorA = CapacitiveSensor(4,3); //*Defining the sensor used for the A strip of the painting        
CapacitiveSensor   buzzCapSensorB = CapacitiveSensor(4,5); //*Defining the sensor used for the B strip of the painting
CapacitiveSensor   buzzCapSensorC = CapacitiveSensor(4,6); //*Defining the sensor used for the C strip of the painting
CapacitiveSensor   buzzCapSensorD = CapacitiveSensor(4,7); //*Defining the sensor used for the D strip of the painting

int ledthreshold = 1000;//* The specific threshold that has to be passed for the led pins to light up 
int thresholdA = 100; //* The specific threshold that has to be passed for the sound to play
int thresholdB = 200;
int thresholdC = 500;
int thresholdD = 1000;

const int buzzer = 9; 
const int ledPin = 12;

void setup(){
  Serial.begin(9600);
   pinMode(buzzer, OUTPUT); //* Defining the buzzer as the output
   pinMode(ledPin, OUTPUT); //* Defining the led pin as the output
}

void loop()
{

LightPins(); //*When the sensor is touched the led pins turn on
playA(); //*When the sensor is touched the "A" tone is played 
playB(); //*When the sensor is touched the "B" tone is played 
playC(); //*When the sensor is touched the "C" tone is played 
playD(); //*When the sensor is touched the "D" tone is played 
  
}


int LightPins () 
{
long sensorValue = ledCapSensor.capacitiveSensor(30);
Serial.println(sensorValue);
//Touch detected
if (sensorValue > ledthreshold) {
//Turn on the led
digitalWrite(ledPin, HIGH);
}
//Touch undetected
else {
//Turn off the led
digitalWrite(ledPin, LOW);
}
delay(10);
}

int playA ()
{
 long sensorValueA = buzzCapSensorA.capacitiveSensor(30);
  Serial.println(sensorValueA);
  if(sensorValueA > thresholdA) { //*If the sensor value received from the Capacitive Sensor is bigger than the specific threshold, the sound is played
    tone(buzzer, 800); //* Setting the tone of the buzzer for the A section
  }
}


int playB ()
{
long sensorValueB = buzzCapSensorB.capacitiveSensor(30);
  Serial.println(sensorValueB);
  if(sensorValueB > thresholdB) { 
    tone(buzzer, 1000); //* Setting the tone of the buzzer for the B section
  }
}


int playC ()
{
long sensorValueC = buzzCapSensorC.capacitiveSensor(30);
  Serial.println(sensorValueC);
  if(sensorValueC > thresholdC) {
    tone(buzzer, 600); //* Setting the tone of the buzzer for the C section
  }
}

int playD ()
{
  long sensorValueD = buzzCapSensorD.capacitiveSensor(30);
  Serial.println(sensorValueD);
  if(sensorValueD > thresholdD) {
    tone(buzzer, 400); //* Setting the tone of the buzzer for the D section
  }
}
