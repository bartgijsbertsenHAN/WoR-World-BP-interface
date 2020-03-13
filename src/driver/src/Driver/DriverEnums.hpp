#pragma once

/// Enum which gives joints names
enum Joints {
    BASE            = 0,
    SHOULDER        = 1,
    ELBOW           = 2,
    WRIST_UP_DOWN   = 3,
    GRIPPER         = 4,
    WRIST_ROTATE    = 5
};

/// State in which the machine can be
enum MachineStates{
    s_Configure = 0,
    s_Idle = 1,
    s_Move = 2,
    s_End = 3,
    s_EmergencyStop = 4
};

/// Amount of joints
const int NUMBER_OF_JOINTS = 5;