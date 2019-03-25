// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
const int buttonPin = 4;   
const int buttonPin1 = 5;     
const int ledPin =  3;     
int motorPin =  6;     
int motorSpeed =  0;     
int buttonState = 0;
int buttonState1 = 0;
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(motorPin, OUTPUT);
  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  
 
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0));  

  motorSpeed = map(1000, 0,1023, 0, 255);
  Serial.print(motorSpeed);
  analogWrite(motorPin, motorSpeed);
   buttonState = digitalRead(buttonPin);
   buttonState1 = digitalRead(buttonPin1);
   if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else if(buttonState1 == HIGH){
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
