#pragma once

#include <map>
#include <cstdint>
#include "../IDriver.hpp"
#include "../LowLevelDriver/LowLevelDriver.hpp"

// Doxygen descriptions are inherited
class HighLevelDriver : IDriver
{
public:
    HighLevelDriver(std::string port);

    void setJointAngle(Joints joint, int16_t degrees, float speedInPercent = 100.0);
    void setTimeToComplete(int timeInMs);
    bool startMovement();
    void resetQueue();
    float getProgressInPercent();
    void emergencyStop();
    uint16_t getMinAngle(Joints joint);
    uint16_t getMaxAngle(Joints joint);

private:
    int16_t pwmToDeg(uint16_t pwm, int8_t offset);
public:
    uint16_t degToPwm(int16_t deg, int8_t offset);

    uint8_t getOffsetForJoint(Joints joint);
private:
    /// This variable stores how much of the possible 180 degrees of freedom are within the negative range
    /// I.e. A value of 90 has a range from -90 degrees to 90 degrees
    /// I.e. A value of 30 has a range from -30 degrees to 150 degrees
    std::map<Joints, uint8_t> negativeRange;

    /// This variable stores the positions that the arm is supposed to be in. It is used to calculate the position while moving
    std::map<Joints, uint16_t> currentPositions;

    /// This variable stores the position that the arm is moving to, to calculate where the arm is while it is moving.
    std::map<Joints, uint16_t> goalPositions;

    /// A reference to the low level driver that sends the commands to the robot arm
    LowLevelDriver lowLevelDriver;
};