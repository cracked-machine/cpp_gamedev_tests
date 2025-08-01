#include <SFML/Graphics.hpp>    
#include <logger.hpp>
#include <memory>

int main()
{
    std::unique_ptr<Test::SFML3::Logger> theLog{std::make_unique<Test::SFML3::Logger>()};
    spdlog::info("main");

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    
    sf::Texture texture;
    try { texture = sf::Texture("resources\\background.jpg"); }
    catch(const std::exception& e) { spdlog::critical("{}", e.what()); }

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
