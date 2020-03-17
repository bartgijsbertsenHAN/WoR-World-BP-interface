#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "Driver/DriverEnums.hpp"
#include "Parser/Parser.hpp"
#include "control_node.hpp"

ros::Publisher stop_control;
ros::Publisher end_control;

Parser parser;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "control_arm");

    ros::NodeHandle n;
    stop_control = n.advertise<std_msgs::Empty>("emergencyStop", 1);
    end_control = n.advertise<std_msgs::Empty>("endProgram", 1);

    while (true)
    {
        std::string inputString;
        std::getline(std::cin, inputString);

        std::cout << "Starting parser" << std::endl;
        bool result = parser.parseLine(inputString);
        std::cout << "Parser finished (" << result << ")" << std::endl;
    }

    return 0;
}

void sendEmergencyStopCmd()
{
    std_msgs::Empty msg;

    stop_control.publish(msg);

    ros::spinOnce();
}

void sendMoveCmd()
{
    // ROS setup
    ros::NodeHandle n;
    ros::ServiceClient client_contol;
    driver::control_arm srv_control;
    client_contol = n.serviceClient<driver::control_arm>("control_arm");

    std::cout << "Starting send method (move)" << std::endl;
    int iter = 0;

    srv_control.request.order.resize(parser.newAngles.size());
    srv_control.request.angles.resize(parser.newAngles.size());
    srv_control.request.speeds.resize(parser.newSpeeds.size());

    for (auto pair : parser.newAngles)
    {
        int8_t speed = INT8_MAX;
        auto speedIter = parser.newSpeeds.find(pair.first);
        if (speedIter != parser.newSpeeds.end())
        {
            speed = speedIter->second;
        }

        srv_control.request.order[iter] = pair.first;
        srv_control.request.angles[iter] = pair.second;
        srv_control.request.speeds[iter] = speed;
        iter++;
    }
    srv_control.request.time = parser.timeToComplete;
    if (client_contol.call(srv_control))
    {
        std::cout << "Successfully sent command" << std::endl;
    }
    std::cout << "Exiting send method" << std::endl;
}


void sendConfigCmd()
{
    // ROS setup
    ros::NodeHandle n;
    ros::ServiceClient client_config;
    driver::config_arm srv_config;
    client_config = n.serviceClient<driver::config_arm>("config_arm");

    std::cout << "Starting send method (config)" << std::endl;
    int iter = 0;

    srv_config.request.order.resize(parser.newAngles.size());
    srv_config.request.angle_offsets.resize(parser.newAngles.size());
    
    for (auto pair : parser.newAngles)
    {
        srv_config.request.order[iter] = pair.first;
        srv_config.request.angle_offsets[iter] = pair.second;
        iter++;
    }
    if (client_config.call(srv_config))
    {
        std::cout << "Successfully sent command" << std::endl;
    }
    std::cout << "Exiting send method" << std::endl;
}