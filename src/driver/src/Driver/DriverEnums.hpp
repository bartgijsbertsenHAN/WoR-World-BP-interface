#pragma once

/// Enum wat de huidige positie van de robotarm beschrijft
///  * OTHER: Geeft aan dat de arm op een niet-gedefinieerde positie is
///  * READY: Geeft aan dat de arm in de ready-positie staat
///  * PARK: Geeft aan dat de arm in de park-positie staat
///  * STRAIGHT_UP: Geeft aan dat de arm rechtop staat
enum RobotArmPosition {
    OTHER,
    READY,
    PARK,
    STRAIGHT_UP
};

/// Enum wat de huidige status van de robotarm beschrijft
///  * MOVING: De arm beweegt tussen twee posities in
///  * IDLE: De arm beweegt niet, de arm kan wel bewegen
///  * ERROR: Er is een fout opgetreden, de arm kan niet bewegen (communicatiefout, fysieke fout)
enum RobotArmStates {
    MOVING,
    IDLE,
    ERROR
};

/// Enum wat de gewrichten een naam geeft
enum Joints {
    UNKNOWN         = -1,
    BASE            = 0,
    SHOULDER        = 1,
    ELBOW           = 2,
    WRIST_UP_DOWN   = 3,
    GRIPPER         = 4,
    WRIST_ROTATE    = 5
};