#pragma once

#include <string_view>

namespace bread::logger
{
    struct cfg
    {
        inline static constexpr std::string_view success = "[\033[32;1mSuccess\033[0m]";
        inline static constexpr std::string_view info    = "[\033[34;1mInfo\033[0m]";
        inline static constexpr std::string_view error   = "[\033[31;1mError\033[0m]";
        inline static constexpr std::string_view warning = "[\033[33;1mWarning\033[0m]";
        inline static constexpr std::string_view critical= "[\033[91;1mCritical\033[0m]";
        inline static constexpr std::string_view debug   = "[\033[35;1mDebug\033[0m]";
        inline static constexpr std::string_view none   = "\033[0m";

        inline static constexpr bool isDebug = true;
    };
}