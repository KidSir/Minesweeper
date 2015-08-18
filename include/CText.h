#ifndef CTEXT_H
#define CTEXT_H
#include <SFML/Graphics.hpp>
#include <string>

class CText
{
    public:
        CText();
        virtual ~CText();
        void setFont(const sf::Font& font);
        void setString(std::string);
        void setSize(int);
        void setColor(const sf::Color&);
        void setPosition(sf::Vector2f);
        void draw(sf::RenderWindow& window);
        void centerTextOrigin();
    protected:
    private:
        sf::Text m_text;

};

#endif // CTEXT_H
