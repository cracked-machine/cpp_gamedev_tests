#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <gl.h>

#include <spdlog/spdlog.h>
#include <spdlog/common.h>
#include <basic_log_controller.hpp>

#include <planet.hpp>

int main()
{
    std::unique_ptr<Test::Logging::BasicLogController> logger{
        std::make_unique<Test::Logging::BasicLogController>("logger", "log.txt")
    };
    spdlog::set_level(spdlog::level::info);

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    auto center_dot = sf::CircleShape(5);
    center_dot.setFillColor(sf::Color::Red);
    center_dot.setPosition({960, 540});

    Planet earth("Earth", 300, 30, sf::Color::Green, window.getSize());
    Planet mars("Mars", 200, 20, sf::Color::Red, window.getSize());
    Planet mercury("Mercury", 70, 15, sf::Color::Cyan, window.getSize());

    float angleX = 0.0f;
    float angleY = 0.0f;

    sf::Clock clock;
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        // Update rotation angles (example)
        float elapsedTime = clock.restart().asSeconds();
        angleX += elapsedTime * 50.0f;
        angleY += elapsedTime * 30.0f;


        // window.clear();
        std::ignore = window.setActive(true);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        std::ignore = window.setActive(false);

        window.pushGLStates();
        window.draw(mars);      
        window.draw(mercury);
        window.draw(earth);
        window.draw(center_dot);
        window.popGLStates();
        
        mars.update();
        mercury.update();
        earth.update();



        window.display();
    }
}