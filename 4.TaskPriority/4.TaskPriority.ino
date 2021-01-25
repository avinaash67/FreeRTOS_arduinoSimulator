#include "SimulatorProgram.h"
#include <Arduino_FreeRTOS.h>

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Led pins
int GPIO10 = 10; // select the pin for the LED
int GPIO9 = 9; // select the pin for the LED 

//Create Tasks
void vLed10ControllerTask(void *param);
void vLed9ControllerTask(void *param);

//Create Task Handles
TaskHandle_t vTaskHandle10;
TaskHandle_t vTaskHandle9;

void setup() {
  // Simulator Serial Connection code  
  Serial.begin(9600);                           
  inString.reserve(10);

// set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  // Creating Tasks
  xTaskCreate(vLed10ControllerTask, "TaskLed1", 100, NULL, 1, &vTaskHandle10);
  xTaskCreate(vLed9ControllerTask, "TaskLed2", 100, NULL, 2, &vTaskHandle9);
  //vTaskDelay(1000/portTICK_PERIOD_MS);
  vTaskStartScheduler();
}

void vLed10ControllerTask(void *pvParameters){
  while(1){
    Serial.println(" PIN 10 : GPIO 10 HIGH");
    DigitalWrite(GPIO10, HIGH);                     // Arduino Simulator Code
    // Print a message to the LCD.
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 10 HIGH");                        // Arduino Simulator code  
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
    Serial.println(" PIN 10 : GPIO 10 LOW");
    DigitalWrite(GPIO10, LOW);                      // Arduino Simulator Code
    // Print a message to the LCD.
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 10 LOW");                         // Arduino Simulator code  
    vTaskDelay(1000/portTICK_PERIOD_MS);
      
  }
}

void vLed9ControllerTask(void *pvParameters){
  while(1){
    Serial.println(" PIN 9 : GPIO 9 HIGH");
    DigitalWrite(GPIO9, HIGH);                      // Arduino Simulator Code
    // Print a message to the LCD.
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 9 HIGH");                         // Arduino Simulator code   
    vTaskDelay(1000/portTICK_PERIOD_MS);
    
    Serial.println(" PIN 9 : GPIO 9 LOW");
    DigitalWrite(GPIO9, LOW);                        // Arduino Simulator Code
    // Print a message to the LCD.
    lcdsetCursor(2, 0);                             // Arduino Simulator code 
    lcdprint("PIN 9 LOW");                         // Arduino Simulator code  
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
