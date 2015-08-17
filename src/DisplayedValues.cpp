#include "DisplayedValues.h"
#include "DangerBoard.h"
#include <iostream>

//DangerBoard dangerBoard
DisplayedValues::DisplayedValues(DangerBoard dangerBoard)
{
    setSize(dangerBoard.getSize());
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            dang value = dangerBoard.getValue(i, j);
            switch(value)
            {
            case safe:
                values[i][j] = empty;
                break;
            case mined:
                values[i][j] = mine;
                break;
            case dangerous:
                values[i][j] = dangerBoard.getNearbyMines(i, j);
                break;
            }
        }
    }
}

void DisplayedValues::afisare()
{
    for(int i = 1; i<= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void DisplayedValues::setSize(int _size)
{
    size = _size;
}

DisplayedValues::~DisplayedValues()
{
    //dtor
}
