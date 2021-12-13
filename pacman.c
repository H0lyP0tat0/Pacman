#include "pacman.h"
#include "ghosts.h"

void getPacmanCoordinates(Pacman * pacman, const int mapWidth, const int mapHeight, char * mapa){
    for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (mapa[i * mapWidth + j] == 'P'){
				pacman->x = j;
				pacman->y = i;
			}
		}
	}
}

void pacmanMovement(Pacman * pacman, char * mapa, const int mapWidth){
	switch (pacman->direction){
		case 0:
			if (mapa[pacman->y * mapWidth + (pacman->x + 1)] != 'W')
			{
				if (mapa[pacman->y * mapWidth + (pacman->x + 1)] != 'T')
				{
					(pacman->x)++;
					if(pacman->x >= mapWidth - 1){
						pacman->x = 0;
					}
				}
			}
			break;
		case 1:
			if (mapa[(pacman->y + 1) * mapWidth + pacman->x] != 'W')
			{
				if (mapa[(pacman->y + 1) * mapWidth + pacman->x] != 'T')
				{
					(pacman->y)++;
				}
			}
			break;
		case 2:
			if (mapa[pacman->y * mapWidth + (pacman->x - 1)] != 'W')
			{
				if (mapa[pacman->y * mapWidth + (pacman->x - 1)] != 'T')
				{
					(pacman->x)--;
					if(pacman->x < 0){
						pacman->x = mapWidth - 1;
					}
				}
			}
			break;
		case 3:
			if (mapa[(pacman->y - 1) * mapWidth + pacman->x] != 'W')
			{
				if (mapa[(pacman->y - 1) * mapWidth + pacman->x] != 'T')
				{
					(pacman->y)--;
				}
			}
			break;
		default:
			break;
	}
}

void resetPacman(Pacman * pacman, Ghosts * ghosts){
	Mix_PlayChannel(-1, pacman->death_sound, 0);

	pacman->x = pacman->origin_x;
	pacman->y = pacman->origin_y;

	pacman->direction = 3;
	pacman->powered = 0;

	ghosts->blinky->x = ghosts->blinky->origin_x;
	ghosts->blinky->y = ghosts->blinky->origin_y;
	ghosts->blinky->isOutside = false;

	ghosts->inky->x = ghosts->inky->origin_x;
	ghosts->inky->y = ghosts->inky->origin_y;
	ghosts->inky->isOutside = false;

	ghosts->pinky->x = ghosts->pinky->origin_x;
	ghosts->pinky->y = ghosts->pinky->origin_y;
	ghosts->pinky->isOutside = false;

	ghosts->clyde->x = ghosts->clyde->origin_x;
	ghosts->clyde->y = ghosts->clyde->origin_y;
	ghosts->clyde->isOutside = false;
}

void renderPacman(SDL_Renderer * renderer, SDL_Rect Rect, Pacman * pacman, SDL_Rect pacmanSrcrect){
	if(pacman->powered == 0){
		Rect.x = pacman->x * 20;
		Rect.y = pacman->y * 20;

		Rect.h = 18;
		SDL_RenderCopyEx(renderer, pacman->normal_texture, &pacmanSrcrect, &Rect, pacman->direction * 90, NULL, 0);
		Rect.h = 20;
	} else if(pacman->powered == 1){
		Rect.x = pacman->x * 20;
		Rect.y = pacman->y * 20;

		Rect.h = 18;
		SDL_RenderCopyEx(renderer, pacman->powered_texture, &pacmanSrcrect, &Rect, pacman->direction * 90, NULL, 0);
		Rect.h = 20;
	}
}