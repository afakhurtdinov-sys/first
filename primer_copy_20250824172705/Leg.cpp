#include <Servo.h>


class Leg {;
  Servo servo1;
  Servo servo2;
  Servo servo3;
  uint64_t lastRunTime;
  int delayForMoving;
  int gradusPort1;
  int gradusPort2;
  int mona;
  int lisa;
public:
  Leg(int port1, int port2) {
    servo1.attach(port1);
    servo2.attach(port2);
    servo1.write(0);
      servo2.write(0);
    delayForMoving = 50;
    mona = 1;
    lisa = 1;
    gradusPort1 = 0;
    gradusPort2 =0;
  }



  void Run(uint64_t millis) {
  
    if (millis - lastRunTime > delayForMoving) {
          lastRunTime = millis;
      switch (mona) {
        case 1:
          gradusPort1++;
          if (gradusPort1 >= 25) {
            mona = 2;
          }
          break;
        case 2:
          gradusPort1--;
          if (gradusPort1 <= 0) {
            mona = 3;
          }
          break;
        case 3:
          break;
      }
      switch (lisa) {
        case 1:
          gradusPort2++;
          if (gradusPort2 >= 45) {
            lisa = 2;
          }
          break;
        case 2:
          gradusPort2--;
          if (gradusPort2 <= 0) {
            lisa = 3;
          }
          break;
          case 3:
          break;
      }
      servo1.write(gradusPort1);
      servo2.write(gradusPort2);
     
    }
  }
};