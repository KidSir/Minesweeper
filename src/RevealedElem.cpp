#include "RevealedElem.h"

RevealedElem::RevealedElem(int _size)
{
    size = _size;
}

RevealedElem::~RevealedElem()
{
    //dtor
}

rev RevealedElem::getState(int i, int j)
{
    return board[i][j];
}

void RevealedElem::setState(int i, int j, rev state)
{
    board[i][j] = state;
}

void RevealedElem::init_board()
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            board[i][j] = hidden;
        }
    }
}
