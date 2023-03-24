#pragma once

#include "okapi/api.hpp"
#include "motor.hpp"
#include <initializer_list>
#include <vector>

namespace lamaLib {
class MotorGroup : public okapi::MotorGroup {
public:
  /**
   * @brief group of V5 motors which act as one motor (i.e. they are mechanically linked). A MotorGroup
   * requires at least one motor. If no motors are supplied, a `std::invalid_argument` exception is
   * thrown.
   *
   * @param imotors The motors in this group.
   * @param ilogger The logger this instance will log initialization warnings to.
   */
  MotorGroup(const std::initializer_list<okapi::Motor> &imotors,
             const std::shared_ptr<okapi::Logger> &ilogger = okapi::Logger::getDefaultLogger());

  /**
   * @brief group of V5 motors which act as one motor (i.e. they are mechanically linked). A MotorGroup
   * requires at least one motor. If no motors are supplied, a `std::invalid_argument` exception is
   * thrown.
   *
   * @param imotors The motors in this group.
   * @param ilogger The logger this instance will log initialization warnings to.
   */
  MotorGroup(const std::initializer_list<std::shared_ptr<AbstractMotor>> &imotors,
             const std::shared_ptr<okapi::Logger> &ilogger = okapi::Logger::getDefaultLogger());
  /**
   * @brief Sets the velocity for the motor.
   *
   * This velocity corresponds to different actual speeds depending on the gearset
   * used for the motor. This results in a range of +-100 for pros::c::red,
   * +-200 for green, and +-600 for blue. The velocity
   * is held with PID to ensure consistent speed, as opposed to setting the motor's
   * voltage.
   *
   * @param velocity The new motor velocity from -+-100, +-200, or +-600 depending on the motor's
   * gearset
   * @return 1 if the operation was successful or `PROS_ERR` if the operation failed, setting errno.
   */
  std::int32_t moveVelocity(std::int16_t velocity) override;


  double getTicks();
};
}