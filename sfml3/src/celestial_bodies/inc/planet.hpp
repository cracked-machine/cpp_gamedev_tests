#ifndef __PLANET__HPP__
#define __PLANET__HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>

#include <basic_log_controller.hpp>

class Planet : public sf::Drawable, public sf::Transformable
{
public:
    Planet(std::string name, float orbit_radius, float planet_radius, sf::Color colour, sf::Vector2u window_size) 
    {
        m_name = name;
        m_orbit.setRadius(orbit_radius);
        m_orbit.setPointCount(orbit_radius * 25);
        m_orbit.setPosition(
            {
                window_size.x * 0.5f - m_orbit.getRadius(), 
                window_size.y * 0.5f - m_orbit.getRadius() 
            }
        );
        m_orbit.setOutlineColor(sf::Color::White);
        m_orbit.setFillColor(sf::Color::Transparent);
        spdlog::info("{} Orbit Radius: {}", m_name, orbit_radius);
        
        m_orbit.setOutlineThickness(1);
        m_planet.setRadius(planet_radius);
        m_planet.setPointCount(planet_radius * 50);
        spdlog::info("{} Planet Radius: {}", m_name, planet_radius);

        m_planet.setFillColor(colour);

    }

    virtual void update()
    {
        m_planet.setPosition(
            {
                m_orbit.getPoint(m_orbit_idx).x + m_orbit.getPosition().x - m_planet.getRadius(), 
                m_orbit.getPoint(m_orbit_idx).y + m_orbit.getPosition().y - m_planet.getRadius()
            }
        );
        m_orbit_idx > m_orbit.getPointCount() -1 ? m_orbit_idx = 0 : m_orbit_idx++; 
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // states.transform *= m_planet.getTransform(); 
        spdlog::debug("{}: {}, {}", m_name, m_planet.getPosition().x, m_planet.getPosition().y);
        target.draw(m_orbit, states);
        target.draw(m_planet, states);        
    }
private:
    std::string m_name;
    sf::CircleShape m_orbit;
    sf::CircleShape m_planet; 
    std::size_t m_orbit_idx{0};
};

#endif // __PLANET__HPP__