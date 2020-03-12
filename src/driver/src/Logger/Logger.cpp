#include <iostream>
#include "Logger.hpp"
#include "ros/ros.h"
#include "std_msgs/String.h"

// Initialise the mutex, because it is a static variable
std::mutex Logger::mtx;

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

Logger::Logger()
{
    // ros::init(0, [], "talker");
    // log_publisher = n.advertise<std_msgs::String>("driver_log", 5);
}

bool Logger::log( std::string text, LogLevel logLevel, bool copyToStdOut)
{
    std_msgs::String msg;
    msg.data = text;
    ros::NodeHandle handler;
    

    mtx.lock();
    switch (logLevel)
    {
        case e_DEBUG:
        {
            ROS_DEBUG("%s", text.c_str());
            break;
        }
        case e_INFO:
        {
            ROS_INFO("%s", text.c_str());
            break;
        }
        case e_WARNING:
        {
            ROS_WARN("%s", text.c_str());
            break;
        }
        case e_ERROR:
        {
            ROS_ERROR("%s", text.c_str());
            break;
        }
        case e_FATAL:
        {
            ROS_FATAL("%s", text.c_str());
            break;
        }
        default:
        {
            ROS_FATAL("Invalid log level used when logging to ROSOUT.");
            throw std::invalid_argument("Invalid argument");
        }
    }

    if (copyToStdOut)
    {
        logToStdOut(text, logLevel);
    }
    mtx.unlock();
}

void Logger::logToStdOut(std::string text, LogLevel loglevel)
{
    int charsInLongestWord = 0, charsInSelectedWord = 0;

    for (auto logLevelWithString : loglevelsAsStrings)
    {   
        // Update charsInLongestWord
        if (logLevelWithString.second.length() > charsInLongestWord)
        {
            charsInLongestWord = logLevelWithString.second.length();
        }

        // Update charsInSelectedWord
        if (logLevelWithString.first == loglevel)
        {
            charsInSelectedWord = logLevelWithString.second.length();
        }
    }

    if (charsInSelectedWord == 0)
    {
        return;
    }

    std::cout << "[" << loglevelsAsStrings.find(loglevel)->second << "] ";
    for (int i = 0; i < charsInLongestWord - charsInSelectedWord; i++)
    {
        std::cout << " ";
    }
    std::cout << text << std::endl;
}