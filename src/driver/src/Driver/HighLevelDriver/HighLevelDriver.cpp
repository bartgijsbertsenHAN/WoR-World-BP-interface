#include "HighLevelDriver.hpp"

HighLevelDriver::HighLevelDriver(std::string port)
    :negativeRanges(), currentPositions(), goalPositions(), lowLevelDriver(port)
{
    // See the comments in the .hpp about the negativeRanges variable
    //  Main point made there is that the values show how much of the range of 180 degrees is below 90 degrees.
    negativeRanges.insert(std::pair<Joints, uint8_t>(BASE,          90));
    negativeRanges.insert(std::pair<Joints, uint8_t>(SHOULDER,      30));
    negativeRanges.insert(std::pair<Joints, uint8_t>(ELBOW,         0));
    negativeRanges.insert(std::pair<Joints, uint8_t>(WRIST_UP_DOWN, 90));
    negativeRanges.insert(std::pair<Joints, uint8_t>(GRIPPER,       0));
    negativeRanges.insert(std::pair<Joints, uint8_t>(WRIST_ROTATE,  90));

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

bool HighLevelDriver::setJointAngle(Joints joint, int16_t degrees, float speedInPercent)
{
    return lowLevelDriver.setJointPwm(joint, degToPwm(degrees, getNegativeRangeForJoint(joint)), speedInPercent * 655.35);
}

void HighLevelDriver::setTimeToComplete(int timeInMs)
{
    lowLevelDriver.setTimeToComplete(timeInMs);
}

bool HighLevelDriver::sendCommand()
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
    return pwmToDeg(lowLevelDriver.getMinPwm(joint), getNegativeRangeForJoint(joint));
}

uint16_t HighLevelDriver::getMaxAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMaxPwm(joint), getNegativeRangeForJoint(joint));
}

int16_t HighLevelDriver::pwmToDeg(uint16_t pwm, int8_t negativeRange)
{
    pwm -= negativeRange;
    const int16_t  IN_MIN = 500;
    const int16_t  IN_MAX = 2500;
    const uint16_t OUT_MIN = 0;
    const uint16_t OUT_MAX = 180;
    return (pwm - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint16_t HighLevelDriver::degToPwm(int16_t deg, int8_t negativeRange)
{
    deg += negativeRange;
    const int16_t  IN_MIN = 0;
    const int16_t  IN_MAX = 180;
    const uint16_t OUT_MIN = 500;
    const uint16_t OUT_MAX = 2500;
    return (deg - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint8_t HighLevelDriver::getNegativeRangeForJoint(Joints joint)
{
    uint8_t negativeRange = 0;
    // If the map contains an entry for the given joint, return the set value
    if (negativeRanges.find(joint) != negativeRanges.end())
    {
        negativeRange = negativeRanges.at(joint);
    }
    return negativeRange;
}

bool HighLevelDriver::setOffset(Joints joint, int8_t offset)
{
    return lowLevelDriver.setPositionOffset(joint, degToPwm(offset, getNegativeRangeForJoint(joint)));
}