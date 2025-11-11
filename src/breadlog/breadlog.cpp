#include "breadlog.hpp"
#include "breadlog/cfg.hpp"

#include <iostream>
#include <format>
#include <filesystem>


namespace bread::logger
{
    std::string parseFunction(std::string_view functionName, std::string_view file, int line)
    {
        return std::format("[\033[96m{}\033[0m:\033[34m{}\033[0m:\033[36m{}\033[0m]", line, functionName, std::filesystem::path(file).filename().native());
    }

    std::string getTime()
    { 
        std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm localTime;
        localtime_r(&t, &localTime);
        return std::format("\033[0m[\033[90m{:02}:{:02}:{:02}\033[0m]",localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
    }

    void log(logLevel level, std::string_view msg, std::string_view func, std::string_view file, int line)
    {
        const std::string_view prefix = 
            (level == logLevel::Success) ? bread::logger::cfg::success :
            (level == logLevel::Info)    ? bread::logger::cfg::info :
            (level == logLevel::Warning) ? bread::logger::cfg::warning:
            (level == logLevel::Error)   ? bread::logger::cfg::error :
            (level == logLevel::Critical)? bread::logger::cfg::critical :
                                           bread::logger::cfg::debug;

        if(level!=bread::logger::logLevel::Debug || bread::logger::cfg::isDebug)
        {
            std::cout << getTime()
                  << parseFunction(func, file, line)
                  << prefix << " "
                  << msg << "\n";
        }
    }
}
