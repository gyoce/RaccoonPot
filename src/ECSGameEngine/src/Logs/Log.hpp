#ifndef LOG_HPP
#define LOG_HPP

namespace EcsGameEngine::Log {

    void Log(const char* format, ...);
    void LogError(const char* format, ...);
        
}

#endif // LOG_HPP