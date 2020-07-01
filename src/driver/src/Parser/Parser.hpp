#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <string>
#include "ros/ros.h"
#include "../Driver/DriverEnums.hpp"
#include "../control_node.hpp"

class Parser
{
public:
    /// @brief Initialises the internal variables of the parser
    Parser();

    /// @brief Parses a string by calling the necessary functions from the Parser class
    /// @param input The string that should be parsed
    bool parseLine(std::string input);

    /// @brief The function resets all temporary variables in the parser
    ///  Call this function before parsing to ensure that no
    ///  variables contain values from a previous parsing
    void resetParser();

    /// @brief The function splits the inputstring on all known
    ///  delimiters and writes the tokens to the workingTokens vector
    /// @param input The string that should be split
    void splitStringInTokens(std::string input);

    /// @brief The function uses the workingTokens vector to check
    ///  if any of the pre-set positions is called
    /// @details Make sure that the input is split into tokens
    ///  (in the workingTokens vector) as this is where the function gets its data from.
    /// @return A new string, which represents the user input needed to send 
    ///  the arm to the requested position, when a valid position was found.
    ///  An empty string when no valid position was found
    std::string parsePresetPositions();

    /// @brief The function checks if the first token in the token list (workingTokens)
    ///  contains any of the emergency stop descriptions
    /// @return True when an emergency stop was detected, otherwise false
    bool parseEmergencyStop();

    /// @brief The function tries to parse a config command in the workingTokens vector
    /// @details Make sure that the workingTokens vector is filled
    ///  with the token before running this method
    /// @return True when the parsing was successfull, false when an error occurred
    bool parseConfig();

    /// @brief The function tries to parse a move command in the workingTokens vector
    /// @details Make sure that the workingTokens vector is filled
    ///  with the token before running this method
    /// @return True when the parsing was successfull, false when an error occurred
    bool parseMove();

    /// @brief Removes items from the map that are not used
    /// @details The elements from the maps from the Parser instance that do not have
    ///    a new value are deleted before the map is used to send data to the driver.
    void clearUnusedMapItems();

    /// @brief Converts a string to its uppercase representation
    /// @param originalString The original string
    /// @return The uppercase representation of the string
    std::string stringToUpper(std::string originalString);

    /// @brief Converts a string (which represents a joint) to an
    ///  instance of the Joints enum (from the driver)
    /// @param jointAsString A string representing a joint
    /// @return An instance of the Joints enum from the Driver package
    Joints stringToJoint(std::string jointAsString);

    /// @brief A map that stores the new angle for every joint
    std::map<Joints, int16_t> newAngles;
    
    /// @brief A map that stores the new speed for every joint
    std::map<Joints, int8_t> newSpeeds;

    /// An integer that stores the time in milliseconds that the entire movement should take
    uint16_t timeToComplete;

private:
    /// The map maps the strings that the user sends to pre-defined
    ///  strings that send the arm to a pre-defined position
    std::map<std::string, std::string> positionStrings;

    std::map<std::string, Joints> stringsAsJoints;

    // Array containing all possible delimiters. Std::array allows for easier looping
    const std::array<char, 2> knownTokenDelimiters = {';', ' '};

    // Array containing all known representations of the emergency stop command.
    //  Std::array allows for easier looping
    const std::array<std::string, 3> knownEmergencyStopCommands = {
        "STOP",
        "EMERGENCY",
        "EMERGENCY_STOP"
    };

    /// This vector stores all tokens that have been found in the string.
    std::vector<std::string> workingTokens;
};

#endif