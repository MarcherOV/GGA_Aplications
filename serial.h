// serial.h

#ifndef SERIAL_H
#define SERIAL_H

#include <iostream>

int openSerialPort(const char* portname);
bool configureSerialPort(int fd, int speed);
void closeSerialPort(int fd);
void readData(int fd);
int initializeSerialPort(const char* portname, int baudrate);

#endif // SERIAL_H
