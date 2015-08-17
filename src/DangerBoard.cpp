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
        std::cout << std::endl;
}

void DangerBoard::addDangerZones()
{
    for(int i = 1; i <= size; i++)
        {
            for(int j = 1; j <= size; j++)
            {
                if(zones[i][j] == mined)
                {
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
            }
        }
}

int DangerBoard::getSize()
{
    return size;
}

dang DangerBoard::getValue(int i, int j)
{
    return zones[i][j];
}

disp DangerBoard::getNearbyMines(int x, int y)
{

    int contorMine = 0;
    for(int d = 0; d < 8; d++)
    {
        int newX = x + dx[d];
        int newY = y + dy[d];

        if(newX >= 1 && newX <= size && newY >= 1 && newY <= size)
        {
            if(zones[newX][newY] == mined)
                contorMine++;
        }
    }
    switch(contorMine)
    {
    case 1:
        return dangerous1;
        break;
    case 2:
        return dangerous2;
        break;
    case 3:
        return dangerous3;
        break;
    case 4:
        return dangerous4;
        break;
    case 5:
        return dangerous5;
        break;
    case 6:
        return dangerous6;
        break;
    case 7:
        return dangerous7;
        break;
    case 8:
        return dangerous8;
        break;
    }
}

DangerBoard::~DangerBoard()
{
    //dtor
}
