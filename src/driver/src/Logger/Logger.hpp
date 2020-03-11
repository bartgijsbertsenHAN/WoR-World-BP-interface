#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <map>
#include <mutex>
#include <ros/console.h>

/// @brief The enum describes all possible Loglevels
enum LogLevel {
    e_DEBUG,
    e_INFO,
    e_WARNING,
    e_ERROR,
    e_FATAL
};

/// @brief The logger class is responsible for logging to the ROSOUT stream.
///         The logger uses the INFO, DEBUG, and WARNING levels of ROS.
//          The logger class implements the Singleton design pattern (see https://stackoverflow.com/a/1008289)
class Logger
{
public:
    /// @brief This method is used to get a reference to the Logger class.
    ///         The constructor is unavailable because it is a singleton.
    /// @return A reference to the Logger class
    static Logger& getInstance();

    // Prevent copies
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

    /// @brief The log function sends a string to the provided ROSOUT level.
    /// @param text The string that should be sent to ROSOUT
    /// @param logLevel The LogLevel (INFO, DEBUG, WARNING, but ERROR and FATAL are also supported)
    /// @param copyToStdOut When set to true, copies the message to standard output, prefixed with the loglevel
    ///          (default = true)
    /// @return True when the message could be send, false when an recoverable
    ///          error prevented the message from being sent
    bool log(std::string text, LogLevel logLevel, bool copyToStdOut = true);

private:
    /// @brief Constructor, currently empty
    Logger();

    static std::mutex mtx;

    ros::NodeHandle n;
    ros::Publisher log_publisher;

    /// @brief The logToStdOut function sends a string to the standard output.
    /// @param text The string that should be sent to ROSOUT
    /// @param logLevel The LogLevel (INFO, DEBUG, WARNING, but ERROR and FATAL are also supported)
    void logToStdOut(std::string text, LogLevel loglevel);

    /// Stores the names for the different log levels as strings
    const std::map<LogLevel, std::string> loglevelsAsStrings = {
        {e_DEBUG,   "DEBUG"},
        {e_INFO,    "INFO"},
        {e_WARNING, "WARNING"},
        {e_ERROR,   "ERROR"},
        {e_FATAL,   "FATAL"}
    };
};

#endif