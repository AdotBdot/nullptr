#include "Logger.hpp"

#include <map>

void Logger::setLogLevel(const LogLevel &logLevel)
{
    Logger_->set_level(toSpdEnum(logLevel));
}

template <typename... Args>
void Logger::log(const LogLevel &logLevel, spdlog::format_string_t<Args...> fmt, Args &&...args) const 
{
    Logger_->log(toSpdEnum(logLevel), fmt, args)
}

void Logger::log(const LogLevel &logLevel, const std::string &msg) const
{
    Logger_->log(toSpdEnum(logLevel), msg);
}

void Logger::setSinks(const std::vector<std::string> sinksNames)
{
    std::vector<spdlog::sink_ptr> sinks;
    for(const std::string sinkName: sinksNames)
    {
        sinks.push_back(Logger::getSink(sinkName));
    }

    Logger_->sinks() = sinks;
}

void Logger::setSinks(const std::vector<spdlog::sink_ptr> sinks)
{
    Logger_->sinks() = sinks;
}

Logger *Logger::getLogger(const std::string &name)
{
    if(!Loggers_.contains(name))
        return nullptr;

    return Loggers_[name];
}

spdlog::level::level_enum Logger::toSpdEnum(const LogLevel &logLevel)
{
    switch (logLevel)
    {
    case LogLevel::Trace:
        return spdlog::level::trace;
        break;
    case LogLevel::Debug:
        return spdlog::level::debug;
        break;
    case LogLevel::Info:
        return spdlog::level::info;
        break;
    case LogLevel::Warn:
        return spdlog::level::warn;
        break;
    case LogLevel::Err:
        return spdlog::level::err;
        break;
    case LogLevel::Critical:
        return spdlog::level::critical;
        break;
    case LogLevel::Off:
        return spdlog::level::off;
        break;
    default:
        break;
    }
}
