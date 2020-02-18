#include "HighLevelDriver.hpp"

HighLevelDriver::HighLevelDriver()
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
    
}

void HighLevelDriver::setTimeToComplete(int timeInMs)
{

}

bool HighLevelDriver::startMovement()
{

}

void HighLevelDriver::resetQueue()
{

}

float HighLevelDriver::getProgressInPercent()
{

}

void HighLevelDriver::emergencyStop()
{

}

uint16_t HighLevelDriver::getMinAngle(Joints joint)
{

}

uint16_t HighLevelDriver::getMaxAngle(Joints joint)
{

}