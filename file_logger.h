#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <string>

// Function to create a filename with a timestamp if no base name is provided
std::string createFileName(const std::string& baseName);

// Function to log all responses to the log file
void logAllResponses(const std::string& data);

// Function to log GNSS data to the GPS file
void logGNSSData(const std::string& data, const std::string& dataType);

// Function to log GGA data and generate a URL based on coordinates
void logGGAData(const std::string& ggaData);

// Global variable declarations for log file names
extern std::string logFileName;  // Name of the log file for all responses
extern std::string ggaFileName;  // Name of the file for GGA data
extern std::string gpsFileName;  // Name of the file for all GPS data

#endif // FILE_LOGGER_H
