
#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

//Create Tasks
void Task_ControlLed1(void *param);
void Task_ControlLed2(void *param);

//Create Task Handles
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

// Mutex variable
SemaphoreHandle_t myMutex;

void setup() { 

// Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);

  myMutex = xSemaphoreCreateMutex();
  
// Creating Tasks
xTaskCreate(Task_ControlLed1,"TaskLed1", 100, NULL, 1, &Task_Handle1);
xTaskCreate(Task_ControlLed2,"TaskLed2", 100, NULL, 1, &Task_Handle2);
}
 
void Task_ControlLed1(void *param){

  while(1){

      xSemaphoreTake(myMutex, portMAX_DELAY);
      
      Serial.println(" Task1");
      
       xSemaphoreGive(myMutex);
      
      vTaskDelay(1000/portTICK_PERIOD_MS);

      
  }
}

void Task_ControlLed2(void *param){

  while(1){

    xSemaphoreTake(myMutex, portMAX_DELAY);
    
    Serial.println(" Task2");
    
    xSemaphoreGive(myMutex);
    
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
   
  }
}

void loop() { 
  
// read the value from the sensor:
// sensorValue = AnalogRead(sensorPin);                
}
  
