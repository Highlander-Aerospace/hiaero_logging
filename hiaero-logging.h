//
// Created by Cristian on 2020-10-23.
//

#include <string>

#ifndef HIAERO_DRONE_FLIGHT_COMPUTER_HIAERO_LOGGING_H
#define HIAERO_DRONE_FLIGHT_COMPUTER_HIAERO_LOGGING_H

extern double START_TIME;

double get_wall_time();
double nround(double x, int d);
void info(const std::string &msg);
void warning(const std::string &msg);
void error(const std::string &msg);
void trace();
void set_start_time();

#endif //HIAERO_DRONE_FLIGHT_COMPUTER_HIAERO_LOGGING_H
