#include "Logger/Logger.hpp"
#include "ros/ros.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    // ros::Publisher log_publishe
    
    // log_publisher = n.advertise<std_msgs::String>("driver_log", 5);
    // Logger::getInstance().log("debug",   e_DEBUG,   true);
    Logger::getInstance().log("STATE: {init}",    e_INFO);
    // Logger::getInstance().log("warning", e_WARNING, true);
    // Logger::getInstance().log("error",   e_ERROR,   true);
    // Logger::getInstance().log("fatal",   e_FATAL,   true);
    ros::spin();
}

// #include <iostream>
// #include <thread>
// #include "Driver/HighLevelDriver/HighLevelDriver.hpp"

// // Test low level driver
// int main(int argc, char** argv)
// {
//     if (argc <= 1)
//     {
//         std::cout << "Exiting, too few parameters" << std::endl;
//         return -1;
//     }

//     std::cout << "Using " << argv[1] << " as port" << std::endl;
//     HighLevelDriver highlevel = HighLevelDriver(argv[1]);

//     // highlevel.setJointAngle(BASE, 1000, 50.0);
//     // highlevel.setJointAngle(GRIPPER, 2000, 50.0);
//     // // highlevel.setTimeToComplete(2000);
//     // highlevel.startMovement();

//     // std::this_thread::sleep_for(std::chrono::seconds(5));

//     // highlevel.setJointAngle(BASE, 2000, 50.0);
//     // highlevel.setJointAngle(GRIPPER, 1000, 50.0);
//     // highlevel.setTimeToComplete(5000);
//     // highlevel.startMovement();

//     // std::this_thread::sleep_for(std::chrono::seconds(2));

//     // highlevel.emergencyStop();

//     // highlevel.setPositionOffset(BASE, 2000);
// }