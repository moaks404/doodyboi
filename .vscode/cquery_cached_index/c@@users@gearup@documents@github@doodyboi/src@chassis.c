#include "main.h"
#include "portdef.h"
#include "chassis.h"

 void driveForDistancePID(int distance, int speed) {
  //use pd to drive straight forever
  float wheelCircum = 4 * 3.14;
  int motorDegree = (distance / wheelCircum) * 360;
  int totalTicks = 0;
  int slavePower = speed - 5;
  int error = 0;
  int kp = 5;

  // reset the encoders.
  encoderReset(encoderLM);
  encoderReset(encoderRM);
  //Repeat ten times a seconds
  while(abs(totalTicks) < motorDegree)
  {
    //Set the motor powers to their respective variables.
    motorSet(LEFT_M_FRONT, speed);
    motorSet(LEFT_M_BACK, speed);
    motorSet(RIGHT_M_BACK, -slavePower);
    motorSet(RIGHT_M_FRONT, -slavePower);
    error = encoderGet(encoderLM) - encoderGet(encoderRM);
    slavePower += error / kp;
    //reset the encoders every loop.
    wait(100);
    totalTicks+= encoderGet(encoderLM);
  }
motorSet(LEFT_M_FRONT, 0);
motorSet(LEFT_M_BACK, 0);
motorSet(RIGHT_M_FRONT, 0);
motorSet(RIGHT_M_BACK, 0);
}
