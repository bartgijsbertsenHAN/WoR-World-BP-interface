#include "HighLevelDriver.hpp"
#include "../../Logger/Logger.hpp"


HighLevelDriver::HighLevelDriver(std::string port)
    :negativeRanges(), currentPositions(), goalPositions(), lowLevelDriver(port), currentState(MachineStates::s_Configure), timeDone(0)
{
    // See the comments in the .hpp about the negativeRanges variable
    //  Main point made there is that the values show how much of the range of 180 degrees is below 90 degrees.
    negativeRanges.insert(std::pair<Joints, uint8_t>(BASE,          90));
    negativeRanges.insert(std::pair<Joints, uint8_t>(SHOULDER,      30));
    negativeRanges.insert(std::pair<Joints, uint8_t>(ELBOW,         0));
    negativeRanges.insert(std::pair<Joints, uint8_t>(WRIST_UP_DOWN, 90));
    negativeRanges.insert(std::pair<Joints, uint8_t>(GRIPPER,       0));
    negativeRanges.insert(std::pair<Joints, uint8_t>(WRIST_ROTATE,  90));

    /// Initialise the other two vectors with a valid position for every joint.
    currentPositions.insert(std::pair<Joints, uint16_t>(BASE,          0));
    currentPositions.insert(std::pair<Joints, uint16_t>(SHOULDER,      0));
    currentPositions.insert(std::pair<Joints, uint16_t>(ELBOW,         0));
    currentPositions.insert(std::pair<Joints, uint16_t>(WRIST_UP_DOWN, 0));
    currentPositions.insert(std::pair<Joints, uint16_t>(GRIPPER,       0));
    currentPositions.insert(std::pair<Joints, uint16_t>(WRIST_ROTATE,  0));
    goalPositions.insert(std::pair<Joints, uint16_t>(BASE,          0));
    goalPositions.insert(std::pair<Joints, uint16_t>(SHOULDER,      0));
    goalPositions.insert(std::pair<Joints, uint16_t>(ELBOW,         0));
    goalPositions.insert(std::pair<Joints, uint16_t>(WRIST_UP_DOWN, 0));
    goalPositions.insert(std::pair<Joints, uint16_t>(GRIPPER,       0));
    goalPositions.insert(std::pair<Joints, uint16_t>(WRIST_ROTATE,  0));

    initPositions[0] = 45; //TODO: Set init waarden
}

bool HighLevelDriver::setJointAngle(Joints joint, int16_t degrees, float speedInPercent)
{
    Logger::getInstance().log("INFO: {Joint " + std::to_string(static_cast<uint8_t>(joint)) + " wordt naar " + std::to_string(degrees) + " graden verplaatst.}",e_DEBUG);
    
    return lowLevelDriver.setJointPwm(joint, degToPwm(degrees, getNegativeRangeForJoint(joint)), speedInPercent * 655.35);
}

void HighLevelDriver::setTimeToComplete(int timeInMs)
{
    timeDone = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())+static_cast<std::chrono::milliseconds>(timeInMs);
    Logger::getInstance().log("INFO: {Tijd voor actie is ingesteld op " + std::to_string(timeInMs)+" ms}",e_DEBUG);
    lowLevelDriver.setTimeToComplete(timeInMs);
}

bool HighLevelDriver::sendCommand()
{
    if(lowLevelDriver.sendCommand())
    {
        Logger::getInstance().log("STATE: {Move}",e_INFO);
        Logger::getInstance().log("EVENT: {Valide commando ontvangen}",e_DEBUG);
        currentState = MachineStates::s_Move;
        return true;
    }
    else
    {
        Logger::getInstance().log("WARNING: {Bericht versturen mislukt}",e_WARNING);
    }
    return false;      
    
}

void HighLevelDriver::resetQueue()
{
    lowLevelDriver.resetCommand();
    Logger::getInstance().log("INFO: {Comando queue gereset}",e_DEBUG);

}

float HighLevelDriver::getProgressInPercent()
{
    // TODO
    return -1;
}

void HighLevelDriver::emergencyStop()
{
    lowLevelDriver.emergencyStop();
}

uint16_t HighLevelDriver::getMinAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMinPwm(joint), getNegativeRangeForJoint(joint));
}

