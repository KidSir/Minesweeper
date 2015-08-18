#include "RevealedElem.h"
#include <iostream>
#include "resources.h"
#include <cmath>
#include "CText.h"
#include <sstream>

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

void RevealedElem::displayBoard(sf::RenderWindow& window, sf::Font& mainScreenFont)
{
    int i, j;// variabile intermediare pentru a parcurge toate celule
    //tablei de joc

    //X , Y variabile intermediare pentru parcurgearea saltata a tablei,
    //X,si Y reprezentand  coltul stang al fiecarei celule
    sf::CircleShape cerc(cellSize/2);
    CText numarMine;
    numarMine.setFont(mainScreenFont);

    CText semnIntrebare;
    semnIntrebare.setFont(mainScreenFont);

    for(int Y = startGridY, i = 1; i <= size; Y +=cellSize, i++)
    {
        for(int X = startGridX, j = 1; j <= size; X += cellSize, j++)
        {
            switch(board[i][j])
            {

            case hidden:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::White);

                semnIntrebare.setColor(sf::Color::Black);
                semnIntrebare.setPosition(sf::Vector2f(X + cellSize/2, Y + cellSize/2));
                semnIntrebare.setString("?");
                semnIntrebare.setSize(20);
                semnIntrebare.centerTextOrigin();


                //std::cout << X << " " << Y << std::endl;
                break;
            case empty:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Blue);
                //std::cout << X << " " << Y << std::endl;
                break;
            case mine:
                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Red);
                break;
            default:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Yellow);


                numarMine.setColor(sf::Color::Red);
                numarMine.setSize(20);

                numarMine.setPosition(sf::Vector2f(X + cellSize/2, Y + cellSize/2));//
                std::stringstream strStream;
                int x = board[i][j];
                strStream << x;
                std::string temp = strStream.str();
                numarMine.setString(temp.c_str());
                numarMine.centerTextOrigin();

            }
            window.draw(cerc);
            switch(board[i][j])
            {
                case mine:

                    break;
                case hidden:
                    semnIntrebare.draw(window);

                    break;
                default:
                    numarMine.draw(window);

            }

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

void RevealedElem::userAction(int i, int j, DisplayedValues displayedValues)
{
    if(i >= 1 && i <= size && j >= 1 && j <= size)
    {
        //std::cout << x << " " << y << std::endl;
        // in viitor vor fi luate in calcul toate cazurile
        board[i][j] = displayedValues.getValue(i, j);
    }
}
