#include "LowLevelDriver.hpp"

#include <iostream> // Wordt alleen gebruikt voor het debuggen van sendCommand

/// Reset de message string naar een lege string<br>
/// Voegt een standaard waarde van 500 toe aan ieder gewricht in de minPwm map.<br>
/// Voegt een standaard waarde van 2500 toe aan ieder gewricht in de maxPwm map.<br>
LowLevelDriver::LowLevelDriver()
{
    resetCommand();

    minPwm.insert(std::pair<Joints, int>(BASE, 500));
    minPwm.insert(std::pair<Joints, int>(SHOULDER, 500));
    minPwm.insert(std::pair<Joints, int>(ELBOW, 500));
    minPwm.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 500));
    minPwm.insert(std::pair<Joints, int>(GRIPPER, 500));
    minPwm.insert(std::pair<Joints, int>(WRIST_ROTATE, 500));

    maxPwm.insert(std::pair<Joints, int>(BASE, 2500));
    maxPwm.insert(std::pair<Joints, int>(SHOULDER, 2500));
    maxPwm.insert(std::pair<Joints, int>(ELBOW, 2500));
    maxPwm.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 2500));
    maxPwm.insert(std::pair<Joints, int>(GRIPPER, 2500));
    maxPwm.insert(std::pair<Joints, int>(WRIST_ROTATE, 2500));
}

/// Controleer of het gegeven gewricht een minimale en maximale waarde heeft.
/// Als één van deze waarden mist, voeg de waarde niet toe.<br>
/// Controleer of de gegeven PWM waarde binnen het toegestane bereik valt.
/// Als de PWM waarde buiten dit bereik valt, pas de waarde aan om binnen het bereik te passen.
/// Schrijf de waardes naar de wachtrij
void LowLevelDriver::setJointPwm(Joints joint, uint16_t pwm, uint16_t speed /* = 65535*/ )
{
    std::map<Joints, uint16_t>::iterator jointLowestAllowedPwmIndex, jointHighestAllowedPwmIndex;
    int channel;

    // Check if the given joint is in both the minPwm and maxPwm map
    jointLowestAllowedPwmIndex = minPwm.find(joint);
    jointHighestAllowedPwmIndex = maxPwm.find(joint);
    if (jointLowestAllowedPwmIndex == minPwm.end() ||
        jointHighestAllowedPwmIndex == maxPwm.end())
    {
        return;
    }

    // Check if the PWM value is within the allowed range.
    // If the PWM value is outside of the range, adjust the value to fit within the range.
    if (pwm < jointLowestAllowedPwmIndex->second)
    {
        pwm = jointLowestAllowedPwmIndex->second;
    }
    if (pwm > jointHighestAllowedPwmIndex->second)
    {
        pwm = jointHighestAllowedPwmIndex->second;
    }

    channel = joint;
    message += "#" + std::to_string(channel) +
                "P" + std::to_string(pwm) +
                "S" + std::to_string(speed);
}

void LowLevelDriver::setTimeToComplete(uint16_t timeInMs)
{
    message += "T" + std::to_string(timeInMs);
}

/// Zorg er voor dat de offset binnen 15 graden ligt. (15 * 65535 / 180)
bool LowLevelDriver::setPositionOffset(Joints joint, int16_t offset)
{
    int channel = joint;
    int16_t maxOffset = 15 * 65535 / 180;
    if (offset > maxOffset)
    {
        offset = maxOffset;
    }
    if (offset < - maxOffset)
    {
        offset = - maxOffset;
    }

    resetCommand();
    message += "#" + std::to_string(channel) +
                "PO" + std::to_string(offset);
    sendCommand();
}

bool LowLevelDriver::sendCommand()
{
    std::cout << "[TO ROBOT] " << message << '\n' << std::endl;
    resetCommand();
}

void LowLevelDriver::resetCommand()
{
    message = "";
}

void LowLevelDriver::emergencyStop()
{
    // TODO: Implement emergency stop
}

/// Controleer of het gewricht in de lijst met laagste waarden staat.<br>
/// Als het gewricht niet in de lijst staat, geef de hoogst mogelijke waarde terug.<br>
/// Staat het gewricht wel in de lijst, geef de waarde uit de lijst terug.
uint16_t LowLevelDriver::getMinPwm(Joints joint)
{
    std::map<Joints, uint16_t>::iterator index;

    index = minPwm.find(joint);
    if (index == minPwm.end())
    {
        return UINT16_MAX;
    }
    return index->second;
}

/// Controleer of het gewricht in de lijst met hoogste waarden staat.<br>
/// Als het gewricht niet in de lijst staat, geef 0 terug.<br>
/// Staat het gewricht wel in de lijst, geef de waarde uit de lijst terug.
uint16_t LowLevelDriver::getMaxPwm(Joints joint)
{
    std::map<Joints, uint16_t>::iterator index;

    index = maxPwm.find(joint);
    if (index == maxPwm.end())
    {
        return 0;
    }
    return index->second;
}