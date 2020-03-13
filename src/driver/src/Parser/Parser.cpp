#include "Parser.hpp"
#include <algorithm>

Parser::Parser()
{
    positionStrings.insert(std::pair<std::string, std::string>(
        "PARK",
        "B-45;T1000;"
    ));
    positionStrings.insert(std::pair<std::string, std::string>(
        "READY",
        "B0;T1000;"
    ));
    positionStrings.insert(std::pair<std::string, std::string>(
        "STRAIGHT",
        "B45;T1000;"
    ));

    stringsAsJoints.insert(std::pair<std::string, Joints>("B", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("S", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("E", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("W", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("G", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("R", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("WR", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("BASE", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("SHOULDER", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("ELBOW", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("WRIST", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("GRIPPER", BASE));
    stringsAsJoints.insert(std::pair<std::string, Joints>("WRIST_ROTATE", BASE));

    resetParser();
}

bool Parser::parseLine(std::string input)
{
    // Reset the parser until we can continue the parsing
    do
    {
        // Clear the temporary characters, like the working tokens vector
        resetParser();

        // Splits the input string into tokens in the vector
        splitStringInTokens(input);

        // Overwrite the string that will be parsed, reset parsing when a pre-defined position is detected
        if (parsePresetPositions() != "")
        {
            input = parsePresetPositions();
        }
    } while (parsePresetPositions() != ""); 

    // No tokens found in the input string, returning
    if (workingTokens.size() == 0)
    {
        return false;
    }

    // Check for an emergency stop command
    if (parseEmergencyStop())
    {
        sendEmergencyStopCmd();
        return true;
    }

    // Check if the current command is an CONFIG command
    if (workingTokens.at(0) == "CONF" || workingTokens.at(0) == "CONFIG")
    {
        if (parseConfig())
        {
            sendConfigCmd();
            return true;
        }
        return false;
    }
    else
    {
        if (parseMove())
        {
            sendMoveCmd();
            return true;
        }
        return false;
    }
}

void Parser::resetParser()
{
    workingTokens.clear();

    newAngles.clear();
    newAngles.insert(std::pair<Joints, int8_t>(BASE,          INT8_MAX));
    newAngles.insert(std::pair<Joints, int8_t>(SHOULDER,      INT8_MAX));
    newAngles.insert(std::pair<Joints, int8_t>(ELBOW,         INT8_MAX));
    newAngles.insert(std::pair<Joints, int8_t>(WRIST_UP_DOWN, INT8_MAX));
    newAngles.insert(std::pair<Joints, int8_t>(GRIPPER,       INT8_MAX));
    newAngles.insert(std::pair<Joints, int8_t>(WRIST_ROTATE,  INT8_MAX));

    newSpeeds.clear();
    newSpeeds.insert(std::pair<Joints, int8_t>(BASE,          100));
    newSpeeds.insert(std::pair<Joints, int8_t>(SHOULDER,      100));
    newSpeeds.insert(std::pair<Joints, int8_t>(ELBOW,         100));
    newSpeeds.insert(std::pair<Joints, int8_t>(WRIST_UP_DOWN, 100));
    newSpeeds.insert(std::pair<Joints, int8_t>(GRIPPER,       100));
    newSpeeds.insert(std::pair<Joints, int8_t>(WRIST_ROTATE,  100));

    timeToComplete = 0;
}

void Parser::splitStringInTokens(std::string input)
{
    std::string workingString = "";

    for (int charIter = 0; charIter < input.length(); charIter++)
    {
        // Check if the currently selected character is an delimiter
        bool isCharacterDelimiter = false;
        for (int delimiterIter = 0; delimiterIter < knownTokenDelimiters.size(); delimiterIter++)
        {
            if (input.at(charIter) == knownTokenDelimiters.at(delimiterIter))
            {
                isCharacterDelimiter = true;
                break;
            }
        }

        // If the selected char is a delimiter, send the current string to the token list
        //  and clear the current string
        if (isCharacterDelimiter)
        {
            if (workingString.size() != 0)
            {
                workingTokens.push_back(workingString);
                workingString = "";
            }
        }
        // If the selected char is not a delimiter, append the character to the working string
        else
        {
            workingString += input.at(charIter);
        }
    }

    if (workingString.size() != 0)
    {
        workingTokens.push_back(workingString);
    }
}

std::string Parser::parsePresetPositions()
{
    // Return if no tokens were found
    if (workingTokens.size() == 0)
    {
        return "";
    }

    // Compare the first token against all known pre-set positions
    for (auto combination : positionStrings)
    {
        if (combination.first == workingTokens.at(0))
        {
            return combination.second;
        }
    }

    return "";
}

bool Parser::parseEmergencyStop()
{
    // Don't parse if no tokens are available
    if (workingTokens.size() == 0)
    {
        return false;
    }

    // Read the first token, convert it to uppercase
    std::string firstToken = stringToUpper(workingTokens.at(0));

    // Loop through all possible variations of the emergency stop command
    for (auto stopCommand : knownEmergencyStopCommands)
    {
        // If the command matches a known stop command, return true
        if (stopCommand == firstToken)
        {
            return true;
        }
    }
    // Return false when no matches were found
    return false;
}

bool Parser::parseConfig()
{
    std::string jointAsString = "", offsetAsString = "";
    Joints selectedJoint = UNKNOWN;
    int8_t offset = 0;

    for (auto token : workingTokens)
    {
        // Reset variables
        jointAsString = "";
        offsetAsString = "";
        selectedJoint = UNKNOWN;
        offset = 0;

        // Convert to uppercase, to make parsing easier
        token = stringToUpper(token);

        // Add every character to either the joint string or the offset string
        for (auto character : token)
        {
            // Part of the joint
            if (character >= 65 && character <= 90)
            {
                jointAsString += character;
            }
            // Part of the offset
            else
            {
                offsetAsString += character;
            }
        }

        selectedJoint = stringToJoint(jointAsString);
        try
        {
            offset = std::stoi(offsetAsString);
        }
        catch(...)
        {
            return false;
        }

        if (selectedJoint == UNKNOWN ||
            offset > 15 ||
            offset < -15)
        {
            return false;
        }

        auto iter = newAngles.find(selectedJoint);
        if (iter != newAngles.end())
        {
            iter->second = offset;
        }
    }

    return true;
}

bool Parser::parseMove()
{
    std::string jointAsString = "", degreesAsString = "", speedAsString = "";
    Joints selectedJoint = UNKNOWN;
    int8_t degrees = 0, speed = INT8_MAX;

    for (auto token : workingTokens)
    {
        // Reset variables
        jointAsString = "";
        degreesAsString = "";
        speedAsString = "";
        selectedJoint = UNKNOWN;
        degrees = INT8_MAX;
        speed = INT8_MAX;

        if (token[0] == 'T')
        {
            try
            {
                timeToComplete = std::stoi(token.substr(1, token.length() - 1));
            }
            catch(...)
            {
                return false;
            }
            continue;
        }

        // Convert to uppercase, to make parsing easier
        token = stringToUpper(token);

        // Add every character to either the joint string or the offset string
        bool isParsingUpToDegrees = true;
        for (auto character : token)
        {
            // Part of the joint
            if (character >= 65 && character <= 90)
            {
                jointAsString += character;
            }
            // Part of the degrees
            else
            {
                if (character == ',')
                {
                    isParsingUpToDegrees = false;
                    continue;
                }
                if (isParsingUpToDegrees)
                {
                    degreesAsString += character;
                }
                else
                {
                    speedAsString += character;
                }
                
            }
        }

        selectedJoint = stringToJoint(jointAsString);
        try
        {
            degrees = std::stoi(degreesAsString);
        }
        catch(...)
        {
            return false;
        }

        if (speedAsString.length() > 0)
        {
            try
            {
                speed = std::stoi(speedAsString);
            }
            catch(...)
            {
                return false;
            }
        }
        
        if (selectedJoint == UNKNOWN ||
            degrees == INT8_MAX)
        {
            return false;
        }

        auto iter = newAngles.find(selectedJoint);
        if (iter != newAngles.end())
        {
            iter->second = degrees;
        }

        if (speed != INT8_MAX)
        {
            auto iter = newSpeeds.find(selectedJoint);
            if (iter != newSpeeds.end())
            {
                iter->second = speed;
            }
        }
    }

    return true;
}

std::string Parser::stringToUpper(std::string originalString)
{
    std::transform(originalString.begin(), originalString.end(), originalString.begin(), ::toupper);
    return originalString;
}

Joints Parser::stringToJoint(std::string jointAsString)
{
    jointAsString = stringToUpper(jointAsString);

    for (auto jointStringCombination : stringsAsJoints)
    {
        if (jointStringCombination.first == jointAsString)
        {
            return jointStringCombination.second;
        }
    }

    return UNKNOWN;
}