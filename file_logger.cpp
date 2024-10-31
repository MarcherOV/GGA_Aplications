#include "file_logger.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include "map_url_generator.h"  // For URL generation
#include <string>

extern std::string logFileName;  // Name of the log file for all responses
extern std::string ggaFileName;  // Name of the file for GGA data
extern std::string gpsFileName;  // Name of the file for all GPS data

std::string createFileName(const std::string& baseName) {
    if (!baseName.empty()) {
        return baseName + ".txt";  // Return custom name with .txt extension
    }
    // Get current date and time
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtm);  // Format as YYYYMMDD_HHMMSS
    return std::string(buffer) + "_gps.txt"; // Default name
}

// Function to log all responses to logFileName
void logAllResponses(const std::string& data) {
    std::ofstream logFile(logFileName, std::ios::app);  // Open file in append mode
    if (logFile.is_open()) {
        logFile << data << std::endl;  // Write data to the file
        logFile.close();
    } else {
        std::cerr << "Failed to open file " << logFileName << " for writing." << std::endl; // Error message
    }
}

// Function to log GNSS data to gpsFileName
void logGNSSData(const std::string& data, const std::string& dataType) {
    std::ofstream gpsLogFile(gpsFileName, std::ios::app);  // Open file in append mode
    if (gpsLogFile.is_open()) {
        gpsLogFile << std::endl; // Add an empty line for spacing
        gpsLogFile << data << std::endl;  // Write data to the file
        gpsLogFile.close();
    } else {
        std::cerr << "Failed to open file " << gpsFileName << " for writing." << std::endl; // Error message
    }
}

// Function to log GGA data and generate URL
void logGGAData(const std::string& ggaData) {
    std::ofstream ggaLogFile(ggaFileName, std::ios::app); // Open file in append mode
    if (!ggaLogFile) {
        std::cerr << "Failed to open file " << ggaFileName << " for writing." << std::endl;
        return;
    }

    // Process GGA data
    if (ggaData.find("$GNGGA") != std::string::npos) {
        ggaLogFile << ggaData << std::endl; // Write only lines with $GNGGA
    }

    // Log GGA data to gpsFileName
    logGNSSData(ggaData, "GGA");

    // Generate map URL based on coordinates (only for logging)
    std::istringstream iss(ggaData);
    std::string token;
    double latitude = 0.0;
    double longitude = 0.0;

    std::getline(iss, token, ','); // Skip first three elements
    std::getline(iss, token, ','); // Skip the third element
    std::getline(iss, token, ','); // Skip the fourth element
    std::string latDirection;
    std::getline(iss, latDirection, ','); // Latitude direction
    std::getline(iss, token, ','); // Skip the fifth element
    std::string lonDirection;
    std::getline(iss, lonDirection, ','); // Longitude direction

    // Convert coordinates to double
    if (!token.empty() && latDirection == "N") {
        latitude = std::stod(token);
    } else if (!token.empty() && latDirection == "S") {
        latitude = -std::stod(token);
    }

    if (!token.empty() && lonDirection == "E") {
        longitude = std::stod(token);
    } else if (!token.empty() && lonDirection == "W") {
        longitude = -std::stod(token);
    }

    // Generate URL
    std::string mapURL = generateMapURL(latitude, longitude);
    logAllResponses("Map URL: " + mapURL); // Log the URL
}
