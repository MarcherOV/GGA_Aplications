#include <cstdlib> // For system()
#include <iostream>
#include "gpio_module.h"

void initializeGPIO() {
    // Set GPIO 26 as output
    system("gpio -g mode 26 out");
}

void enableGNSSModule() {
    // Set GPIO 26 high to enable GNSS
    system("gpio -g write 26 1");
    std::cout << "GNSS module enabled (GPIO 26 set to high)." << std::endl;
}

void disableGNSSModule() {
    // Set GPIO 26 low to disable GNSS
    system("gpio -g write 26 0");
    std::cout << "GNSS module disabled (GPIO 26 set to low)." << std::endl;
}
