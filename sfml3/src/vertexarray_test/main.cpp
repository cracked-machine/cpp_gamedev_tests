#include <SFML/Graphics.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <basic_log_controller.hpp>
#include <entity.hpp>


int main()
{
    using BasicLogController = Test::Logging::BasicLogController;
    static std::unique_ptr<BasicLogController> logger{
        std::make_unique<BasicLogController>("vertexarray_test", "log.txt")};
    
    spdlog::info("Starting");

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "VertexArray Test");
    window.setFramerateLimit(144);

    spdlog::info("Init RenderWindow");

    VertexArrayTest::MyEntity entt;
    

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
        entt += sf::degrees(1.f);
        // entt.getTransform().transformRect(getLocalBounds());
        window.draw(entt);        
        window.display();
    }
}