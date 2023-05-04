#include "RP/Logs/Log.hpp"

#include <chrono>
#include <sstream>
#include <iomanip>

std::string RP::GetLocalTimeStr() {
    const auto now = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_MSC_VER)
    localtime_s(&tm, &time);
#else
    tm = *std::localtime(&time);
#endif  
    std::stringstream ss{};
    ss << std::put_time(&tm, "%H:%M:%S");
    return ss.str();
}