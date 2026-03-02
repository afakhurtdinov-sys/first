#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Arduino.h>
#include <SensirionI2cScd30.h>
#include <Wire.h>
#include "IRremote.h"
SensirionI2cScd30 sensor;
IRrecv irrecv(2);
decode_results results;
static char errorMessage[128];
static int16_t error;
#define TFT_CS 11
#define TFT_RST 8
#define TFT_DC 9
int j = 0;
int t= 0;
Adafruit_ST7789 tft = Adafruit_ST7789(-1, TFT_DC, TFT_RST);


void setup() {
  tft.init(240, 240, SPI_MODE3);
  tft.setRotation(1);
  Serial.begin(9600);
  Wire.begin();
  sensor.begin(Wire, SCD30_I2C_ADDR_61);
  irrecv.enableIRIn();
  sensor.stopPeriodicMeasurement();
  sensor.softReset();
  error = sensor.startPeriodicMeasurement(0);
  if (error != NO_ERROR) {
    Serial.print("Error trying to execute startPeriodicMeasurement(): ");
    errorToString(error, errorMessage, sizeof errorMessage);
    Serial.println();
    Serial.print(errorMessage);
    return;
  } else {
    Serial.println();
    Serial.print("Нет ошибки");
  }
}
float co2Concentration = 0.0;
float temperature = 0.0;
float humidity = 0.0;
void loop() {
  if (irrecv.decode(&results)) {
   
    if (results.value == 0x1689906F) {
      Serial.print("Нажата кнопка температуры: ");
      Serial.println(results.value, HEX);


      error = sensor.blockingReadMeasurementData(co2Concentration, temperature, humidity);
      tft.fillScreen(ST77XX_WHITE);
      tft.fillCircle(120, 120, 100, ST77XX_BLACK);
      tft.fillCircle(120, 120, 80, ST77XX_RED);
      tft.fillCircle(120, 120, 60, ST77XX_YELLOW);

      tft.setCursor(50, 100);
      tft.setTextColor(ST77XX_BLUE);
      tft.setTextSize(5);
      tft.println(temperature);
    }
    if (results.value == 0x1689A05F){
       Serial.print("Нажата кнопка влажности: ");
      Serial.println(results.value, HEX);


      error = sensor.blockingReadMeasurementData(co2Concentration, temperature, humidity);
       tft.fillScreen(ST77XX_WHITE);
      tft.fillCircle(120, 120, 100, ST77XX_BLACK);
      tft.fillCircle(120, 120, 80, ST77XX_RED);
      tft.fillCircle(120, 120, 60, ST77XX_YELLOW);
      tft.setCursor(50, 100);
      tft.setTextColor(ST77XX_BLUE);
      tft.setTextSize(5);
      tft.println(humidity);
    }
    if (results.value == 0x168940BF){
       Serial.print("Нажата кнопка CO2: ");
      Serial.println(results.value, HEX);


      error = sensor.blockingReadMeasurementData(co2Concentration, temperature, humidity);
      tft.fillScreen(ST77XX_WHITE);
      tft.fillCircle(120, 120, 100, ST77XX_BLACK);
      tft.fillCircle(120, 120, 80, ST77XX_RED);
      tft.fillCircle(120, 120, 60, ST77XX_YELLOW);
      tft.setCursor(50, 95);
      tft.setTextColor(ST77XX_BLUE);
      tft.setTextSize(4);
      tft.println(co2Concentration);
    }
    irrecv.resume();
  }
}
