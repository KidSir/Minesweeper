#include "RevealedElem.h"
#include <iostream>
#include "resources.h"
#include <cmath>
#include "CText.h"
#include <sstream>
#include "remap.h"

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
    fontSize = cellSize * 0.60; // dam fontului o dimensiune
    //in pixeli proportional cu dimensiunea unei celule.
}

void RevealedElem::revealAll(DisplayedValues displayedValues)
{
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            board[i][j] = displayedValues.getValue(i, j);
        }
    }
}



void RevealedElem::displayBoard(sf::RenderWindow& window, sf::Font& mainScreenFont)
{
    int i, j;// variabile intermediare pentru a parcurge toate celule
    //tablei de joc

    //X , Y variabile intermediare pentru parcurgearea saltata a tablei,
    //X,si Y reprezentand  coltul stang al fiecarei celule

    sf::CircleShape cerc(cellSize/2);
    cerc.setPointCount(25);

    CText numarMine;
    numarMine.setFont(mainScreenFont);
    numarMine.setSize(fontSize);

    CText semnIntrebare;
    semnIntrebare.setFont(mainScreenFont);
    semnIntrebare.setSize(fontSize);

    sf::Texture imgBomba;
    imgBomba.loadFromFile("data/images/bomb.png");
    sf::Transform transformareImagine;
    transformareImagine.scale(5,5);
    sf::Sprite bomba;
    bomba.setTexture(imgBomba);
    bomba.setOrigin(imgBomba.getSize().x / 2, imgBomba.getSize().y / 2);
    float bombScale = remap(fontSize , 1 , bomba.getLocalBounds().width, 0, 1);
    bomba.setScale(bombScale, bombScale);

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
                semnIntrebare.setPosition(sf::Vector2f(X + cellSize/2, Y + cellSize/2));//
                semnIntrebare.setString("?");
                //semnIntrebare.setSize(20);
                semnIntrebare.centerTextOrigin();


                //std::cout << X << " " << Y << std::endl;
                break;
            case empty:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color(209, 209, 209));
                //std::cout << X << " " << Y << std::endl;
                break;
            case mine:
                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Red);
                bomba.setPosition(X + cellSize / 2, Y + cellSize / 2);
                break;
            default:

                cerc.setPosition(X, Y);
                cerc.setFillColor(sf::Color::Yellow);


                numarMine.setColor(sf::Color::Red);
                //numarMine.setSize(20);

                numarMine.setPosition(sf::Vector2f(X + cellSize/2, Y + cellSize/2));//
                std::stringstream strStream;
                strStream << board[i][j];
                std::string temp = strStream.str();
                numarMine.setString(temp.c_str());
                numarMine.centerTextOrigin();

            }
            window.draw(cerc);

            switch(board[i][j])
            {
                case empty:

                case mine:
                    window.draw(bomba);
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

void RevealedElem::userAction(int i, int j, DisplayedValues displayedValues, MarkedElem& markedElem)
{
    if(i >= 1 && i <= size && j >= 1 && j <= size)// daca mouse se afla
        //peste o celula valida
    {
        //std::cout << x << " " << y << std::endl;
        // in viitor vor fi luate in calcul toate cazurile
        if(markedElem.getValue(i, j) == unmarked) // daca celula nu a mai fost apasata
        {
            markedElem.setValue(i, j, marked); // marcam celula
            disp value = displayedValues.getValue(i, j); // ne ocupam de cazurile jocului
            switch(value)
            {
            case empty: //celula este o zona sigura
                revealSection(i, j,displayedValues, markedElem);// afiseaza un grup de celule
    //formata din zone sigure si zone periculoase
                markedElem.afisare();// pentru debugging
                break;

            case mine:
                revealAll(displayedValues);// cand se apasa o mina
                //jocul este terminat ( de asemenea in viitor va fi
                //implementata un mecanism de terminare/resetare a jocului)
                break;
            default:
                board[i][j] = displayedValues.getValue(i, j);
                // se afiseaza doar celula daca zona este una periculoasa

            }

        }
    }
}

void RevealedElem::revealSection(int i, int j,DisplayedValues displayValues, MarkedElem& markedElem)
{
    // functie de parcurgere pentru a afisa toate zolele sigure interconectate
    //cu celula(zona sigura) selectate de catre player
    markedElem.setValue(i, j, marked); // retinearea faptului ca celula a fost vizitata
    // si evitarea unei bucle infinite
    board[i][j] = displayValues.getValue(i, j);
    // celula nu mai este ascunsa playerului si primeste
    // valoarea precalculata din tabloul de valori

    for(int d = 0; d < 8; d++) // se parcurg toti vecinii
    {
        int tempi = i +  dy[d];
        int tempj = j +  dx[d];
        // se retine pozitia noului vecin
        if(tempi >= 1 && tempi <= size && tempj >= 1 && tempj <=size)// daca acesta
            //este un vecin valid ( daca celula se afla pe tabla de joc)
        {
            if(markedElem.getValue(tempi, tempj) == unmarked)//daca celula nu a mai fost vizitata
            {
                if(displayValues.getValue(tempi,tempj) != mine)// nu vrem sa aratam playerului si minele
                {
                    revealSection(tempi, tempj, displayValues, markedElem);//apel recursiv pentru a indentifica toata sectiune
                }
            }
        }
    }

}
