#include "DangerBoard.h"
#include "cstdlib"
#include "ctime"
#include <iostream>
#include "resources.h"

DangerBoard::DangerBoard(int gameSize)
{
    size = gameSize;
    srand((unsigned)time(NULL));
    reset();
}

void DangerBoard::reset()
{
    for(int i = 1; i<= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            zones[i][j] = safe;
        }
    }
}

void DangerBoard::addMines(int nrMines)
{
    for(int nr = 1; nr <= nrMines; nr++)
    {
        int x = rand() % size + 1;
        int y = rand() % size + 1;
        while(zones[x][y] != safe)
        {
            x = rand() % size + 1;
            y = rand() % size + 1;
        }
        zones[x][y] = mined;

    }
}



void DangerBoard::afisare()
{
        for(int i = 1; i<= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                std::cout << zones[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

void DangerBoard::addDangerZones()
{
    for(int i = 1; i <= size; i++)
        for(int j = 1; j <= size; j++)
            if(zones[i][j] == mined)
                for(int d = 0; d < 8; d++)
                {
                    int newX = i + dx[d];
                    int newY = j + dy[d];

                    if(newX >= 1 && newX <= size && newY >= 1 && newY <= size)
                    {
                        if(zones[newX][newY] == safe)
                            zones[newX][newY] =  dangerous;
                    }
                }
}

DangerBoard::~DangerBoard()
{
    //dtor
}
