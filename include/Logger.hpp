#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/common.h>
#include <spdlog/sinks/sink.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

enum class LogLevel
{
    Trace,
    Debug,
    Info,
    Warn,
    Err,
    Critical,
    Off
};

class Logger
{
private:
    std::shared_ptr<spdlog::logger> Logger_;

public:
    Logger();
    ~Logger();

    void setLogLevel(const LogLevel &logLevel);

    //IDEA: Add log level specific methods (err, warn, info, etc.)
    template<typename... Args>
    void log(const LogLevel &logLevel, spdlog::format_string_t<Args...> fmt, Args &&...args) const;
    void log(const LogLevel &logLevel, const std::string &msg) const;

    void setSinks(const std::vector<std::string> sinksNames);
    void setSinks(const std::vector<spdlog::sink_ptr> sinks);

protected:
    static std::map<std::string, spdlog::sink_ptr> Sinks_;
    static std::map<std::string, spdlog::logger> Loggers_;

public:
    std::shared_ptr<spdlog::logger> createLogger(const std::string &name);
    std::shared_ptr<spdlog::logger> createLogger(const std::string &name, const std::vector<std::string> sinksNames);
    std::shared_ptr<spdlog::logger> createLogger(const std::string &name, const spdlog::sinks_init_list sinks);

    static void createSink(const std::string &name, 
                           const LogLevel &logLevel = LogLevel::Info);
    static void createFileSink(const std::string &name, const std::string &fileName, 
                               const LogLevel &LogLevel = LogLevel::Info);

    static void setSinkLogLevel(const std::string &name, const LogLevel &logLeel);

    static std::shared_ptr<spdlog* getLogger(const std::string &name);
    static spdlog::sink_ptr getSink(const std::string &name);
    static void setGlobalFormat(const std::string &format = "[%X][%^%n%$][%l] %v");
    static void setGlobalLogLevel(const LogLevel &logLevel);

    static spdlog::level::level_enum toSpdEnum(const LogLevel &logLevel);
};

