#pragma once

#include "DriverEnums.hpp"

/// @brief Interface for translating commands to robotarm instructions and adding usefull functionality
class IDriver
{
public:
    /// @brief Adds new angle to set joint
    /// @param joint Joint which needs to be moved
    /// @param degrees The new angle of the joint 
    /// @param speedInPercent Maximum speed in percentages
    /// @return True when degrees are valid
    virtual bool setJointAngle(Joints joint, int16_t degrees, float speedInPercent = 100.0) = 0;

    /// @brief Sets time in which the operation needs to be completed
    /// @param timeInMs Time of action in milliseconds
    virtual void setTimeToComplete(int timeInMs) = 0;

    /// @brief Sends command to robotarm
    /// @return True when command is succesfully send
    virtual bool sendCommand() = 0;

    /// @brief Resets queue of command
    virtual void resetQueue() = 0;

    /// @brief Gives the progress of the robotarm in percentages
    /// @return The progress in percentages (0 - 100)
    virtual float getProgressInPercent() = 0;

    /// @brief emergency stop. Stops movement right away
    virtual void emergencyStop() = 0;

    /// @brief Getter for the minimum angle of set joint
    /// @param joint The joint of which angle is requested
    /// @return Minimum angle for set joint
    virtual uint16_t getMinAngle(Joints joint) = 0;

    /// @brief Getter for the maximum angle of set joint
    /// @param joint The joint of which angle is requested
    /// @return Maximum value for set joint
    virtual uint16_t getMaxAngle(Joints joint) = 0;
    
    /// @brief Adds a offset for set joint to queue, offsets are lost after power down
    /// @param joint Joint which needs calibrating
    /// @param offset Offset of joint in pwm
    /// @return True when offset is valid
    virtual bool setOffset(Joints joint, int8_t offset) = 0;
};