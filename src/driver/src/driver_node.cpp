#include <iostream>
#include <thread>
#include "ros/ros.h"
#include "std_mgs/Empty.h"
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "HighLevelDriver.hpp"
#include "DriverEnum.hpp"

//Temporary empty string as port
HighLevelDriver highlevel = HighLevelDriver(" "); 

void emergencyStopCall(const std_msgs::Empty::ConstPtr& msg)
{
  highlevel.emergencyStop();
}

bool controlArm(driver::control_arm::Request  &req,
                driver::control_arm::Response &res)
{
  for(int i = 0; i != req.angles.size(); ++i)
  {
    highlevel.setJointAngle(i, req.angles[i], req.speeds[i]);
  }
  highlevel.setTimeToComplete(req.time);
  //Check if move is posible
  highlevel.startMovement();
  return true;
}

bool configArm(driver::config_arm::Request  &req,
                driver::config_arm::Response &res)
{
  for(int i = 0; i != req.angle_offsets.size(); ++i)
  {
    //Set offsets
  }
  //Check if offset is posible
  
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
    ros::ServiceServer control_arm = n.advertiseService("control_arm", controlArm);
    ros::ServiceServer config_arm = n.advertiseService("config_arm", configArm);
    
    highlevel = HighLevelDriver(argv[1]);
    ros::spin();

    return 0;

}