#include "MinesArray.h"
#include "cstdlib"
#include "ctime"
#include <iostream>

MinesArray::MinesArray(int gameSize)
{
    size = gameSize;
    srand((unsigned)time(NULL));
    for(int i = 1; i<= gameSize; i++)
    {
        for(int j = 1; j <= gameSize; j++)
        {
            mines[i][j] = 0;
        }
    }
}

void MinesArray::reset()
{
    for(int i = 1; i<= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            mines[i][j] = 0;
        }
    }
}

void MinesArray::addMines(int nrMines)
{
    for(int nr = 1; nr <= nrMines; nr++)
    {
        int x = rand()%nrMines + 1;
        int y = rand()%nrMines + 1;
        while(mines[x][y] != 0)
        {
            x = rand()%nrMines + 1;
            y = rand()%nrMines + 1;
        }
        mines[x][y] = -1;
    }
}

void MinesArray::afisare()
{
        for(int i = 1; i<= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                std::cout << mines[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

MinesArray::~MinesArray()
{
    //dtor
}
