#ifndef _portDef_H_
#define _portDef_H_
// Create all the port defintions in one place for easy trouble shooting
#include "main.h"

// ---------- Motor Port Assignments -----------------------------------
#define LEFT_M_FRONT 2 // cortex port for motor - left motor front on port 2
#define LEFT_M_BACK 3
#define RIGHT_M_FRONT 6 // cortex port for motor - right motor front on port 6
#define RIGHT_M_BACK 9
#define RIGHT_M_ARM 4
#define LEFT_M_ARM 5

// ----------- Digital Ports ------------------------------------------
// Drive train encoders
#define QUAD_TOP_LM_PORT 1
#define QUAD_BOTTOM_LM_PORT 2
#define QUAD_TOP_RM_PORT 3
#define QUAD_BOTTOM_RM_PORT 4

// Lift encoders
//#define QUAD_TOP_LIFT_PORT 5
//#define QUAD_BOTTOM_LIFT_PORT 6

// ----------- Is DEBUGGING ON ---------------------------------------
#define DEBUG_ON true
#define VEXNET_MANUAL false        // turns opcontrol into allowing for
                                  // testing autonomous code
#define VEXNET_TIME 15            // 15 seconds or other time to run
                                  // not yet implemented

// ----------- Setup sensors as needed -------------------------------
// Setup Encoder and other device instances
Encoder encoderLM;
Encoder encoderRM;
Encoder encoderLIFT;

#endif // _portDef_H_
