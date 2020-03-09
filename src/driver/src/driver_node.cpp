#include <iostream>
#include <thread>
#include "std_mgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "ros/ros.h"
#include "HighLevelDriver.hpp"

//Temporary empty string as port
HighLevelDriver highlevel = HighLevelDriver(" "); 

void emergencyStopCall(const std_msgs::Empty::ConstPtr& msg)
{
  highlevel.emergencyStop();
}

bool controlArm(beginner_tutorials::AddTwoInts::Request  &req,
                beginner_tutorials::AddTwoInts::Response &res)
{
  
  return true;
}

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        std::cout << "Exiting, too few parameters" << std::endl;
        return -1;
    }

    ros::init(argc, argv, "driver_node");

    ros::NodeHandle n;
    ros::Subscriber emergencyStop = n.subscribe("emergencyStop", 1, emergencyStopCall);
    
    highlevel = HighLevelDriver(argv[1]);

}