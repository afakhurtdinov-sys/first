#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
bool hopl;
bool trigger;
int top = 7;
int xDest = 1, yDest = 1;
int game;
int dom;
bool town = true;
int X, Y;
#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9

Adafruit_ST7789 tft = Adafruit_ST7789(-1, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);

  pinMode(top, INPUT);
  tft.init(240, 240, SPI_MODE3);  // Напиши свое разрешение экрана
  tft.setRotation(1);  // если изображение перевернуто, смените значение на 3
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 100);
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(5);
  tft.println("Artem camiy cladki pupusik");
  delay(1000);

  tft.fillScreen(0x565);
  tft.setCursor(10, 100);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(6);
  tft.println("I love bananas");
  X = 90;
  Y = 10;
  hopl = true;
  trigger = true;
}
void loop() {
 sharik();
}
void sharik(){
  tft.fillCircle(X, Y, 20, ST77XX_RED);
  delay(10);
  tft.fillCircle(X, Y, 20, 0x565);
  tft.drawRect(game, 220, 67, 5, ST77XX_RED);
  delay(10);
  tft.drawRect(game, 220, 67, 5, 0x565);
  if (hopl == true) {
    Y++;
  } else {
    Y--;
  }
  if (Y == 0) {
    hopl = true;
  }
  if (Y == 240) {
    hopl = false;
  }
  if (X >= 240) {
    trigger = false;
  }
  if (trigger == true) {
    X = X + 7;
  } else {
    X = X - 7;
  }
  if (X <= 0) {
    trigger = true;
  }

  dom = digitalRead(top);
  if (dom > 0) {
    if (town == true ) {
      game = game + 10;
    }
    if (town == false ) {
      game = game - 10;
    }
    
  
  if (game == 180) {
    town = false;
  }
  if (game == 0) {
    town = true;
  }
  }
  Serial.print(dom);
  Serial.println(dom);
}