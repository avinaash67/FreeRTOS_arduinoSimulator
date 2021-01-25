#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>

//
int GPIO12 = 12; // select the pin for the LED
int GPIO13 = 13; // select the pin for the LED 

//Create Tasks
void vBlueLedControllerTask(void *param);
void vRedLedControllerTask(void *param);

//Create Task Handles
TaskHandle_t vBlueTaskHandle;
TaskHandle_t vRedTaskHandle;

void setup() {
  // Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);
  // Creating Tasks
  xTaskCreate(vBlueLedControllerTask, "TaskLed1", 100, NULL, 1, &vBlueTaskHandle);
  xTaskCreate(vRedLedControllerTask, "TaskLed2", 100, NULL, 1, &vRedTaskHandle);
  //vTaskDelay(1000/portTICK_PERIOD_MS);
  vTaskStartScheduler();
}

void vBlueLedControllerTask(void *pvParameters){
  while(1){
     
      Serial.println(" PIN 12 : BlUE LED TASK");
      DigitalWrite(GPIO12, HIGH);       // Arduino Simulator Code
      vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void vRedLedControllerTask(void *pvParameters){
  while(1){
      Serial.println(" PIN 13 :RED LED TASK");
      DigitalWrite(GPIO13, HIGH);       // Arduino Simulator Code
      vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
