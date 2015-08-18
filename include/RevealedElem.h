#ifndef REVEALEDELEM_H
#define REVEALEDELEM_H
#include "dispEnum.h"
#include <SFML/Graphics.hpp>
#include "DisplayedValues.h"
#include "MarkedElem.h"

class RevealedElem
{
    public:
        RevealedElem(int _size);
        disp getState(int, int);
        void setState(int, int, disp state);
        void init_board();
        void afisareConsola();
        void displayBoard(sf::RenderWindow& window, sf::Font& mainScreenFont);
        int locateCellX(int, sf::RenderWindow&);
        int locateCellY(int, sf::RenderWindow&);
        void setGridValues();
        void userAction(int, int, DisplayedValues displayedValues, MarkedElem& markedElem);
        void revealAll(DisplayedValues displayedValues);
        void revealSection(int i, int j, DisplayedValues displayedValues, MarkedElem& markedElem);
        virtual ~RevealedElem();
    protected:
    private:
        int cellSize;
        int startGridX;
        int startGridY;
        int fontSize;
        int size;
        disp board[31][31];
};

#endif // REVEALEDELEM_H
