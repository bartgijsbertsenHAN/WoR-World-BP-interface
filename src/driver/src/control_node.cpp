#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "Driver/DriverEnums.hpp"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "control_arm");

    ros::NodeHandle n;
    ros::ServiceClient client_contol = n.serviceClient<driver::control_arm>("control_arm");
    ros::ServiceClient client_config = n.serviceClient<driver::config_arm>("config_arm");
    ros::Publisher stop_control = n.advertise<std_msgs::Empty>("emergencyStop", 1);
    ros::Publisher end_control = n.advertise<std_msgs::Empty>("endProgram", 1);
    driver::control_arm srv_control;
    driver::config_arm srv_config;

    //Add parser (remember values)
    return 0;
}