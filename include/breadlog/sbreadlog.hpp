#include "breadlog.hpp"

#define LOG_SUCCESS(msg)  bread::logger::log(bread::logger::logLevel::Success, msg, __func__, __FILE__, __LINE__)
#define LOG_INFO(msg)     bread::logger::log(bread::logger::logLevel::Info, msg, __func__, __FILE__, __LINE__)
#define LOG_WARNING(msg)  bread::logger::log(bread::logger::logLevel::Warning, msg, __func__, __FILE__, __LINE__)
#define LOG_ERROR(msg)    bread::logger::log(bread::logger::logLevel::Error, msg, __func__, __FILE__, __LINE__)
#define LOG_CRITICAL(msg) bread::logger::log(bread::logger::logLevel::Critical, msg, __func__, __FILE__, __LINE__)
#define LOG_DEBUG(msg)    bread::logger::log(bread::logger::logLevel::Debug, msg, __func__, __FILE__, __LINE__)