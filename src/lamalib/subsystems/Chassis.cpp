#include "Chassis.hpp"

Chassis::Chassis(okapi::Motor left, okapi::Motor right) : Leftmotor(left), Rightmotor(right){

}


void Chassis::arcade(int lefty, int rightx){
    double ly = lefty * 1.57480314961;
    double rx = rightx * 1.57480314961;

    double leftSpeed = ly + rx;
    double rightSpeed = ly - rx;

    Rightmotor.moveVelocity(rightSpeed);
    Leftmotor.moveVelocity(leftSpeed);
}