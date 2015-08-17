#include "GameLoop.h"

EnumState gameLoop(sf::RenderWindow& window)
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

    DangerBoard dangerBoard(4); // constructor , cu nr de linii
    dangerBoard.addMines(1); // se adauga mine
    dangerBoard.addDangerZones();// se adauga zonele periculoasa
    // prin excludere obtinand si zonele sigure
    dangerBoard.afisare();

    while (window.isOpen())
    {
        sf::Event event;
        if(handleEvents(event, window, value))
        {
            if(exitValue == mainValue)
                return gameValue;
            else
                return mainValue;
            return exitValue;
        }
        window.clear();
        //gameLogo.draw(window);
        //mainMessage.draw(window);
        window.display();
    }
    return exitValue;
}


