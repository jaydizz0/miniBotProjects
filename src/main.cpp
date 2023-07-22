#include "main.h"
#include "lamalib/lamaapi.hpp"


lamaLib::Motor leftFront(10);
lamaLib::Motor rightFront(-11);

lamaLib::Inline chassis = lamaLib::Inline({leftFront}, {rightFront}, {3.3, {okapi::AbstractMotor::gearset::green, 1}});


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		autonomous();
	} else {
		pros::lcd::clear_line(2);
	}
}


void initialize() {
	pros::lcd::initialize();
	pros::lcd::register_btn1_cb(on_center_button);
}


void disabled() {}


void competition_initialize() {}



void autonomous() {
    pros::ADIUltrasonic ultrasonicSensor(1, 2);
    int stopDistance = 20;

    while (true) {
        int distance = ultrasonicSensor.get_value();

        if (distance <= stopDistance) {
            chassis.move(0, 0);
            break; 
        } else {
            chassis.move(0.5, 0); 
        }

        pros::delay(10); 
    }
}


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// Chassis controlChassis = Chassis(leftFront,rightFront);
	// while (true) {
	// 	int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	// 	int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	// 	controlChassis.arcade(leftY,rightX);
	// 	pros::delay(20);
 	// }
}

