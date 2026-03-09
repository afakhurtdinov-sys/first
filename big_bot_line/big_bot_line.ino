
#define SPEED_1 5
#define DIR_1 4
#define SPEED_2 6
#define DIR_2 7
int svet1;
int svet2;
const int speed_all = 70;
unsigned long previousMillis = 0;
const long interval = 1000;
void setup() {
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  // настраиваем выводы платы 4, 5, 6, 7 на вывод сигналов
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  vpered();
}
void vpered() {
  digitalWrite(DIR_2, 0);
  analogWrite(SPEED_2, speed_all);  //левое не
  analogWrite(SPEED_1, speed_all);
  digitalWrite(DIR_1, 0);
  //правое не
}
void nalevo() {
  digitalWrite(DIR_2, 0);    //налево
  analogWrite(SPEED_2, speed_all);  //левое не
  digitalWrite(DIR_1, 1);
  analogWrite(SPEED_1, 0);  //правое не
  //delay(1200);
}
void vpravo() {
  digitalWrite(DIR_2, 1);   //налево
  analogWrite(SPEED_2, 0);  //левое не
  digitalWrite(DIR_1, 0);
  analogWrite(SPEED_1, speed_all);  //правое не
  //delay(1200);
}
void stop1() {
  digitalWrite(DIR_2, 0);   //налево
  analogWrite(SPEED_2, 0);  //левое не
  digitalWrite(DIR_1, 0);
  analogWrite(SPEED_1, 0);  //правое не
}
void loop() {
  svet1 = analogRead(A1);
  svet2 = analogRead(A2);
  // Определение порогового значения (может потребоваться подстройка)
  int thr = 35;
  if (svet1 > thr && svet2 > thr) {
    stop1();
  }
  if (svet1 > thr && svet2 < thr) {
    analogWrite(SPEED_2, speed_all);  //левое не
    analogWrite(SPEED_1, speed_all);
  }
  if (svet1 < thr && svet2 > thr)
    // Небольшая задержка для стабильности
    delay(10);
  Serial.print(svet1);
  Serial.println();
  Serial.print(svet2);
  Serial.println();
}