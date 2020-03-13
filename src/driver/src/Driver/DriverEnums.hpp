#pragma once

/// Enum which gives joints names
enum Joints {
    UNKNOWN         = -1,
    BASE            = 0,
    SHOULDER        = 1,
    ELBOW           = 2,
    WRIST_UP_DOWN   = 3,
    GRIPPER         = 4,
    WRIST_ROTATE    = 5
};


/// Amount of joints
const int NUMBER_OF_JOINTS = 5;