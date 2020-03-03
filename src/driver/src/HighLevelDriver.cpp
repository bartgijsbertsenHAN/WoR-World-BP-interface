#include "HighLevelDriver.hpp"

HighLevelDriver::HighLevelDriver(std::string port)
    :currentPositions(), goalPositions(), lowLevelDriver(port)
{
    currentPositions.insert(std::pair<Joints, int>(BASE, 0));
    currentPositions.insert(std::pair<Joints, int>(SHOULDER, 0));
    currentPositions.insert(std::pair<Joints, int>(ELBOW, 0));
    currentPositions.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 0));
    currentPositions.insert(std::pair<Joints, int>(GRIPPER, 0));
    currentPositions.insert(std::pair<Joints, int>(WRIST_ROTATE, 0));

    goalPositions.insert(std::pair<Joints, int>(BASE, 0));
    goalPositions.insert(std::pair<Joints, int>(SHOULDER, 0));
    goalPositions.insert(std::pair<Joints, int>(ELBOW, 0));
    goalPositions.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 0));
    goalPositions.insert(std::pair<Joints, int>(GRIPPER, 0));
    goalPositions.insert(std::pair<Joints, int>(WRIST_ROTATE, 0));
}

void HighLevelDriver::setJointAngle(Joints joint, uint16_t degrees, float speedInPercent)
{
    lowLevelDriver.setJointPwm(joint, degToPwm(degrees), speedInPercent * 655.35);
}

void HighLevelDriver::setTimeToComplete(uint16_t timeInMs)
{
    lowLevelDriver.setTimeToComplete(timeInMs);
}

bool HighLevelDriver::startMovement()
{
    return lowLevelDriver.sendCommand();
}

void HighLevelDriver::resetQueue()
{
    lowLevelDriver.resetCommand();
}

float HighLevelDriver::getProgressInPercent()
{
    // TODO
    return -1;
}

void HighLevelDriver::emergencyStop()
{
    lowLevelDriver.emergencyStop();
}

uint16_t HighLevelDriver::getMinAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMinPwm(joint));
}

uint16_t HighLevelDriver::getMaxAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMaxPwm(joint));
}

int16_t HighLevelDriver::pwmToDeg(uint16_t pwm)
{
    pwm /= (65535.0 / 360.0);
    return pwm - 90;
}

uint16_t HighLevelDriver::degToPwm(int16_t deg)
{
    uint16_t pwm = deg + 90;
    return pwm *= (65535.0 / 360.0);
}