#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Led pins
int GPIO10 = 10; // select the pin for the LED
int GPIO9 = 9; // select the pin for the LED 
int GPIO8 = 8; // select the pin for the LED 
//Create Tasks
void vGPIO10ControllerTask(void *param);
void vGPIO9ControllerTask(void *param);
void vGPIO8ControllerTask(void *param);

//Create Task Handles
TaskHandle_t vTaskHandle10;
TaskHandle_t vTaskHandle9;
TaskHandle_t vTaskHandle8;

void setup() {
  // Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);

// set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  // Creating Tasks
  xTaskCreate(vGPIO10ControllerTask, "GPIO10", 100, NULL, 1, &vTaskHandle10);
  xTaskCreate(vGPIO9ControllerTask, "GPIO9", 100, NULL, 2, &vTaskHandle9);
  xTaskCreate(vGPIO8ControllerTask, "GPIO8", 100, NULL, 3, &vTaskHandle8);

  //vTaskDelay(1000/portTICK_PERIOD_MS);
  vTaskStartScheduler();
}

void vGPIO10ControllerTask(void *pvParameters){
  while(1){
    // Print a message to the LCD.
    lcdclear();
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 10 Active");                        // Arduino Simulator code  
    vTaskDelay(1000/portTICK_PERIOD_MS);      
  }
}

void vGPIO9ControllerTask(void *pvParameters){
  while(1){
    // Print a message to the LCD.
    lcdclear();
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 9 Active");                         // Arduino Simulator code   
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}


void vGPIO8ControllerTask(void *pvParameters){
  while(1){
    // Print a message to the LCD.
    lcdclear();
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 8 Active");                         // Arduino Simulator code   
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}



void loop() {
  // put your main code here, to run repeatedly:

}
