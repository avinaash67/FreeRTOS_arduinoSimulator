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
int counter = 0; // Declaring a global counter

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
  
// Creating Tasks
xTaskCreate(Task_ControlLed1,"TaskLed1", 100, NULL, 1, &Task_Handle1);
xTaskCreate(Task_ControlLed2,"TaskLed2", 100, NULL, 1, &Task_Handle2);
}
 
void Task_ControlLed1(void *param){

  while(1){
      counter++;
      Serial.print(counter);
      Serial.println(" Task1");
      vTaskDelay(1000/portTICK_PERIOD_MS);

      if(counter ==15){
        vTaskResume(Task_Handle2);
      }
  }
}

void Task_ControlLed2(void *param){

  while(1){
    counter++;
    Serial.print(counter);
    Serial.println(" Task2");
    vTaskDelay(1000/portTICK_PERIOD_MS);

    if (counter == 5){
      vTaskSuspend(Task_Handle2);
    }
  }
}


void loop() { 
  
// read the value from the sensor:
// sensorValue = AnalogRead(sensorPin);                
}
  
