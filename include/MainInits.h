#ifndef MAININITS_H
#define MAININITS_H
#include <SFML/Graphics.hpp>
#include <cstring>
#include "CText.h"
#include "EnumState.h"
#include "RevealedElem.h"

void gameLogoInit(CText& gameLogo, sf::Font& mainScreenFont);
void mainMessageInit(CText& mainMessage, sf::Font& mainScreenFont);
bool handleEventsGame(sf::Event event, sf::RenderWindow& window, EnumState& exitValue, RevealedElem& revealedElem,const DisplayedValues& displayedValues);
bool handleEventsMain(sf::Event event, sf::RenderWindow& window, EnumState& exitValue);
#endif // MAININITS_H
