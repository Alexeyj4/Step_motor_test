#include <GyverStepper.h>
// ULN2003 Motor Driver Pins:
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

GStepper<STEPPER4WIRE> stepper(stepsPerRevolution, IN4, IN2, IN3, IN1);
// мотор с драйвером ULN2003 подключается по порядку пинов, но крайние нужно поменять местами
// то есть у меня подключено D2-IN1, D3-IN2, D4-IN3, D5-IN4, но в программе поменял 5 и 2

void setup() {
  Serial.setTimeout(100000);
  Serial.begin(115200);
  // режим следования к целевй позиции
  stepper.setRunMode(FOLLOW_POS);
  // установка макс. скорости в шагах/сек
  stepper.setMaxSpeed(400);
  // установка ускорения в шагах/сек/сек
  stepper.setAcceleration(500);   
}

void loop() {

  // график положения
  static uint32_t tmr2;
  if (millis() - tmr2 > 20) {
    tmr2 = millis();
    Serial.println(stepper.getCurrent());
  }
}
