/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Nihar Sheth                                      */
/*    Created:      Mon Sep 12 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontRight           motor         1               
// BackRight            motor         2               
// FrontLeft            motor         3               
// BackLeft             motor         4               
// claw                 motor         5               
// arm                  motor         7               
// shoulder             motor         6               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void usercontrol(void){
  while(1){
    FrontRight.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct); 
    BackRight.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct); 
    FrontLeft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct); 
    BackLeft.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct); 

    // claw 
    if(Controller1.ButtonLeft.pressing()){
      claw.spinToPosition(0, degrees); 
    }

    else if(Controller1.ButtonRight.pressing()){
      claw.spinToPosition(90, degrees); 
    }

    // arm 

    if(Controller1.ButtonL1.pressing()){
      arm.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct); 
    }

    else if(Controller1.ButtonL2.pressing()){
      arm.spin(vex::directionType::rev, 50, vex::velocityUnits::pct); 
    }

    if(Controller1.ButtonA.pressing()){
      arm.stop(brakeType::hold); 
    }

    // shoulder 

    if(Controller1.ButtonR1.pressing()){
      shoulder.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct); 
    }

    else if(Controller1.ButtonR2.pressing()){
      shoulder.spin(vex::directionType::rev, 50, vex::velocityUnits::pct); 
    }

    if(Controller1.ButtonB.pressing()){
      shoulder.stop(brakeType::hold); 
    }
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  usercontrol(); 
  vexcodeInit();
  
}
