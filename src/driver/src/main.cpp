#include <iostream>
#include "LowLevelDriver.hpp"

// Test low level driver
int main(int argc, char** argv)
{
    LowLevelDriver lowLevel = LowLevelDriver("/dev/pts/4");
    lowLevel.setJointPwm(BASE, 1500);
    lowLevel.setJointPwm(GRIPPER, 2000);
    lowLevel.setTimeToComplete(2000);
    lowLevel.sendCommand();

    lowLevel.setPositionOffset(BASE, 2000);
}