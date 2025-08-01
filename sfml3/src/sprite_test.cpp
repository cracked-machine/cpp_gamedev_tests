#include <SFML/Graphics.hpp>    
// #include <logger.hpp>
#include <iostream>
#include <logger.hpp>
#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/callback_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>
#include <spdlog/spdlog.h>

int main()
{
    std::unique_ptr<Test::SFML3::Logger> theLog{std::make_unique<Test::SFML3::Logger>()};

    spdlog::info("some info log");
    spdlog::error("critical issue"); // will notify you

    // spdlog::info("main");
    
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    
    sf::Texture texture;
    try { texture = sf::Texture("resources\\background.jpg"); }
    catch(const std::exception& e) { 
        // spdlog::critical("{}", e.what());
    }

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
