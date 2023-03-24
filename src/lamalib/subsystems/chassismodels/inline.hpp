#pragma once

#include "../../devices/motorgroup.hpp"
#include "chassis.hpp"
#include <initializer_list>
#include <vector>

namespace lamaLib {
class Inline : public Chassis{
    public:
    Inline(const std::initializer_list<okapi::Motor> &left, const std::initializer_list<okapi::Motor> &right, ChassisScales chassisScales);
    Inline &withOdometry(EncoderScales encoderScales, Encoders encoders);
    Inline &withOdometry(shared_ptr<Odometry> odometry);
    /**
     * @brief Moves the robot according to how fast it should move foward and how fast it should turn
     * 
     * @param forward How fast the robot moves forward, in a range of -1 to 1
     * @param turn How fast the robot turns, in a range of -1 to 1. -1 being left and 1 being right
     */
    void move(double forward, double turn);

    /**
	 * @brief Drive the robot with a tank style
	 * 
	 * @param left The left joystick value from -1 to 1
	 * @param right The right joystick value from -1 to 1
	 * @param deadzone The area around the center of the controller
	 * 				where the controller won't actually do anything,
	 * 				fixing controller drift
	 */
	void tank(double left, double right, double deadzone = 0);
	/**
	 * @brief Drive the robot with an arcade style (single or split)
	 * 
	 * @param forward The joystick value of the y-axis from -1 to 1
	 * @param turn The joystick value of the x-axis from -1 to 1
	 * @param deadzone The area around the center of the controller
	 * 				where the controller won't actually do anything,
	 * 				fixing controller drift
	 */
	void arcade(double forward, double turn, double deadzone = 0);

    /**
	 * @brief Moves forwards or backwards for a given amount of distance.
	 * 
	 * @param dist The distance in the unit that the wheel diameter is in.
	 * @param points Starting velocity and ending velocities; used for cutoff; velocities are in the unit the wheel diameter is in per second.
	 */
    void moveDistance(double dist, std::vector<MotionPoint> points) override;

    /**
     * @brief Turns the robot relative to the starting heading at the beginning of the program
     *
     * Uses odometry heading
     * 
     * @param target The target angle in deg
     * @param maxVel The speed of the turn in the unit the wheel diameter is in per second.
     * @param pid The PID gains used for the turn
     */
    void turnAbsolute(double target, double maxVel, PIDGains pid) override;

    /**
     * @brief Turns the robot relative to the current heading
     * 
     * @param target The target angle in deg
     * @param maxVel The speed of the turn in the unit the wheel diameter is in per second.
     * @param pid The PID gains used for the turn
     */
    void turnRelative(double target, double maxVel, PIDGains pid) override;

    /**
	 * @brief Moves towards a certain point and turns to face an angle on the field using odometry or GPS sensor
	 * 
	 * @param target The target coordinate
	 * @param points Starting velocity and ending velocities; used for cutoff; velocities are in the unit the wheel diameter is in per second.
	 * @param turnVel The velocity of the turn in the unit the wheel diameter is in per second.
	 * @param turnPid The PID gains used for the turn
	 */
    void moveToPose(Pose target, std::vector<MotionPoint> points, double turnVel, PIDGains turnPID) override;

    /**
     * @brief Gets the left motors
     * 
     * @return The left motors
     */
    MotorGroup getLeftMotors();
    /**
     * @brief Gets the right motors
     * 
     * @return The right motors 
     */
    MotorGroup getRightMotors();

	/**
	 * @brief Sets the brake mode of the chassis
	 * 
	 * @param ibrakeMode The brake mode (coast, brake, and hold)
	 */
    void setBrakeMode(okapi::AbstractMotor::brakeMode brakeMode);
	/**
	 * @brief Gets the brake mode of the chassis
	 * 
	 * @return The brake mode (coast, brake, and hold)
	 */
    okapi::AbstractMotor::brakeMode getBrakeMode() override;

    /**
     * @brief Updates the gear ratio in the case that a transmission is being used.
     * 
     * @param igearRatio The new gear ratio of the drive train
     */
    void updateGearRatio(double gearRatio);
    
    private:
    MotorGroup leftMotors;
    MotorGroup rightMotors;
};
} // namespace lamaLib