#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>

//


//Create Tasks
void vLedControllerTask(void* param);
//void vIdleTask(void* param);

//Create Task Handles
//TaskHandle_t vBlueTaskHandle;
//TaskHandle_t vRedTaskHandle;

void setup() {
  // Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);
  
  uint8_t* GPIO10 = 10; // select the pin for the LED
  uint8_t* GPIO9 = 9; // select the pin for the LED 
  
  // Creating Tasks
  //xTaskCreate(vIdleTask, "IdleTask", 10, NULL, 0, NULL);
  //xTaskCreate(vLedControllerTask, "TaskLed1", 100, (void*)GPIO10, 1, NULL);
  xTaskCreate(vLedControllerTask, "TaskLed2", 100, (void*)GPIO9, 1, NULL);

  Serial.println("Tasks are created");
  //delay(100);
  vTaskStartScheduler();
}

void vLedControllerTask(void* pvParameters){
  //uint8_t a = *((uint8_t*)pvParameters);
  //uint8_t a = (uint8_t)pvParameters;
  while(1){
    Serial.println((uint8_t)pvParameters);  
    DigitalWrite((uint8_t)pvParameters, HIGH);       // Arduino Simulator Code
    vTaskDelay(1000/portTICK_PERIOD_MS);
    DigitalWrite((uint8_t)pvParameters, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}

//void vIdleTask(void* pvParameters){
//  while(1){
//    Serial.println("Idle Task");
//    vTaskDelay( 10/ portTICK_PERIOD_MS );
//  }
//}

void loop() {
  // put your main code here, to run repeatedly:

}
