#include "HighLevelDriver.hpp"

HighLevelDriver::HighLevelDriver(std::string port)
    :negativeRange(), currentPositions(), goalPositions(), lowLevelDriver(port)
{
    // See the comments in the .hpp about the negativeRange variable
    //  Main point made there is that the values show how much of the range of 180 degrees is below 90 degrees.
    negativeRange.insert(std::pair<Joints, uint8_t>(BASE,          90));
    negativeRange.insert(std::pair<Joints, uint8_t>(SHOULDER,      30));
    negativeRange.insert(std::pair<Joints, uint8_t>(ELBOW,         0));
    negativeRange.insert(std::pair<Joints, uint8_t>(WRIST_UP_DOWN, 90));
    negativeRange.insert(std::pair<Joints, uint8_t>(GRIPPER,       0));
    negativeRange.insert(std::pair<Joints, uint8_t>(WRIST_ROTATE,  90));

    /// Initialise the other two vectors with a valid position for every joint.
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
    if (negativeRange.find(joint) != negativeRange.end())
    {
        offset = negativeRange.at(joint);
    }
    return offset;
}