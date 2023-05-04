#ifndef RP_LOG_HPP
#define RP_LOG_HPP

#include <string>

namespace RP {

    template<class... Args> void Log(const char* format, Args&&... args);
    template<class... Args> void LogError(const char* format, Args&&... args);

    std::string GetLocalTimeStr();
}

#include <RP/Logs/Log.inl>

#endif // RP_LOG_HPP