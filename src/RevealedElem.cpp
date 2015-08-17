#include "RevealedElem.h"
#include <iostream>
#include "resources.h"
#include <cmath>

RevealedElem::RevealedElem(int _size)
{
    size = _size;
    init_board();
}

RevealedElem::~RevealedElem()
{
    //dtor
}

disp RevealedElem::getState(int i, int j)
{
    return board[i][j];
}

void RevealedElem::setState(int i, int j, disp state)
{
    board[i][j] = state;
}

void RevealedElem::afisareConsola()
{
    //afisare a tablei de joc in consola pentru teste
    //aceasta functie ar putea fi eliminata la terminarea proiectului
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void RevealedElem::setGridValues()
{
    int valX = GAMEWIDTH / (size + 1);
    int valY = GAMEHEIGHT / (size + 1);
    //  valX si valY reprezinta nr de pixeli pe care l-ar avea
    //o celula daca ecranul ar fi impartit in cate cate linii si
    // coloane avem, valoare reprezentata de variabila size
    // se foloseste size + 1 deoare se doreste un spatiu gol suplimentra
    // pentru ca celulele sa nu ocupe tot ecranul
    cellSize = std::min(valX, valY);// se alege dimensiunea
    //unei celule astfel incat aspectul ferestrei sa nu trebuiasa
    // sa fie de 1:1

    startGridX = (GAMEWIDTH - cellSize * size) / 2;
    startGridY = (GAMEHEIGHT - cellSize * size) / 2;
    // se salveaza valorile de unde se va incepe afisarea campului
    //cu mine, acestea fiind necesare la fiecare reimprospatare
    //a ferestrei
}

void RevealedElem::displayBoard(sf::RenderWindow& window)
{
    int i, j;// variabile intermediare pentru a parcurge toate celule
    //tablei de joc

    //X , Y variabile intermediare pentru parcurgearea saltata a tablei,
    //X,si Y reprezentand  coltul stang al fiecarei celule
    sf::CircleShape cerc(cellSize/2);
    for(int X = startGridX, i = 1; i <= size; X += cellSize, i++)
    {
        for(int Y = startGridY, j = 1; j <= size; Y +=cellSize, j++)
        {

            switch(board[i][j])
            {

            case hidden:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::White);
                //std::cout << X << " " << Y << std::endl;
                break;
            case empty:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Blue);
                //std::cout << X << " " << Y << std::endl;
                break;

            }
            window.draw(cerc);
            // Setari temporare pentru a vedea daca pozitiile calculate
            // sunt corecte

        }
    }
    //std::cout << cellSize << std::endl;
}

int RevealedElem::locateCellX(int mouseX, sf::RenderWindow& window)
{
    //std::cout << " X: " << sf::Mouse::getPosition(window).x << std::endl;
    float temp = -1;
    if(cellSize != 0)// evitarea impartirii la 0
        temp = ((float)(mouseX - startGridX)) / cellSize ;
   // std::cout << floor(temp) + 1<< std::endl;
    return floor(temp) + 1;
    // rotunjire prin scadere se datoreaza offsetului initial,
    //valoarea rezultata nefiind
    //convertita corect printr-o conversie de tipul int
}

int RevealedElem::locateCellY(int mouseY, sf::RenderWindow& window)
{
    //std::cout << " Y: " << sf::Mouse::getPosition(window).y << std::endl;
    float temp = -1;
    if(cellSize != 0)// evitarea impartirii la 0
        temp = ((float)(mouseY - startGridY)) / cellSize ;
    //std::cout << floor(temp) + 1<< std::endl;
    return floor(temp) + 1;//aceasi explicatie ca mai sus
}

void RevealedElem::init_board()
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            board[i][j] = hidden; // initial toate valorile sunt ascunse playerului
        }
    }
}

void RevealedElem::userAction(int x, int y)
{
    if(x >= 1 && x <= size && y >= 1 && y <= size)
    {
        // in viitor vor fi luate in calcul toate cazurile
        board[x][y] = empty;
        /*
        switch(board[i][j])
        {

        }
        */
    }
}
