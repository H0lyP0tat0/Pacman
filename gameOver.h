#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "headers.h"
#include "pacman.h"
#include "ghosts.h"

bool ghostCollision(Pacman * pacman, Ghost * ghost);

void gameOver(SDL_Renderer * renderer, TTF_Font * font, SDL_Color color);

void winningScreen(SDL_Renderer * renderer, TTF_Font * font, SDL_Color color);

void restartGame(Pacman * pacman, int mapSize, char * mapa, Ghosts * ghosts);

#endif //GAMEOVER_H