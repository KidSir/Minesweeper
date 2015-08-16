#include "MainLoop.h"
#include <iostream>
#include "CText.h"
#include "MainInits.h"
#include "resources.h"
#include "EnumState.h"

EnumState mainLoop(sf::RenderWindow& window)
{
    EnumState value;
    sf::Font mainScreenFont;
    if(!mainScreenFont.loadFromFile("data/font/mainFont.ttf"))
    {
        std::cout << " Eroare";
    }

    CText gameLogo;
    gameLogoInit(gameLogo, mainScreenFont);

    CText mainMessage;
    mainMessageInit(mainMessage, mainScreenFont);


    while (window.isOpen())
    {

        sf::Event event;
        if(handleEvents(event, window, value))
        {
            if(value == gameValue)
                return gameValue;
            else
                return mainValue;
            return exitValue;
        }

        window.clear();
        gameLogo.draw(window);
        mainMessage.draw(window);
        window.display();
    }
    return exitValue;
}
