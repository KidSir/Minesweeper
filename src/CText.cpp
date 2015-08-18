#include "CText.h"
#include <cstring>

CText::CText()
{
    //ctor
}

CText::~CText()
{
    //dtor
}

 void CText::setFont(const sf::Font& font)
 {
     m_text.setFont(font);
 }

 void CText::setString(std::string text)
 {
    m_text.setString(text);
 }


        // set the character size
void CText::setSize(int textSize)
{
    m_text.setCharacterSize(textSize);
}

void CText::setColor(const sf::Color& color)
{
    m_text.setColor(color);
}

void CText::setPosition(sf::Vector2f position)
{
    m_text.setPosition(position);
}
void CText::centerTextOrigin()
{
    m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width /2, m_text.getLocalBounds().top + m_text.getLocalBounds().height /2);
}

void CText::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

