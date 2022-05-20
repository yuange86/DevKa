#pragma once

#include "common/base/macro.hpp"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

#ifdef DK_DEBUG

namespace dvk
{
    enum LogLevel
    {
        TRACE = 0,
        DEBUG,
        LOG,
        WARN,
        ERROR,
        FATAL
    };

    class SpdLog
    {
    public:
        static void init(const std::string &logfilename = "DVK.log");
        static void create_logger(const std::string &name, unsigned int code, LogLevel level = LogLevel::LOG, LogLevel flush = LogLevel::LOG);

        static std::shared_ptr<spdlog::logger> &get_logger(unsigned int code);

    private:
        static std::unordered_map<unsigned int, std::shared_ptr<spdlog::logger>> m_loggers;
    };
}


#define DK_LOG_INIT()                       ::dvk::SpdLog::init()

#define DK_LOGGGER(code)                    ::dvk::SpdLog::get_logger(code)

#define DK_CREATE_LOGGER(...)               ::dvk::SpdLog::create_logger(__VA_ARGS__)


#define DK_TRACE(code, ...)        ::dvk::SpdLog::get_logger(code)->trace(__VA_ARGS__)
#define DK_INFO(code, ...)         ::dvk::SpdLog::get_logger(code)->info(__VA_ARGS__)
#define DK_WARN(code, ...)         ::dvk::SpdLog::get_logger(code)->warning(__VA_ARGS__)
#define DK_ERROR(code, ...)        ::dvk::SpdLog::get_logger(code)->error(__VA_ARGS__)
#define DK_FATAL(code, ...)        ::dvk::SpdLog::get_logger(code)->fatal(__VA_ARGS__)


#define DK_DEFAULT_TRACE(...)        ::dvk::SpdLog::get_logger(0)->trace(__VA_ARGS__)
#define DK_DEFAULT_INFO(...)         ::dvk::SpdLog::get_logger(0)->info(__VA_ARGS__)
#define DK_DEFAULT_WARN(...)         ::dvk::SpdLog::get_logger(0)->warn(__VA_ARGS__)
#define DK_DEFAULT_ERROR(...)        ::dvk::SpdLog::get_logger(0)->error(__VA_ARGS__)
#define DK_DEFAULT_FATAL(...)        ::dvk::SpdLog::get_logger(0)->critical(__VA_ARGS__)


//  example 
//  ---    dvk::SpdLog::create_logger(<code>, <mid_name>);\
//  ---    #define DK_<mid_name>_TRACE(...)        ::dvk::SpdLog::get_logger(<code>)->trace(__VA_ARGS__)
//  ---    #define DK_<mid_name>_INFO(...)         ::dvk::SpdLog::get_logger(<code>)->info(__VA_ARGS__)
//  ---    #define DK_<mid_name>_WARN(...)         ::dvk::SpdLog::get_logger(<code>)->warning(__VA_ARGS__)
//  ---    #define DK_<mid_name>_ERROR(...)        ::dvk::SpdLog::get_logger(<code>)->error(__VA_ARGS__)
//  ---    #define DK_<mid_name>_FATAL(...)        ::dvk::SpdLog::get_logger(<code>)->fatal(__VA_ARGS__)

#else

#define DK_LOG_INIT()   

#define DK_LOGGGER(code)

#define DK_CREATE_LOGGER(...)  


#define DK_TRACE(code, ...) 
#define DK_INFO(code, ...) 
#define DK_WARN(code, ...) 
#define DK_ERROR(code, ...) 
#define DK_FATAL(code, ...) 


#define DK_DEFAULT_TRACE(...)
#define DK_DEFAULT_INFO(...)
#define DK_DEFAULT_WARN(...)
#define DK_DEFAULT_ERROR(...)
#define DK_DEFAULT_FATAL(...)

#endif
