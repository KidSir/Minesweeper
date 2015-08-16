#ifndef MAININITS_H
#define MAININITS_H
#include <SFML/Graphics.hpp>
#include <cstring>
#include "CText.h"
#include "EnumState.h"

void gameLogoInit(CText& gameLogo, sf::Font& mainScreenFont);
void mainMessageInit(CText& mainMessage, sf::Font& mainScreenFont);
bool handleEvents(sf::Event event, sf::Window& window, EnumState& exitValue);

#endif // MAININITS_H