uint16_t HighLevelDriver::getMaxAngle(Joints joint)
{
    return pwmToDeg(lowLevelDriver.getMaxPwm(joint), getNegativeRangeForJoint(joint));
}

int16_t HighLevelDriver::pwmToDeg(uint16_t pwm, int8_t negativeRange)
{
    pwm -= negativeRange;
    const int16_t  IN_MIN = 500;
    const int16_t  IN_MAX = 2500;
    const uint16_t OUT_MIN = 0;
    const uint16_t OUT_MAX = 180;
    return (pwm - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint16_t HighLevelDriver::degToPwm(int16_t deg, int8_t negativeRange)
{
    deg += negativeRange;
    const int16_t  IN_MIN = 0;
    const int16_t  IN_MAX = 180;
    const uint16_t OUT_MIN = 500;
    const uint16_t OUT_MAX = 2500;
    return (deg - IN_MIN) * (OUT_MAX - OUT_MIN) / (IN_MAX - IN_MIN) + OUT_MIN;
}

uint8_t HighLevelDriver::getNegativeRangeForJoint(Joints joint)
{
    uint8_t negativeRange = 0;
    // If the map contains an entry for the given joint, return the set value
    if (negativeRanges.find(joint) != negativeRanges.end())
    {
        negativeRange = negativeRanges.at(joint);
    }
    return negativeRange;
}

bool HighLevelDriver::setOffset(Joints joint, int8_t offset)
{
    if(lowLevelDriver.setPositionOffset(joint, degToPwm(offset, getNegativeRangeForJoint(joint))))
    {
        jointOffsets[static_cast<uint8_t>(joint)] = offset;
        currentState = MachineStates::s_Configure;
        Logger::getInstance().log("INFO: {Joint " + std::to_string(static_cast<uint8_t>(joint)) + " krijgt een offset van " + std::to_string(offset) + " graden.}",e_DEBUG);
        return true;
    }
    else
    {
        Logger::getInstance().log("WARNING: {Joint " + std::to_string(static_cast<uint8_t>(joint)) + " kan niet worden ingesteld met een offset van " + std::to_string(offset) + " graden.}",e_WARNING);
    }    

    return false;
}

void HighLevelDriver::setCurrentState(MachineStates newState)
{
    currentState = newState;
}

HighLevelDriver::MachineStates HighLevelDriver::getCurrentState()
{
    return currentState;
}

void HighLevelDriver::runStateMachine()
{
    switch (currentState)
    {
    case MachineStates::s_Configure:
    {
        moveToInitPos();
        sendCommand();
        currentState = MachineStates::s_Idle;
        Logger::getInstance().log("EVENT: {Nieuwe configuratie}",e_DEBUG);
        Logger::getInstance().log("STATE: {DefaultPosition}",e_INFO);
        Logger::getInstance().log("EVENT: {Arm in start positie}",e_DEBUG);
        break;
    }
    case MachineStates::s_Idle:
    {
        break;
    }
    case MachineStates::s_Move:
    {
        if(timeDone <= std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()))
        {
            currentState = MachineStates::s_Idle;
            Logger::getInstance().log("STATE: {Idle}",e_INFO);
            Logger::getInstance().log("EVENT: {Arm in positie}",e_DEBUG);
        }
        break;
    }
    case MachineStates::s_End:
    {
        moveToInitPos();
        sendCommand();
        Logger::getInstance().log("STATE: {DefaultPosition}",e_INFO);
        Logger::getInstance().log("EVENT: {EndProgram ontvangen}",e_DEBUG);

        break;
    }
    case MachineStates::s_EmergencyStop:
    {
        lowLevelDriver.emergencyStop();
        Logger::getInstance().log("STATE: {EmergencyStop}",e_INFO);
        Logger::getInstance().log("EVENT: {EmergencyStop ontvangen}",e_DEBUG);
        while(true);
        break;
    }
    default:
        break;
    }
}

void HighLevelDriver::moveToInitPos()
{
    for(int i = 0; i != NUMBER_OF_JOINTS; ++i)
    {
        setJointAngle(static_cast<Joints>(i), initPositions[i], 50.0);
    }
}