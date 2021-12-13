#include "points.h"
#include "ghosts.h"
#include "headers.h"

void pointCollision(Pacman * pacman, int mapWidth, char * mapa){
    if(mapa[(pacman->y) * mapWidth + pacman->x] == '-'){
		mapa[(pacman->y) * mapWidth + pacman->x] = ' ';
		pacman->score += 10;
	}
}

void cherryCollision(Pacman * pacman, int mapWidth, char * mapa){
	if(mapa[(pacman->y) * mapWidth + pacman->x] == 'C'){
		mapa[(pacman->y) * mapWidth + pacman->x] = ' ';
		pacman->score += 200;
		Mix_PlayChannel(-1, pacman->eat_fruit_sound, 0);
		pacman->powered = 1;
	}
}

void ghostPoweredCollision(Pacman * pacman, Ghost * ghost){
	if(pacman->x == ghost->x && pacman->y == ghost->y){
		pacman->score += 500;
		Mix_PlayChannel(-1, pacman->eat_ghost_sound, 0);

		ghost->x = ghost->origin_x;
		ghost->y = ghost->origin_y;
		ghost->isOutside = false;
	}
}