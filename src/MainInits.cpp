#include "MainInits.h"
#include "resources.h"


void gameLogoInit(CText& gameLogo, sf::Font& mainScreenFont)
{

    gameLogo.setColor(sf::Color::Green);
    gameLogo.setFont(mainScreenFont);
    gameLogo.setSize(30);
    gameLogo.setString("Minesweeper");
    gameLogo.setPosition(sf::Vector2f(GAMEWIDTH / 2, GAMEHEIGHT / 2.5));
    gameLogo.centerTextOrigin();
}

void mainMessageInit(CText& mainMessage, sf::Font& mainScreenFont)
{

    mainMessage.setColor(sf::Color::Green);
    mainMessage.setFont(mainScreenFont);
    mainMessage.setSize(20);
    mainMessage.setString("Apasa Enter pentru a incepe");
    mainMessage.setPosition(sf::Vector2f(GAMEWIDTH / 2, GAMEHEIGHT / 2.5 + GAMEHEIGHT / 4));
    mainMessage.centerTextOrigin();
}

bool handleEvents(sf::Event event, sf::Window& window, EnumState& exitValue)
{
     while (window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Return)
            {
                exitValue = gameValue;
                return true;
            }
        }
    }
    return false;
}

