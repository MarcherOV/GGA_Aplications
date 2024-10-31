#ifndef GNSS_H
#define GNSS_H

#include <string>

// bool isGNSSEnabled(int fd);
bool enableGNSS(int fd);
bool getGNSSData(int fd, char* response, size_t size);
bool disableGNSS(int fd); // Add function to disable GNSS

#endif // GNSS_H
