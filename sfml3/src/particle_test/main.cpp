#include <SFML/Graphics.hpp>
#include <particle.hpp>
#include <basic_log_controller.hpp>

int main()
{
    using BasicLogController = Test::Logging::BasicLogController;
    static std::unique_ptr<BasicLogController> logger{
        std::make_unique<BasicLogController>("vertexarray_test", "log.txt")};

    // create the window
    sf::RenderWindow window(sf::VideoMode({512, 256}), "Particles");

    // create the particle system
    ParticleSystem particles(1000);

    // create a clock to track the elapsed time
    sf::Clock clock;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // make the particle system emitter follow the mouse
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));

        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        // draw it
        window.clear();
        window.draw(particles);
        window.display();
    }
}