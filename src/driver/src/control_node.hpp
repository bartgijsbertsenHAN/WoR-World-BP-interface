#ifndef __CONTROL_NODE_HPP__
#define __CONTROL_NODE_HPP__

/// @brief Sends an emergency stop command to the robot arm controller (driver)
void sendEmergencyStopCmd();

/// @brief Sends an move command to the robot arm controller (driver)
void sendMoveCmd();

/// @brief Sends an configuration command to the robot arm controller (driver)
void sendConfigCmd();

#endif