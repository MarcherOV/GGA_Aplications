#English# version
# GNSS Logger (made by 5623)
##Project Overview
This program connects to a GNSS module (model used: MC60), paired with an antenna (e.g., Mitcom), to collect and log location data. It records the full range of data as well as GGA format messages in log files, with URL links for visualizing coordinates on Google Maps.
#Key Functionality
    Startup Checks: The program verifies the GNSS module status on startup and activates it if necessary.
    File Naming: Users can specify a custom file name. By default, the file is named with the date and time.
    Data Logging: The program generates and stores three separate files:
        log_name.txt - all program activities.
        gps_name.txt - all received data.
        gga_name.txt - GGA format data (lines with $GGA).
    Shutdown: Pressing Ctrl+C ends the program, automatically turning off the GNSS interface and offering the option to fully power down the GNSS module.
#Known Issues (Bugs)
    Serial Port Busy (picocom): If another process, such as picocom, occupies the serial port, the program will not work correctly. It is recommended to stop the picocom process before running this program.
    First Character of Filename: Sometimes, the first character of the file name input is "eaten." To avoid this, enter the name from the second character or repeat the first character.
#Compilation Instructions
Use the following command to compile the executable file:
g++ -o Your_name main.cpp gnss.cpp gpio_module.cpp file_logger.cpp map_url_generator.cpp serial.cpp -I.
#Creating an Alias for Quick Access
On Linux, you can create an alias for easy program access (in this case, named GNSS).
Open the .bashrc file (or .zshrc, depending on your terminal) in your home directory:
nano ~/.bashrc
Add the following line:
alias gnss_run='/path/to/GNSS'
Replace '/path/to/GNSS' with the path to your directory.
