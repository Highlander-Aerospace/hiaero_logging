//
// Created by Cristian on 2020-10-23.
//

#include "hiaero-logging.h"
#include <string>
#include <ctime>
#include <sys/time.h>
#include <cmath>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <chrono>

double START_TIME;

double get_wall_time() {
    struct timeval time{};
    if (gettimeofday(&time,nullptr)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

double nround(double x, int d) {
    return round(x*pow(10, d))/pow(10, d);
}

void info(const std::string& msg) {
    printf("\033[38;5;075m[%8.3f] INFO:     %s\033[0m\n", nround(get_wall_time()-START_TIME, 3), msg.c_str());
}

void warning(const std::string& msg) {
    printf("\033[38;5;202m\033[1m[%8.3f] WARNING:     %s\033[0m\033[0m\n", nround(get_wall_time()-START_TIME, 3), msg.c_str());
}

void error(const std::string& msg) {
    printf("\033[38;5;196m\033[1m[%8.3f] ERROR:     %s\033[0m\033[0m\n", nround(get_wall_time()-START_TIME, 3), msg.c_str());
}

void trace() {
    printf("\033[38;5;196m\033[1mBEGIN STACK TRACE\033[0m\033[0m\n");
    printf("\033[38;5;196m\n");
    pid_t myPid = getpid();
    std::string pstackCommand = "pstack ";
    std::stringstream ss;
    ss << myPid;
    pstackCommand += ss.str();
    system(pstackCommand.c_str());
    printf("\033[0m\n");
    printf("\033[38;5;196m\033[1mEND STACK TRACE\033[0m\033[0m\n");
}

void set_start_time() {
    START_TIME = get_wall_time();
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto ts = std::ctime(&t);
    ts[19] = '\0';
    info("Set start time as " + std::string(ts) + ".");
}
