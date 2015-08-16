#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "EnumState.h"

typedef EnumState (*pointerState)(sf::RenderWindow&);

class StateManager
{
    public:
        StateManager();
        virtual ~StateManager();
        void addState(pointerState);
        void run(sf::RenderWindow& window);
    protected:
    private:
       std::vector<pointerState> States;
       EnumState StateValue;

};

#endif // STATEMANAGER_H
