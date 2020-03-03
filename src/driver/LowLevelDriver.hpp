#pragma once

#include <cstdint>
#include <string>
#include <map>
#include <boost/asio.hpp>
#include "DriverEnums.hpp"

/// @brief Deze klasse beheert direct de communicatie met de robotarm, zonder functionaliteit toe te voegen
class LowLevelDriver
{
public:
    /// @brief De constructor initialiseert de klassevariabelen
    /// @param port The port to send the commands to
    LowLevelDriver(std::string port);

    /// @brief Deze functie voegt de gewenste hoek van het meegegeven gewricht toe aan de wachtrij voor de robotarm
    /// @param joint De enum waarde van het gewricht waar het commando naar toe wordt gestuurd
    /// @param pwm De PWM waarde die naar de servo wordt geschreven aan het einde van de beweging
    /// @param speed De maximale snelheid van de servo gedurende de beweging
    void setJointPwm(Joints joint, uint16_t pwm, uint16_t speed = 65535);

    /// @brief De functie stelt de tijd in waarin de arm de beweging uitvoert.
    /// Roep deze functie aan als laatste functie voor sendCommand wordt aangeroepen.
    /// @param timeInMs De tijd in milliseconden waarin de beweging minimaal moet worden uitgevoerd
    void setTimeToComplete(uint16_t timeInMs);

    /// @brief Schrijft een offset van de servo naar het geheugen van de robotarm. Deze wordt gereset bij opnieuw opstarten.
    /// @param joint De enum waarde van het gewricht wat wordt gekalibreerd
    /// @param offset De offset voor het gewricht als PWM waarde
    /// @return True als het bericht kan worden verzonden, false als het niet kan worden verzonden
    bool setPositionOffset(Joints joint, int16_t offset);

    /// @brief Verstuurt het commando wat in de wachtrij staat, reset de wachtrij
    /// @return True als het bericht kan worden verzonden, false als het niet kan worden verzonden
    bool sendCommand();

    /// @brief Reset de wachtrij naar een lege string
    void resetCommand();

    /// @brief Stopt onmiddelijk alle beweging van de robotarm
    void emergencyStop();

    /// @brief Vraagt de laagst toegestane hoek van een gegeven gewricht op
    /// @param joint Het gewricht als een enum waarde
    /// @return Geeft de laagst toegestane hoek terug
    uint16_t getMinPwm(Joints joint);

    /// @brief Vraagt de hoogst toegestane hoek van een gegeven gewricht op
    /// @param joint Het gewricht als een enum waarde
    /// @return Geeft de hoogst toegestane hoek terug
    uint16_t getMaxPwm(Joints joint);

private:
    /// @brief Slaat een lijst op met alle laagst toegestane waarden
    std::map<Joints, uint16_t> minPwm;

    /// @brief Slaat een lijst op met alle hoogst toegestane waarden
    std::map<Joints, uint16_t> maxPwm;

    /// @brief Slaat het bericht op terwijl het wordt opgebouwd, tot het wordt verzonden. (De wachtrij)
    std::string message;

    /// @brief Slaat de port op als een string
    std::string port;
};