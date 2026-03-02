#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
int game;
#define TFT_CS     13
#define TFT_RST    8
#define TFT_DC     9
bool top;
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);

  tft.init(240, 240,SPI_MODE3); // Напиши свое разрешение экрана

  tft.setRotation(1); // если изображение перевернуто, смените значение на 3

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 100);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println("       Freddy");
  delay(1000);

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 100);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println("       Fazber");
top = true;
}

void loop() {
 if (top == true){
    game++;
  }
    if (game >= 180||top == false) {
      game--;
      top = false;
      if (game == 5){
        top = true;
      }
    }
    
    delay(10);

 tft.drawRect(game, 220, 67, 5, ST77XX_RED);
 delay(10);
 tft.drawRect(game,220,67,5,ST77XX_BLACK);
 tft.drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
}