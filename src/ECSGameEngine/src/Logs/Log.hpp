#ifndef LOG_HPP
#define LOG_HPP

#include <streambuf>

namespace ECSGameEngine::Log {

    void Log(const char* format, ...);
    void LogError(const char* format, ...);
        
}

#endif // LOG_HPP