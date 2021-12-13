#ifndef POINTS_H
#define POINTS_H

#include "headers.h"
#include "pacman.h"
#include "ghosts.h"

void pointCollision(Pacman * pacman, int mapWidth, char * mapa);

void cherryCollision(Pacman * pacman, int mapWidth, char * mapa);

void ghostPoweredCollision(Pacman * pacman, Ghost * ghost);

#endif //POINTS_H