#include "MainInits.h"
#include "resources.h"
#include <iostream>

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

bool handleEventsGame(sf::Event event, sf::RenderWindow& window, EnumState& exitValue, RevealedElem& revealedElem, const DisplayedValues& displayedValues)
{
     while (window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
    //Intoarcerea in meniul principal este temporar dezactivata
 /*       case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Return)
            {
                exitValue = mainValue;
                return true;
            }
            break;
*/

        }
    }

    //rezolvarea inputului primit de user
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

          int i =  revealedElem.locateCellY(sf::Mouse::getPosition(window).y, window);
          int j =  revealedElem.locateCellX(sf::Mouse::getPosition(window).x, window);
          // cele doua variabile de mai sus contin indecsii corespunzatori tablei
          // de joc in functie de pozitia mouse-ului
         // std::cout << i << " " << j << std::endl;
          revealedElem.userAction(i, j, displayedValues);
    }

    return false;
}

bool handleEventsMain(sf::Event event, sf::RenderWindow& window, EnumState& exitValue)
{
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Return)
            {
                exitValue = gameValue;
                return true;
            }
            break;
        }
    }
}

