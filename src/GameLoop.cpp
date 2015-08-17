#include "GameLoop.h"
#include "DisplayedValues.h"
#include "RevealedElem.h"

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
    dangerBoard.addMines(4); // se adauga mine
    dangerBoard.addDangerZones();// se adauga zonele periculoasa
    // prin excludere obtinand si zonele sigure
    dangerBoard.afisare();

    DisplayedValues displayedValues(dangerBoard);
    displayedValues.afisare();

    RevealedElem revealedElem(dangerBoard.getSize());// setare dimensiune
    revealedElem.setGridValues();//initializare cu valorile ce vor fi afisate
    // pe ecran, valorile fiind precalculate
    revealedElem.afisareConsola();
    // afisare in consola pentru verificare corectitudine
    revealedElem.displayBoard(window); // afisarea grafica a tablei de joc

    while (window.isOpen())
    {
        sf::Event event;

        if(handleEventsGame(event, window, value, revealedElem))
        {
            return value;
        }
        window.clear();

        revealedElem.displayBoard(window);
        //gameLogo.draw(window);
        //mainMessage.draw(window);
        window.display();
    }
    return exitValue;
}


