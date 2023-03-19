#include "Log.hpp"

#include <iostream>
#include <cstdarg>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cstring>

using namespace ECSGameEngine;

std::string getLocalTimeStr();
void formatLog(std::stringstream& ss, const char* format, va_list& list);

void Log::Log(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::stringstream ss;
    ss << "[" << getLocalTimeStr() << "]: ";
    formatLog(ss, format, args);
    va_end(args);
    std::cout << ss.str() << '\n';
}

void Log::LogError(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::stringstream ss;
    ss << "ERROR [" << getLocalTimeStr() << "]: ";
    formatLog(ss, format, args);
    va_end(args);
    std::cerr << ss.str() << '\n';
}

std::string getLocalTimeStr() {
    auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    tm* tm = std::localtime(&time);
    std::stringstream ss;
    ss << std::put_time(tm, "%H:%M:%S");
    return ss.str();
}

void formatLog(std::stringstream& ss, const char* format, va_list& list) {
    int index = 0;
    while (format[index] != '\0') {
        if (format[index] != '%') {
            ss << format[index];
            index++;
            continue;
        }
        index++;
        if (index >= (int)strlen(format)) { break; }
        switch (format[index]) {
        case 'd':
            ss << va_arg(list, int);
            break;
        case 'c':
            ss << static_cast<char>(va_arg(list, int));
            break;
        case 's':
            ss << va_arg(list, char*);
            break;
        case 'f':
            ss << va_arg(list, double);
            break;
        default:
            std::cerr << "Format for Log is unknown" << std::endl;
            break;
        }
        index++;
    }
}
