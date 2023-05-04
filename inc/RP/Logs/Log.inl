#include <sstream>
#include <iostream>
#include <cstring>

namespace RP::Internal {

    struct LogContext {
        const char* Format = nullptr;
        int FormatSize = 0;
        int Index = 0;
        std::stringstream Stream{};
    };

    template<typename T, class... Args> void FormatLog(LogContext* context, T&& current, Args&&... args);

    inline void FormatLog(LogContext* context) {
        while (context->Index < context->FormatSize) {
            context->Stream << context->Format[context->Index];
            context->Index++;
        }
    }

    inline LogContext GetNewLogContext(const char* format) {
        return LogContext {
            .Format = format,
            .FormatSize = static_cast<int>(strlen(format))
        };
    }
}

template <class... Args>
void RP::Log(const char* format, Args&&... args) {
    Internal::LogContext context = Internal::GetNewLogContext(format);
    context.Stream << "[" << GetLocalTimeStr() << "]: ";
    if constexpr (sizeof...(args) > 0) {
        Internal::FormatLog(&context, std::forward<Args>(args)...);
    } else {
        Internal::FormatLog(&context);
    }
    std::cout << context.Stream.str() << "\n";
}

template <class... Args>
void RP::LogError(const char* format, Args&&... args) {
    Internal::LogContext context = Internal::GetNewLogContext(format);
    context.Stream << "ERROR [" << GetLocalTimeStr() << "]: ";
    if constexpr (sizeof...(args) > 0) {
        Internal::FormatLog(&context, std::forward<Args>(args)...);
    } else {
        Internal::FormatLog(&context);
    }
    std::cerr << context.Stream.str() << "\n";
}

template<typename T, class... Args> void RP::Internal::FormatLog(LogContext* context, T&& current, Args&&... args) {
    while (context->Index < context->FormatSize) {
        if (context->Format[context->Index] == '{' && context->Format[context->Index + 1] == '}') {
            context->Index = context->Index + 2;
            context->Stream << current;
            FormatLog(context, std::forward<Args>(args)...);
        } else {
            context->Stream << context->Format[context->Index];
        }
        context->Index++;
    }
}