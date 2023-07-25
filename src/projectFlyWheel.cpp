#include "main.h"
#include "lamalib/lamaapi.hpp"

lamaLib::Motor onlyOne(10);


void myFlyWheel(){
  pros::Controller master (pros::E_CONTROLLER_MASTER);
  while(true){
    if (master.get_digital(DIGITAL_Y)) {
      onlyOne.moveVelocity(100);
    }
    else if (master.get_digital(DIGITAL_X)) {
      onlyOne.moveVelocity(400);
    }
    else if(master.get_digital(DIGITAL_A)){
      onlyOne.moveVelocity(600);
    }
    else{
      onlyOne.moveVelocity(0);
    }
    pros::delay(2);
  }

}
