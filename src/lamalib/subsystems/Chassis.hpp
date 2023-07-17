#pragma once
#include "api.h"
#include "okapi/api.hpp"

class Chassis{
public:
    Chassis(okapi::Motor left, okapi::Motor right);

    void arcade(int lefty, int rightx);

private:
    okapi::Motor Leftmotor;
    okapi::Motor Rightmotor;
};