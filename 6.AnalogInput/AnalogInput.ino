//*****************************************************************************************************************************************************************************************
//***************************************************************************  Arduino Simulator Drag & Draw  *****************************************************************************
//*******************************************************************  Copyright by Marc Van Den Berge and Louis D'hont  ******************************************************************
//*****************************************************************************************************************************************************************************************

#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>

/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin1 = 12; // select the pin for the LED
int ledPin2 = 13; // select the pin for the LED 
//int sensorValue = 0;  // variable to store the value coming from the sensor
int button1 = 7; // select the pin for button
int button2 = 8; // select the pin for button

//Create Tasks
void Task_ControlLed1(void *param);
void Task_ControlLed2(void *param);

//Create Task Handles
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

void setup() { 

// Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);

// declare the ledPin as an OUTPUT:
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 

// declare the button pin as INPUT
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT); 
  
// Creating Tasks
xTaskCreate(Task_ControlLed1,"TaskLed1", 100, NULL, 1, &Task_Handle1);
xTaskCreate(Task_ControlLed2,"TaskLed2", 100, NULL, 1, &Task_Handle2);
 }
 
void loop() { 
  
// read the value from the sensor:
// sensorValue = AnalogRead(sensorPin);                
}

void Task_ControlLed1(void *param){

  while(1){
    if(DigitalRead(button1) > 0){
      //while(digitalRead(button1) > 0){
        DigitalWrite(ledPin1, HIGH);       // Arduino Simulator Code
        digitalWrite(ledPin1, HIGH);     // Original code
        Serial.println("button1 Pressed");
      //}
    }
    else{
      DigitalWrite(ledPin1, LOW);       // Arduino Simulator Code
      digitalWrite(ledPin1, LOW);     // Original code
      Serial.println("button1 Released");
    }
     vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void Task_ControlLed2(void *param){

  while(1){
    if(DigitalRead(button2) == 1){
      //while(digitalRead(button2) == 1){
        DigitalWrite(ledPin2, HIGH);       // Arduino Simulator Code
        digitalWrite(ledPin2, HIGH);     // Original code
        Serial.println("button2 Pressed");
      //}
    }
    else{
      DigitalWrite(ledPin2, LOW);       // Arduino Simulator Code
      digitalWrite(ledPin2, LOW);     // Original code
      Serial.println("button2 Released");
    } 
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
  
