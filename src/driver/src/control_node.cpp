#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "control_arm");

    ros::NodeHandle n;
    ros::ServiceClient client_contol = n.serviceClient<driver::control_arm>("control_arm");
    ros::ServiceClient client_config = n.serviceClient<driver::config_arm>("config_arm");
    ros::Publisher stop_control = n.advertise<std_msgs::Empty>("emergencyStop", 1);
    driver::control_arm srv_control;
    driver::config_arm srv_config;

    //Add parser

    if(client_contol.call(srv_control))
    {
        if(srv_control.response.succes)
        {
            std::cout << "Move posible" << std::endl;
        }
         else 
        {
            std::cout << "Move not posible" << std::endl;    
        }
    }

    if(client_config.call(srv_config))
    {
        if(srv_config.response.succes)
        {
            std::cout << "Config valid" << std::endl;
        }
         else 
        {
            std::cout << "Config invalid" << std::endl;    
        }
    }
    return 0;
}