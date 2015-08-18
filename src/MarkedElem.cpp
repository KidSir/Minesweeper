#include "MarkedElem.h"
#include <iostream>

MarkedElem::MarkedElem(int _size)
{
    size = _size;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            values[i][j] = unmarked;
        }
    }
}

void MarkedElem::afisare()
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            std::cout << values[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

mark MarkedElem::getValue(int i, int j)
{
    return values[i][j];
}

void MarkedElem::setValue(int i, int j, mark val)
{
    values[i][j] = val;
}

MarkedElem::~MarkedElem()
{
    //dtor
}
