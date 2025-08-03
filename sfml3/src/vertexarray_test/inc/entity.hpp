#ifndef __TEST_ENTITY__HPP__
#define __TEST_ENTITY__HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <numeric>
#include <spdlog/spdlog.h>

namespace VertexArrayTest {

class MyEntity : public sf::Drawable, public sf::Transformable
{
public:
    // add functions to play with the entity's geometry / colors / texturing...
    MyEntity() {
        m_vertices = sf::VertexArray(sf::PrimitiveType::Triangles, 3);

        // define the position of the m_vertices's points
        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[1].position = sf::Vector2f(width, 0);
        m_vertices[2].position = sf::Vector2f(width, height);

        // define the color of the m_vertices's points
        m_vertices[0].color = sf::Color::Red;
        m_vertices[1].color = sf::Color::Blue;
        m_vertices[2].color = sf::Color::Green;

        // std::filesystem::path imagePath{"resources\\sfml_logo.png"};
        // try { m_texture = sf::Texture(imagePath); }
        // catch(const std::exception& e) { 
        //     spdlog::critical("{}: {}" , e.what(), imagePath.string());
        // }

        setPosition(sf::Vector2f(500, 500));

        // m_bounds = m_vertices.getBounds();
        spdlog::info("Init MyEntity");
    }

    MyEntity& operator+=(const sf::Angle& rhs)
    {
        auto a = getRotation() ;
        setRotation(a += rhs);        
        return *this;
    }

    MyEntity& operator+=(const sf::Vector2f& rhs)
    {
        return *this;
    }
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
        spdlog::info(getRotation().asDegrees());

        // apply the texture
        // states.texture = &m_texture;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture     m_texture;
    sf::FloatRect m_bounds;

    float width{100.f};
    float height{100.f};
};

} // namespace VertexArrayTest

#endif // __TEST_ENTITY__HPP__