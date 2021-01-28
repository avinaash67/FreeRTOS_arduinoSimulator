#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>
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
  
