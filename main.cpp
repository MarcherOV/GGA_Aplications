#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <sstream>
#include <fstream>
#include "gnss.h"
#include "serial.h"
#include "gpio_module.h"
#include "file_logger.h"
#include "map_url_generator.h"

using namespace std;

int fd;  
bool ggaOnly = false;  
string logFileName; 
string ggaFileName; 
string gpsFileName; 

// Signal handler to handle Ctrl+C (SIGINT)
void signalHandler(int signum) {
    cout << "\nProgram interrupted (Ctrl+C detected)." << endl;

    // Attempt to disable GNSS on program exit
    if (!disableGNSS(fd)) {
        logAllResponses("Failed to disable GNSS on program exit.");
        cerr << "Failed to disable GNSS." << endl;
    } else {
        logAllResponses("GNSS disabled successfully on program exit.");
        cout << "GNSS disabled." << endl;
    }

    // Ask user if they want to power off the GPS module
    cout << "Do you want to power off the entire GPS module? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        disableGNSSModule();  // Power off the GNSS module using GPIO
        logAllResponses("GPS module powered off (GPIO 26 set to low).");
        cout << "GPS module powered off." << endl;
    } else {
        logAllResponses("GPS module remains powered on (GPIO 26 remains high).");
        cout << "GPS module remains powered on." << endl;
    }

    closeSerialPort(fd); // Close the serial port
    exit(signum);        // Exit the program
}

// Function to continuously retrieve GNSS data every 2 seconds
void continuousDataRetrieval() {
    char response[4092];  // Buffer for GNSS data

    while (true) {
        // Attempt to get GNSS data
        if (getGNSSData(fd, response, sizeof(response))) {
            cout << "GNSS Data: " << response << endl;  // Print GNSS data to console
        } else {
            string errorMsg = "Failed to read GNSS data.";
            logAllResponses(errorMsg);  // Log the error if reading fails
            cerr << errorMsg << endl;
        }
        usleep(2000000);  // Sleep for 2 seconds
    }
}

// Menu for controlling GNSS module
void displayMenu() {
    bool running = true;

    while (running) {
        cout << "\nGNSS Module Control Menu:\n";
        cout << "1. Start retrieving all data\n"; 
        cout << "2. Stop data retrieval\n";
        cout << "3. Exit program\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                ggaOnly = false;  
                cout << "Starting data retrieval for all data...\n";
                continuousDataRetrieval();  // Start retrieving data
                break;

            case 2:
                cout << "Stopping data retrieval.\n";
                return;  // Stop data retrieval and return to the menu

            case 3:
                cout << "Exiting program...\n";
                running = false;  // Exit the program
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}

// Main function
int main() {
    // Set up signal handler for Ctrl+C
    signal(SIGINT, signalHandler);

    // Initialize GPIO and power on the GNSS module
    initializeGPIO();
    enableGNSSModule();

    // Open serial port for communication with GNSS module
    fd = initializeSerialPort("/dev/ttyAMA0", 9600);
    if (fd == -1) {
        return 1;  // If opening the port fails, exit with error
    }

    // Enable GNSS module
    if (!enableGNSS(fd)) {
        logAllResponses("Failed to enable GNSS.");
        cerr << "Failed to enable GNSS." << endl;
    } else {
        logAllResponses("GNSS enabled successfully.");
        cout << "GNSS enabled." << endl;
    }

    // Ask the user for a log file name
    cout << "Enter log file name (leave empty for default): ";
    string customLogFileName;
    cin.ignore();  // Clear input buffer
    getline(cin, customLogFileName);
    logFileName = createFileName(customLogFileName);  // Create log file name
    ggaFileName = "gga_" + logFileName;  // Create GGA log file name
    gpsFileName = "gps_" + logFileName;  // Create GPS log file name

    // Display the menu for controlling the GNSS module
    displayMenu();

    // Handle SIGINT for graceful shutdown
    signalHandler(SIGINT);  
    return 0;
}
