#include <iostream>
#include <thread>
#include "LowLevelDriver.hpp"

// Test low level driver
int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        std::cout << "Exiting, too few parameters" << std::endl;
        return -1;
    }

    std::cout << "Using " << argv[1] << " as port" << std::endl;
    LowLevelDriver lowLevel = LowLevelDriver(argv[1]);
    lowLevel.setJointPwm(BASE, 1000);
    lowLevel.setJointPwm(GRIPPER, 2000);
    // lowLevel.setTimeToComplete(2000);
    lowLevel.sendCommand();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    lowLevel.setJointPwm(BASE, 2000);
    lowLevel.setJointPwm(GRIPPER, 1000);
    lowLevel.setTimeToComplete(5000);
    lowLevel.sendCommand();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    lowLevel.emergencyStop();

    // lowLevel.setPositionOffset(BASE, 2000);
}