#pragma once

#include <map>
#include <cstdint>
#include <chrono>
#include "../IDriver.hpp"
#include "../LowLevelDriver/LowLevelDriver.hpp"

// Doxygen descriptions are inherited
class HighLevelDriver : IDriver
{
public:
    
    HighLevelDriver(std::string port);

    bool setJointAngle(Joints joint, int16_t degrees, float speedInPercent = 100.0);
    void setTimeToComplete(int timeInMs);
    bool sendCommand(bool isSendingMove = true);
    void resetQueue();
    float getProgressInPercent();
    void emergencyStop();
    uint16_t getMinAngle(Joints joint);
    uint16_t getMaxAngle(Joints joint);
    bool setOffset(Joints joint, int8_t offset);
    /// @brief sets new state for highlevel driver
    /// @param state new state to set 
    void setCurrentState(MachineStates newState);
    /// @brief returns current state of highlevel driver
    MachineStates getCurrentState();
    /// @brief runs the state machine of highlevel driver
    void runStateMachine();

private:
    int16_t pwmToDeg(uint16_t pwm, int8_t negativeRange);
    /// @brief moves arm to init position with half speed
    void moveToInitPos();
public:
    uint16_t degToPwm(int16_t deg, int8_t negativeRange);

    uint8_t getNegativeRangeForJoint(Joints joint);
private:
    /// This variable stores how much of the possible 180 degrees of freedom are within the negative range
    /// I.e. A value of 90 has a range from -90 degrees to 90 degrees
    /// I.e. A value of 30 has a range from -30 degrees to 150 degrees
    std::map<Joints, uint8_t> negativeRanges;

    /// This variable stores the positions that the arm is supposed to be in. It is used to calculate the position while moving
    std::map<Joints, uint16_t> currentPositions;

    /// This variable stores the position that the arm is moving to, to calculate where the arm is while it is moving.
    std::map<Joints, uint16_t> goalPositions;

    /// A reference to the low level driver that sends the commands to the robot arm
    LowLevelDriver lowLevelDriver;

    /// The current state of highleveldriver
    MachineStates currentState;

    /// Initial position of arm
    uint8_t initPositions[NUMBER_OF_JOINTS];

    // Joint offsets
    uint8_t jointOffsets[NUMBER_OF_JOINTS];

    /// Estimated time when done
    std::chrono::milliseconds timeDone;
};