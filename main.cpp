#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainLoop.h"
#include "GameLoop.h"
#include "resources.h"
#include "StateManager.h"


int main()
{
    std::string windowName = "Minesweeper";
    sf::RenderWindow window(sf::VideoMode(GAMEWIDTH, GAMEHEIGHT), windowName);
    // Declararea ferestrei
    StateManager stateManager;
    stateManager.addState(mainLoop);
    stateManager.addState(gameLoop);
    stateManager.run(window);
    //Rularea jocului

    return 0;
}
