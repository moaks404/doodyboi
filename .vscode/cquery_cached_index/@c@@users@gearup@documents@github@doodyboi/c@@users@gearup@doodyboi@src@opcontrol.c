#include "main.h"
#include "portdef.h"


void operatorControl() {
  int left_speed = 0; // variabels to hold the speed from joysticks
  int right_speed = 0;

  while (1) { // read remote control forever
    // connect the joysticks to the left and right speed varibale to set te set
    // speed for the motors subsequently
    right_speed = joystickGetAnalog(1, 2); // vertical axis on right joystick
    left_speed = joystickGetAnalog(1, 3);  // vertical axis on left joystick

    int lift_speed = 75;
		if(joystickGetDigital(1,6, JOY_UP)) {
            motorSet(LEFT_M_ARM, lift_speed);
            motorSet(RIGHT_M_ARM, -lift_speed);
            printf("in 6 JOY_UP \n");
    }
    else if(joystickGetDigital(1,6, JOY_DOWN)) {
            motorSet(LEFT_M_ARM, -lift_speed);
            motorSet(RIGHT_M_ARM, lift_speed);
    }
    else {
            motorSet(LEFT_M_ARM, 0);
            motorSet(RIGHT_M_ARM, 0);
    }
    // connect the joystick movement ot he motor groups, we have two left and
    // two right
    // motors.  the right motors are mirrored (does reveresed) from the left
    // motor
    motorSet(LEFT_M_FRONT, left_speed);    // set left motor speed
    motorSet(LEFT_M_BACK, left_speed);     // set left motor speed
    motorSet(RIGHT_M_FRONT, -right_speed); // set right motor speed
    motorSet(RIGHT_M_BACK, -right_speed);
    delay(20); // give cortex time to set the motors speed
  }
}
