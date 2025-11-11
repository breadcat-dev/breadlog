#include <iostream>

#include "sbreadlog.hpp"

int main()
{
    std::cout << "\033[94;1m---===[ \033[96;1mbreadlog \033[94;1m]===---\033[0m\n";
    
    bread::logger::log(bread::logger::logLevel::Debug,"Welcome to my channel :D","Bread","ytvid1",67);

    LOG_CRITICAL("Critical error message");
    LOG_DEBUG("Debug message");
    LOG_ERROR("Error message");
    LOG_INFO("Info message");
    LOG_SUCCESS("Success message");
    LOG_WARNING("Warning message");
    
    std::cout << "\033[31;1mClosing the program..\n";
    return 0;
}