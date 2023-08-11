#include "main.h"
#include "lamalib/lamaapi.hpp"

lamaLib::Motor leftFront(10);
lamaLib::Motor rightFront(11);
lamaLib::Inline chassis = lamaLib::Inline({leftFront}, {rightFront}, {2.77, {okapi::AbstractMotor::gearset::green, 1}});


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
    chassis.withOdometry({3.5,3.5,0,3.3,3.3,0}, {std::make_shared<lamaLib::Motor>(leftFront),std::make_shared<lamaLib::Motor>(rightFront)});
    pros::Distance distance_sensor(1);
    double travel_distance = distance_sensor.get();
    chassis.moveDistance({{{10.0, 10.0}, travel_distance}},{0.035,0,0});
    travel_distance *= -1;
    chassis.moveDistance({{{10.0, 10.0}, travel_distance}},{0.035,0,0});
}



void opcontrol() {
    // lamaLib::Motor myMotor(10, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

    pros::Controller master(pros::E_CONTROLLER_MASTER);
    // while (true) {
    //     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    //         myMotor.moveVelocity(200);
    //     } 
    //     else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    //         myMotor.moveVelocity(400);
    //     } 
    //     else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    //         myMotor.moveVelocity(600);
    //     } 
    //     else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    //         myMotor.moveVelocity(0);
    //     }
        
    
    //     pros::delay(20);
    //}
}





