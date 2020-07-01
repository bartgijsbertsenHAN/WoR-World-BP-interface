#pragma once

#include <cstdint>
#include <string>
#include <map>
#include <boost/asio.hpp>
#include "../DriverEnums.hpp"

/// @brief LowLevelDriver translates robotarm functionality and protects the hardware from damage without adding functionality
class LowLevelDriver
{
public:
    LowLevelDriver() = delete;

    /// @brief Contructor sets port and fills all protection values
    /// @param port The port to send the commands to
    LowLevelDriver(std::string port);

    /// @brief Adds wanted joint adjustment to message
    /// @param joint Set joint which needs to be adjusted
    /// @param pwm Target angle in pwm
    /// @param speed Maximum speed of the joint
    /// @return if pwm is valid
    bool setJointPwm(Joints joint, uint16_t pwm, uint16_t speed = 65535);

    /// @brief Sets time in which movements needs to be completed, it doesn't mean it will always achieve this.
    /// Call this function last before sending.
    /// @param timeInMs Time in millieseconds in which the movement needs to be completed.
    void setTimeToComplete(uint16_t timeInMs);

    /// @brief Adds a offset for set joint to queue, offsets are lost after power down
    /// @param joint Joint which needs calibrating
    /// @param offset Offset of joint in pwm
    /// @return True when offset is valid
    bool setPositionOffset(Joints joint, int8_t offset);

    /// @brief Sends command to robotarm and resets queue
    /// @return True when command is send, false if it fails
    bool sendCommand();

    /// @brief Reset command queue to empty string
    void resetCommand();

    /// @brief Stops movement of the robotarm
    void emergencyStop();

    /// @brief Getter for the minimum pwm of set joint
    /// @param joint The joint of which pwm is requested
    /// @return Minimum value for set joint
    uint16_t getMinPwm(Joints joint);

    /// @brief Getter for the maximum pwm of set joint
    /// @param joint The joint of which pwm is requested
    /// @return Maximum value for set joint
    uint16_t getMaxPwm(Joints joint);

private:
    /// @brief Contains a list of minimum pwm values
    std::map<Joints, uint16_t> minPwm;

    /// @brief Contains a list of maximum pwm values
    std::map<Joints, uint16_t> maxPwm;

    /// @brief Saves the message while its being constructed (Queue)
    std::string message;

    /// @brief Saves port as string
    std::string port;

    /// @brief Absolute max offset
    uint8_t absMaxOffset;

};