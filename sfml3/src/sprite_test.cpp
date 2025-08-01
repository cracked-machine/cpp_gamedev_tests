#include <SFML/Graphics.hpp>    
// #include <logger.hpp>
#include <async_log_controller.hpp>
#include <filesystem>
#include <memory>


int main()
{
    // std::unique_ptr<Test::SFML3::Logger> theLog{std::make_unique<Test::SFML3::Logger>()};
    std::unique_ptr<Test::Sprite::AsyncLogController> logController {std::make_unique<Test::Sprite::AsyncLogController>()};

    spdlog::info("some info log");
    spdlog::error("critical issue"); // will notify you

    // spdlog::info("main");
    
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    
    std::filesystem::path imagePath{"resources\\background.jpg"};
    sf::Texture texture;
    try { texture = sf::Texture(imagePath); }
    catch(const std::exception& e) { 
        spdlog::critical("{}: {}" , e.what(), imagePath.string());
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
