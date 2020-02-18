#pragma once

#include <map>
#include <cstdint>
#include "IDriver.hpp"
#include "LowLevelDriver.hpp"

// Doxygen descriptions are inherited
class HighLevelDriver : IDriver
{
public:
    HighLevelDriver();

    void setJointAngle(Joints joint, uint16_t degrees, float speedInPercent = 100.0);
    void setTimeToComplete(uint16_t timeInMs);
    bool startMovement();
    void resetQueue();
    float getProgressInPercent();
    void emergencyStop();
    uint16_t getMinAngle(Joints joint);
    uint16_t getMaxAngle(Joints joint);

private:
    int16_t pwmToDeg(uint16_t pwm);
    uint16_t degToPwm(int16_t deg);

    std::map<Joints, uint16_t> currentPositions;
    std::map<Joints, uint16_t> goalPositions;

    LowLevelDriver lowLevelDriver;
};