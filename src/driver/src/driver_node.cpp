#include <iostream>
#include <thread>
#include "ros/ros.h"
#include <std_msgs/Empty.h>
#include "driver/control_arm.h"
#include "driver/config_arm.h"
#include "Driver/HighLevelDriver/HighLevelDriver.hpp"
#include "Driver/DriverEnums.hpp"

//Temporary empty string as port
HighLevelDriver highlevel = HighLevelDriver(" "); 

void emergencyStopCall(const std_msgs::Empty::ConstPtr& msg)
{
  highlevel.emergencyStop();
  highlevel.setCurrentState(MachineStates::s_EmergencyStop);
}

void endProgramCall(const std_msgs::Empty::ConstPtr& msg)
{
  highlevel.setCurrentState(MachineStates::s_End);
}

bool controlArm(driver::control_arm::Request  &req,
                driver::control_arm::Response &res)
{
  bool return_value = true;
  for(int i = 0; i != req.order.size(); ++i)
  {
    if(highlevel.setJointAngle(static_cast<Joints>(req.order[i]), req.angles[i], req.speeds[i]))
    {
      res.possible[i] = true;
    } 
    else
    {
      return_value = false;
      res.possible[i] = false;
    }
  }
  highlevel.setTimeToComplete(req.time); //Log warning

  if(!highlevel.sendCommand())
  {
    return_value = false;
  }
  
  return return_value;
}

bool configArm(driver::config_arm::Request  &req,
                driver::config_arm::Response &res)
{
  bool return_value = true;
  for(int i = 0; i != req.order.size(); ++i)
  {
    if(highlevel.setOffset(static_cast<Joints>(req.order[i]), req.angle_offsets[i]))
    {
      res.possible[i] = true;
    } 
    else
    {
      return_value = false;
      res.possible[i] = false;
    }
  }
  
  // if(!highlevel.sendCommand())
  // {
  //   return_value = false;
  // }
  
  return return_value;
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
    ros::Subscriber endProgram = n.subscribe("endProgram", 1, endProgramCall);
    ros::ServiceServer control_arm = n.advertiseService("control_arm", controlArm);
    ros::ServiceServer config_arm = n.advertiseService("config_arm", configArm);
    
    highlevel = HighLevelDriver(argv[1]);

    while(highlevel.getCurrentState() != MachineStates::s_End)
    {
      highlevel.runStateMachine();
      ros::spinOnce();
    }

    return 0;

}