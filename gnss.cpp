#include "gnss.h"
#include "serial.h" // Include your serial functions
#include "file_logger.h" // Include the logger functions
#include <unistd.h> // For usleep
#include <cstring>  // For strlen, strncpy
#include <iostream>
#include <sstream>  // For parsing GGA data

using namespace std;

// Send AT command and read response
bool sendATCommand(int fd, const char* command, char* response, size_t responseSize) {
    // Write the command to the serial port
    write(fd, command, strlen(command));
    usleep(500000); // Wait for half a second to allow the module to respond

    // Read response from the serial port
    ssize_t bytesRead = read(fd, response, responseSize - 1); // Leave space for null terminator
    if (bytesRead < 0) {
        cerr << "Failed to read from serial port." << endl;
        return false; // Reading failed
    }

    response[bytesRead] = '\0'; // Null-terminate the response
    logAllResponses(response); // Log the response
    return true; // Return true for success
}

// Check if GNSS is enabled
//bool isGNSSEnabled(int fd) {
    //const char* checkGNSS = "AT+QGNSS?\r"; // Command to check GNSS status
    //char response[256];

    //if (!sendATCommand(fd, checkGNSS, response, sizeof(response))) {
        //cerr << "Failed to check GNSS status." << endl;
        //return false;
    //}
    
    //return strstr(response, "1") != nullptr; // Check for "1" in response
//}

// Enable GNSS
bool enableGNSS(int fd) {
    const char* enableCommand = "AT+QGNSSC=1\r"; // Command to enable GNSS
    char response[256];

    if (!sendATCommand(fd, enableCommand, response, sizeof(response))) {
        cerr << "Failed to enable GNSS." << endl;
        return false;
    }

    return true; // Return true on success
}

// Disable GNSS
bool disableGNSS(int fd) {
    const char* disableCommand = "AT+QGNSSC=0\r"; // Command to disable GNSS
    char response[256];

    if (!sendATCommand(fd, disableCommand, response, sizeof(response))) {
        cerr << "Failed to disable GNSS." << endl;
        return false;
    }

    return true; // Return true on success
}

// Get GNSS data
bool getGNSSData(int fd, char* response, size_t responseSize) {
    const char* getDataCommand = "AT+QGNSSRD?\r"; // Command to read GNSS data

    if (!sendATCommand(fd, getDataCommand, response, responseSize)) {
        cerr << "Failed to get GNSS data." << endl;
        return false;
    }

    // Now parse the response for GGA and GPS data
    std::istringstream responseStream(response);
    std::string line;

    while (std::getline(responseStream, line)) {
        // Log GGA data
        if (line.find("$GNGGA") != std::string::npos) {
            logGGAData(line); // Log GGA data and generate URL
        }
        // Log GPS data
        else if (line.find("$GNRMC") != std::string::npos || line.find("$GNVTG") != std::string::npos ||
                 line.find("$GPGSA") != std::string::npos || line.find("$GPGSV") != std::string::npos || 
                 line.find("$GNGLL") != std::string::npos || line.find("$GLGSA") != std::string::npos ||
                 line.find("$GLGSV") != std::string::npos) {
            logGNSSData(line, "GPS"); // Log GPS data
        }
    }

    return true; // Return true on success
}
