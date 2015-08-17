#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include "CText.h"
#include "MainInits.h"
#include <iostream>
#include "EnumState.h"
#include "DangerBoard.h"

//declaratiai etapei de joc propriu-zis
EnumState gameLoop(sf::RenderWindow& window);




#endif // GAMELOOP_H
