#include <Wire.h>
#include <stdio.h>
#include <SPI.h>


#define DEBUG 1

//############### PIN & HARDWARE definitions  ####################
#define SDA 18
#define SCL 5

#define HSPI_MISO 14
#define HSPI_MOSI 12
#define HSPI_CS 13
#define HSPI_CLK 15

#define VSPI_MISO 21
#define VSPI_MOSI 23
#define VSPI_CS 19
#define VSPI_CLK 22

#define LED_R 16
#define LED_G 4
#define LED_B 17

#define SWITCH 34
#define BUTTON_TRIGGER 35
#define BUTTON_MULTI 32

#define V_BATT 33 //Divider: (10.0+22.1)/22.1
#define RTC_INT 26

#define TMUX_Ref 25
#define TMUX_Z 27


#define I2C_Freq 100000
TwoWire I2C = TwoWire(0);

 
void setup()
{
  Serial.begin(115200);
  I2C.begin(SDA , SCL , I2C_Freq);
  
  pinMode(V_BATT, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_R, HIGH);
}
 
void loop()
{
  if(DEBUG) printf("Battery voltage: %lf\n", readBatteryVoltage());

  delay(500);

  
}

double readBatteryVoltage()
{
  return analogRead(V_BATT)/4095.0 * 3.3 * (10.0+22.1)/22.1;
}
