#define SPEED_1      5
#define DIR_1        4
#define SPEED_2      6
#define DIR_2        7

int svet1;
int svet2;
void setup() {
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);

  // настраиваем выводы платы 4, 5, 6, 7 на вывод сигналов
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

  void vpered() {
    digitalWrite(DIR_2, 0);
    analogWrite(SPEED_2, 120);//левое не
    digitalWrite(DIR_1, 0);
    analogWrite(SPEED_1, 115); //правое не
    delay(2000);
  }
  void nalevo() {
    digitalWrite(DIR_2, 0); //налево
    analogWrite(SPEED_2, 115);//левое не
    digitalWrite(DIR_1, 1);
    analogWrite(SPEED_1, 0); //правое не
    delay(1200);
  }
  void vpravo() {
    digitalWrite(DIR_2, 1); //налево
    analogWrite(SPEED_2, 0);//левое не
    digitalWrite(DIR_1, 0);
    analogWrite(SPEED_1, 115); //правое не
    delay(1200);
  }
  void stop1() {
    digitalWrite(DIR_2, 0); //налево
    analogWrite(SPEED_2, 0);//левое не
    digitalWrite(DIR_1, 0);
    analogWrite(SPEED_1, 0); //правое не
    delay(2000);
  }

void loop() {
  vpered();
  vpravo();
  
  nalevo();
  stop1();
}
