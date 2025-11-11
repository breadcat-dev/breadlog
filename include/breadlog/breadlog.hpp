#pragma once

#include <string>

namespace bread::logger
{
    enum class logLevel { Success, Info, Warning, Error, Critical, Debug };

    void log(logLevel level, std::string_view msg, std::string_view func = "", std::string_view file = "", int line = 0);
}