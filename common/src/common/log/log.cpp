
#include <string>
#include <unordered_map>
#include <memory>

#include "common/log/log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#ifdef DK_DEBUG

namespace dvk
{

    std::unordered_map<unsigned int, std::shared_ptr<spdlog::logger>> SpdLog::m_loggers;

    static std::vector<spdlog::sink_ptr> sinks;

    void SpdLog::init(const std::string &logfilename)
    {
        sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
        sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(logfilename, true));

        sinks[0]->set_pattern("%^ [%T] %n: %v%$");
        sinks[1]->set_pattern("[%T] %n: %v");

        create_logger("default", 0);
    }

    void SpdLog::create_logger(const std::string &name, unsigned int code, LogLevel level, LogLevel flush)
    {
        auto logger = std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
        spdlog::register_logger(logger);
        logger->set_level((spdlog::level::level_enum)level);
        logger->flush_on((spdlog::level::level_enum)flush);

        m_loggers[code] = logger;
    }

    std::shared_ptr<spdlog::logger> &SpdLog::get_logger(unsigned int code)
    {
        if (m_loggers.find(code) == 0)
        {
            return m_loggers[0];
        }
        else
        {
            return m_loggers[code];
        }
    }

}

#endif
