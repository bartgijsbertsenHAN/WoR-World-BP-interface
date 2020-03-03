#pragma once

#include "DriverEnums.hpp"

/// @brief Interface voor het programma om te communiceren met de robotarm
class IDriver
{
public:
    /// @brief Voegt de nieuwe hoek van het gewricht toe aan de wachtrij voor de robotarm
    /// @param joint De enum waarde van het gewricht wat bewogen moet worden
    /// @param degrees De nieuwe hoek voor het gewricht
    /// @param speedInPercent De maximale snelheid van het gewricht in een percentage
    virtual void setJointAngle(Joints joint, uint16_t degrees, float speedInPercent = 100.0) = 0;

    /// @brief Stelt de minimale tijd in waarin de beweging wordt afgerond
    /// @param timeInMs De tijd die de volledige beweging nodig heeft om af te ronden 
    virtual void setTimeToComplete(int timeInMs) = 0;

    /// @brief Verstuurt de wachtrij naar de robot. Alle gewrichten zullen tegelijk bewegen.
    /// @return True als het commando wordt verstuurt, false als er een fout is opgetreden.
    virtual bool startMovement() = 0;

    /// @brief Reset de wachtrij voor de robotarm
    virtual void resetQueue() = 0;

    /// @brief Geeft de voortgang van de beweging in percentages
    /// @return Een percentage wat de voortgang van de beweging representeert (0 - 100)
    virtual float getProgressInPercent() = 0;

    /// @brief Noodstop. Stopt de beweging van de robotarm onmiddelijk.
    virtual void emergencyStop() = 0;

    /// @brief Vraagt de laagst toegestane hoek van een gegeven gewricht op
    /// @param joint De enum waarde van een gewricht
    /// @return De minimale hoek van het gewricht
    virtual uint16_t getMinAngle(Joints joint) = 0;

    /// @brief Vraagt de hoogst toegestane hoek van een gegeven gewricht op
    /// @param joint De enum waarde van een gewricht
    /// @return De maximale hoek van het gewricht
    virtual uint16_t getMaxAngle(Joints joint) = 0;
};