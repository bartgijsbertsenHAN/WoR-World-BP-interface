#include "LowLevelDriver.hpp"

#include <iostream> // Wordt alleen gebruikt voor het debuggen van sendCommand

/// Reset de message string naar een lege string<br>
/// Voegt een standaard waarde van 500 toe aan ieder gewricht in de minPwm map.<br>
/// Voegt een standaard waarde van 2500 toe aan ieder gewricht in de maxPwm map.<br>
LowLevelDriver::LowLevelDriver(std::string port)
    :minPwm(), maxPwm(), message(), port(port), absMaxOffset(100)
{
    resetCommand();

    minPwm.insert(std::pair<Joints, int>(BASE, 500));
    minPwm.insert(std::pair<Joints, int>(SHOULDER, 500));
    minPwm.insert(std::pair<Joints, int>(ELBOW, 500));
    minPwm.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 500));
    minPwm.insert(std::pair<Joints, int>(GRIPPER, 500));
    minPwm.insert(std::pair<Joints, int>(WRIST_ROTATE, 500));

    maxPwm.insert(std::pair<Joints, int>(BASE, 2500));
    maxPwm.insert(std::pair<Joints, int>(SHOULDER, 1833));
    maxPwm.insert(std::pair<Joints, int>(ELBOW, 2000));
    maxPwm.insert(std::pair<Joints, int>(WRIST_UP_DOWN, 2500));
    maxPwm.insert(std::pair<Joints, int>(GRIPPER, 2500));
    maxPwm.insert(std::pair<Joints, int>(WRIST_ROTATE, 2500));
}

/// Controleer of het gegeven gewricht een minimale en maximale waarde heeft.
/// Als één van deze waarden mist, voeg de waarde niet toe.<br>
/// Controleer of de gegeven PWM waarde binnen het toegestane bereik valt.
/// Als de PWM waarde buiten dit bereik valt, pas de waarde aan om binnen het bereik te passen.
/// Schrijf de waardes naar de wachtrij
bool LowLevelDriver::setJointPwm(Joints joint, uint16_t pwm, uint16_t speed /* = 65535*/ )
{
    std::map<Joints, uint16_t>::iterator jointLowestAllowedPwmIndex, jointHighestAllowedPwmIndex;
    int channel;

    // Check if the given joint is in both the minPwm and maxPwm map
    jointLowestAllowedPwmIndex = minPwm.find(joint);
    jointHighestAllowedPwmIndex = maxPwm.find(joint);
    if (jointLowestAllowedPwmIndex == minPwm.end() ||
        jointHighestAllowedPwmIndex == maxPwm.end())
    {
        return false;
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
    return true;
}

void LowLevelDriver::setTimeToComplete(uint16_t timeInMs)
{
    message += "T" + std::to_string(timeInMs);
}


bool LowLevelDriver::setPositionOffset(Joints joint, int8_t offset)
{
    int channel = joint;
    // int16_t maxOffset = 15 * 65535 / 180;
    if (abs(offset) > absMaxOffset)
    {
        return false;
    }
   

    resetCommand();
    message += "#" + std::to_string(channel) +
                "PO" + std::to_string(offset);
    return true;
}

bool LowLevelDriver::sendCommand()
{
    // std::cout << "[TO ROBOT] " << message << '\n' << std::endl;
    boost::asio::io_service ioservice;
	boost::asio::serial_port serial(ioservice, port);

	serial.set_option(boost::asio::serial_port_base::baud_rate(9600));
	serial.set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none));
	serial.set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none));
	serial.set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one));
	serial.set_option(boost::asio::serial_port::character_size(boost::asio::serial_port::character_size(8)));

    boost::asio::streambuf b;
    std::ostream os(&b);
    os << message << "\r";
    boost::asio::write(serial, b.data());
    os.flush();

    if (serial.is_open()) {
        serial.close();
    }


    resetCommand();
}

void LowLevelDriver::resetCommand()
{
    message = "";
}

void LowLevelDriver::emergencyStop()
{
    message = "STOP";
    sendCommand();
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