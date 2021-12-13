#ifndef GHOSTS_H
#define GHOSTS_H

#include "headers.h"
#include "pacman.h"

void renderGhosts(SDL_Renderer * renderer, Ghosts * ghosts, SDL_Rect Rect);

void getBlinkyCoordinates(Ghost * blinky, const int mapWidth, const int mapHeight, char * mapa);

void getInkyCoordinates(Ghost * inky, const int mapWidth, const int mapHeight, char * mapa);

void getPinkyCoordinates(Ghost * pinky, const int mapWidth, const int mapHeight, char * mapa);

void getClydeCoordinates(Ghost * clyde, const int mapWidth, const int mapHeight, char * mapa);

void ghostRandomMove(Ghost * ghost, const int mapWidth, char * mapa);

void ghostGetClose(Ghost * ghost, Pacman * pacman, const int mapWidth, char * mapa);

void ghostGetAway(Ghost * ghost, Pacman * pacman, const int mapWidth, char * mapa);

#endif //GHOSTS_H