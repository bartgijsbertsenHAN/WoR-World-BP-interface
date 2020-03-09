#include "HighLevelDriver.hpp"

HighLevelDriver::HighLevelDriver(std::string port)
    :angleOffsets(), currentPositions(), goalPositions(), lowLevelDriver(port)
{
    angleOffsets.insert(std::pair<Joints, uint8_t>(BASE,          90));
    angleOffsets.insert(std::pair<Joints, uint8_t>(SHOULDER,      30));
    angleOffsets.insert(std::pair<Joints, uint8_t>(ELBOW,         0));
    angleOffsets.insert(std::pair<Joints, uint8_t>(WRIST_UP_DOWN, 90));
    angleOffsets.insert(std::pair<Joints, uint8_t>(GRIPPER,       0));
    angleOffsets.insert(std::pair<Joints, uint8_t>(WRIST_ROTATE,  90));

    currentPositions.insert(std::pair<Joints, uint16_t>(BASE,          0));
    currentPositions.insert(std::pair<Joints, uint16_t>(SHOULDER,      0));
    currentPositions.insert(std::pair<Joints, uint16_t>(ELBOW,         0));
    currentPositions.insert(std::pair<Joints, uint16_t>(WRIST_UP_DOWN, 0));
    currentPositions.insert(std::pair<Joints, uint16_t>(GRIPPER,       0));
    currentPositions.insert(std::pair<Joints, uint16_t>(WRIST_ROTATE,  0));

    goalPositions.insert(std::pair<Joints, uint16_t>(BASE,          0));
    goalPositions.insert(std::pair<Joints, uint16_t>(SHOULDER,      0));
    goalPositions.insert(std::pair<Joints, uint16_t>(ELBOW,         0));
    goalPositions.insert(std::pair<Joints, uint16_t>(WRIST_UP_DOWN, 0));
    goalPositions.insert(std::pair<Joints, uint16_t>(GRIPPER,       0));
    goalPositions.insert(std::pair<Joints, uint16_t>(WRIST_ROTATE,  0));
}

void HighLevelDriver::setJointAngle(Joints joint, int16_t degrees, float speedInPercent)
{
    lowLevelDriver.setJointPwm(joint, degToPwm(degrees, getOffsetForJoint(joint)), speedInPercent * 655.35);
}

void HighLevelDriver::setTimeToComplete(int timeInMs)
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
    return pwmToDeg(lowLevelDriver.getMinPwm(joint), getOffsetForJoint(joint));
}

uint16_t HighLevelDriver::getMaxAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMaxPwm(joint), getOffsetForJoint(joint));
}

int16_t HighLevelDriver::pwmToDeg(uint16_t pwm, int8_t offset)
{
    pwm -= offset;
    const int16_t  IN_MIN = 500;
    const int16_t  IN_MAX = 2500;
    const uint16_t OUT_MIN = 0;
    const uint16_t OUT_MAX = 180;
    return (pwm - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint16_t HighLevelDriver::degToPwm(int16_t deg, int8_t offset)
{
    deg += offset;
    const int16_t  IN_MIN = 0;
    const int16_t  IN_MAX = 180;
    const uint16_t OUT_MIN = 500;
    const uint16_t OUT_MAX = 2500;
    return (deg - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint8_t HighLevelDriver::getOffsetForJoint(Joints joint)
{
    uint8_t offset = 0;
    // If the map contains an entry for the given joint, return the set value
    if (angleOffsets.find(joint) != angleOffsets.end())
    {
        offset = angleOffsets.at(joint);
    }
    return offset;
}