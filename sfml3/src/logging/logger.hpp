#ifndef __TEST_SFML3_LOGGER_HPP__
#define __TEST_SFML3_LOGGER_HPP__

#include <spdlog/sinks/callback_sink.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>

namespace Test::SFML3 {

class Logger {
public:
    Logger()
    {
        m_console_sink->set_level(spdlog::level::trace);
        m_console_sink->set_pattern("[" + m_log_name + "] [%^%l%$] %v");

        m_file_sink->set_level(spdlog::level::trace);
        m_file_sink->set_pattern("["+ m_log_name +"] [%^%l%$] %v");    

        spdlog::set_default_logger(m_logger);
        spdlog::flush_on(spdlog::level::trace); 
    }
private:
    std::string m_log_path{ "logs/log.txt" };
    std::string m_log_name{ "sprite_test" };

    // sink for logging to stdout
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_console_sink {
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
    };

    // sink for logging to file
    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> m_file_sink {
        std::make_shared<spdlog::sinks::basic_file_sink_mt>( m_log_path, true )
    };

    std::shared_ptr<spdlog::sinks::callback_sink_mt> m_callback_sink
    {
        std::make_shared<spdlog::sinks::callback_sink_mt>(
            [](const spdlog::details::log_msg &msg) {
                std::cout << "Callback!!!" << "\n";
            }
        )
    };
    
    // initialise spdlog::logger with sinks 
    std::shared_ptr<spdlog::logger> m_logger {
        std::make_shared<spdlog::logger>(spdlog::logger( 
            m_log_name, 
            {
                m_file_sink, m_console_sink, m_callback_sink
        }))
    };
};

} // namespace Test::SFML3

#endif // __TEST_SFML3_LOGGER_HPP__