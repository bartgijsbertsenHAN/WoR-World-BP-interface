#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "Driver/DriverEnums.hpp"
#include "Parser/Parser.hpp"
#include "control_node.hpp"

ros::ServiceClient client_contol;
ros::ServiceClient client_config;
ros::Publisher stop_control;
ros::Publisher end_control;
driver::control_arm srv_control;
driver::config_arm srv_config;

Parser parser;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "control_arm");

    ros::NodeHandle n;
    stop_control = n.advertise<std_msgs::Empty>("emergencyStop", 1);
    end_control = n.advertise<std_msgs::Empty>("endProgram", 1);
    client_contol = n.serviceClient<driver::control_arm>("control_arm");
    client_config = n.serviceClient<driver::config_arm>("config_arm");

    while (true)
    {
        std::string inputString;
        std::getline(std::cin, inputString);

        bool result = parser.parseLine(inputString);
        if (!result)
        {
            std::cout << "Parser could not form a message to send to the driver\n" <<
                         " Please check your input" << std::endl;
        }
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
}


void sendConfigCmd()
{
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
}