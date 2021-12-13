#ifndef PACMAN_H
#define PACMAN_H

#include "headers.h"
#include "ghosts.h"

void getPacmanCoordinates(Pacman * pacman, const int mapWidth, const int mapHeight, char * mapa);

void pacmanMovement(Pacman * pacman, char * mapa, const int mapWidth);

void resetPacman(Pacman * pacman, Ghosts * ghosts);

void renderPacman(SDL_Renderer * renderer, SDL_Rect Rect, Pacman * pacman, SDL_Rect pacmanSrcrect);

#endif //PACMAN_H