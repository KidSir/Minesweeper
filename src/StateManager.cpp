#include "StateManager.h"
#include <iostream>
#include <EnumState.h>

StateManager::StateManager():StateValue(mainValue)
{
    //ctor
}

StateManager::~StateManager()
{
    //dtor
}

void StateManager::run(sf::RenderWindow& window)
{
    while(StateValue != exitValue) // cat timp nu s-a cerut inchiderea aplicatiei
    {
        //std::cout << StateValue;
        switch(StateValue)
        {
        case mainValue:
            //ecranul principal
            StateValue = States.at(mainValue)(window);
            break;
        case gameValue:
            //jocul propriu-zis
            StateValue = States.at(gameValue)(window);
            break;
        default:
            //in cazul in care valoarea nu e acoperita de niciun caz
            //aplicatia este inchisa fortat
            StateValue = exitValue;
        };
    }
}

void StateManager::addState(pointerState state)
{
    //Se adauga in vector inca o functie ce va rula o alta etapa
    //a aplicatiei
    States.push_back(state);
}


