#pragma once
 
#include "okapi/api.hpp"
#include "../controller/pid.hpp"
#include "../devices/motorgroup.hpp"
 
using namespace std;
 
namespace lamaLib {
class Catapult {
 
    private:
    pros::task_t catapultTask;
    int m_velocity;
    MotorGroup m_motors;
    float m_tpr;
    int m_target = 0;
    int m_ready;
 
    int getPosition(){
        return (int)m_motors.getTicks()%(int)m_tpr;
    }
 
    protected:
    /**
     * @brief goto a position in the rotation
     *
     * @param itarget how far from the 0 position the target is
     * @param ishots how many times it shoots on the way to the target
     */
    void setTarget(double itarget, bool shoot);
 
    public:
    /**
     * @brief Construct a new Catapult object
     *
     * @param motors motor group being used
     * @param tpr encoder ticks one rotation of the CATAPULT (NOT of motor)
     * @param readyPosition the ready position in ticks
     */
    Catapult(MotorGroup motors, double tpr, double gearRatio, double readyPosition);
 
    /**
     * @brief move at a certain velocity
     *
     * @param ivel the velocity you'd like to move at
     */
    void moveVelocity(int ivel);
 
    /**
     * @brief go to ready position
     *
     */
    void goToReadyPosition();
 
    /**
     * @brief shoot once
     *
     */
    void shoot();
 
    /**
     * @brief Set the Velocity
     *
     * @param ivel the speed you want to move at
     */
    void setVelocity(int ivel);
 
    /**
     * @brief Get the Velocity
     *
     * @return m_velocity
     */
    int getVelocity();
 
    /**
     * @brief Get the Target
     *
     * @return m_target
     */
    int getTarget();
 
    /**
     * @brief Get the Ready position
     *
     * @return m_ready
     */
    int getReadyPosition();
};
}
