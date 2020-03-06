#include <iostream>
#include <thread>
#include "HighLevelDriver.hpp"

// Test low level driver
int main(int argc, char** argv)
{
    // if (argc <= 1)
    // {
    //     std::cout << "Exiting, too few parameters" << std::endl;
    //     return -1;
    // }

    // std::cout << "Using " << argv[1] << " as port" << std::endl;
    HighLevelDriver highlevel = HighLevelDriver(argv[1]);

    std::cout << "BASE: low = " << highlevel.degToPwm(-90, highlevel.getOffsetForJoint(BASE))
        << ", high = " << highlevel.degToPwm(90, highlevel.getOffsetForJoint(BASE)) << std::endl;
    std::cout << "SHOULDER: low = " << highlevel.degToPwm(-30, highlevel.getOffsetForJoint(SHOULDER))
        << ", high = " << highlevel.degToPwm(90, highlevel.getOffsetForJoint(SHOULDER)) << std::endl;
    std::cout << "ELBOW: low = " << highlevel.degToPwm(0, highlevel.getOffsetForJoint(ELBOW))
        << ", high = " << highlevel.degToPwm(135, highlevel.getOffsetForJoint(ELBOW)) << std::endl;
    std::cout << "WRIST_UP_DOWN: low = " << highlevel.degToPwm(-90, highlevel.getOffsetForJoint(WRIST_UP_DOWN))
        << ", high = " << highlevel.degToPwm(90, highlevel.getOffsetForJoint(WRIST_UP_DOWN)) << std::endl;
    std::cout << "WRIST_ROTATE: low = " << highlevel.degToPwm(-90, highlevel.getOffsetForJoint(WRIST_ROTATE))
        << ", high = " << highlevel.degToPwm(90, highlevel.getOffsetForJoint(WRIST_ROTATE)) << std::endl;

    // highlevel.setJointAngle(BASE, 1000, 50.0);
    // highlevel.setJointAngle(GRIPPER, 2000, 50.0);
    // // highlevel.setTimeToComplete(2000);
    // highlevel.startMovement();

    // std::this_thread::sleep_for(std::chrono::seconds(5));

    // highlevel.setJointAngle(BASE, 2000, 50.0);
    // highlevel.setJointAngle(GRIPPER, 1000, 50.0);
    // highlevel.setTimeToComplete(5000);
    // highlevel.startMovement();

    // std::this_thread::sleep_for(std::chrono::seconds(2));

    // highlevel.emergencyStop();

    // highlevel.setPositionOffset(BASE, 2000);
}