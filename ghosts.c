#include "ghosts.h"
#include "enviroment.h"
#include "pacman.h"

void renderGhosts(SDL_Renderer * renderer, Ghosts * ghosts, SDL_Rect Rect){
	
	//Blinky
	Rect.x = (ghosts->blinky->x) * 20;
	Rect.y = (ghosts->blinky->y) * 20;

	SDL_RenderCopy(renderer, ghosts->blinky->normal_texture, NULL, &Rect);
		
	//Inky
	Rect.x = (ghosts->inky->x) * 20;
	Rect.y = (ghosts->inky->y) * 20;

	SDL_RenderCopy(renderer, ghosts->inky->normal_texture, NULL, &Rect);
		
	//Pinky
	Rect.x = (ghosts->pinky->x) * 20;
	Rect.y = (ghosts->pinky->y) * 20;

	SDL_RenderCopy(renderer, ghosts->pinky->normal_texture, NULL, &Rect);
		
	//Clyde
	Rect.x = (ghosts->clyde->x) * 20;
	Rect.y = (ghosts->clyde->y) * 20;

	SDL_RenderCopy(renderer, ghosts->clyde->normal_texture, NULL, &Rect);
}

void getBlinkyCoordinates(Ghost * blinky, const int mapWidth, const int mapHeight, char * mapa){
    for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (mapa[i * mapWidth + j] == '1'){
				blinky->x = j;
				blinky->y = i;
			}
		}
	}
}

void getInkyCoordinates(Ghost * inky, const int mapWidth, const int mapHeight, char * mapa){
    for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (mapa[i * mapWidth + j] == '2'){
				inky->x = j;
				inky->y = i;
			}
		}
	}
}

void getPinkyCoordinates(Ghost * pinky, const int mapWidth, const int mapHeight, char * mapa){
    for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (mapa[i * mapWidth + j] == '3'){
				pinky->x = j;
				pinky->y = i;
			}
		}
	}
}

void getClydeCoordinates(Ghost * clyde, const int mapWidth, const int mapHeight, char * mapa){
    for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			if (mapa[i * mapWidth + j] == '4'){
				clyde->x = j;
				clyde->y = i;
			}
		}
	}
}

void ghostRandomMove(Ghost * ghost, const int mapWidth, char * mapa){

	switch (ghost->direction){
		case 0:
			if (mapa[ghost->y * mapWidth + (ghost->x + 1)] != 'W')
			{
				if (mapa[ghost->y * mapWidth + (ghost->x + 1)] != 'T')
				{
					(ghost->x)++;
					if(ghost->x == mapWidth - 1){ghost->direction = 2;}
				}
			}
			break;
		case 1:
			if (mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'W')
			{
				if (mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'T')
				{
					(ghost->y)++;
				}
			}
			break;
		case 2:
			if (mapa[ghost->y * mapWidth + (ghost->x - 1)] != 'W')
			{
				if (mapa[ghost->y * mapWidth + (ghost->x - 1)] != 'T')
				{
					(ghost->x)--;
					if(ghost->x == 0){ghost->direction = 0;}
				}
			}
			break;
		case 3:
			if (mapa[(ghost->y - 1) * mapWidth + ghost->x] != 'W')
			{
				(ghost->y)--;
			}
			break;
		default:
			break;
	}
}

void ghostGetClose(Ghost * ghost, Pacman * pacman, const int mapWidth, char * mapa){
	if(ghost->isOutside == true){
		if(ghost->x > pacman->x){
			if(mapa[ghost->y * mapWidth + (ghost->x - 1)] != 'W' && ghost->direction != 0){
				ghost->direction = 2;
			}
		}
		if(ghost->x < pacman->x){
			if (mapa[ghost->y * mapWidth + (ghost->x + 1)] != 'W' && ghost->direction != 2){
				ghost->direction = 0;
			}
		}
		if(ghost->y > pacman->y){
			if(mapa[(ghost->y - 1) * mapWidth + ghost->x] != 'W' && ghost->direction != 1){
				ghost->direction = 3;
			}
		}
		if(ghost->y < pacman->y){
			if(mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'W' && ghost->direction != 3 && mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'T'){
				ghost->direction = 1;
			}
		}
	} else {
		if(ghost->x < (mapWidth / 2) - 1){
			ghost->direction = 0;
		} else if(ghost->x > (mapWidth / 2) - 1){
			ghost->direction = 2;
		} else {
			if(ghost->y > 7){
				ghost->direction = 3;
			} else ghost->isOutside = true;
		}
	}
}

void ghostGetAway(Ghost * ghost, Pacman * pacman, const int mapWidth, char * mapa){
	if(ghost->isOutside == true){
		if(ghost->x > pacman->x){
			if(mapa[ghost->y * mapWidth + (ghost->x + 1)] != 'W' && ghost->direction != 2){
				ghost->direction = 0;
			} else ghost->direction = rand() % 4;
		}
		if(ghost->x < pacman->x){
			if (mapa[ghost->y * mapWidth + (ghost->x - 1)] != 'W' && ghost->direction != 0){
				ghost->direction = 2;
			} else ghost->direction = rand() % 4;
		}
		if(ghost->y > pacman->y){
			if(mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'W' && mapa[(ghost->y + 1) * mapWidth + ghost->x] != 'T' && ghost->direction != 3){
				ghost->direction = 1;
			} else ghost->direction = rand() % 4;
		}
		if(ghost->y < pacman->y){
			if(mapa[(ghost->y - 1) * mapWidth + ghost->x] != 'W' && ghost->direction != 1){
				ghost->direction = 3;
			} else ghost->direction = rand() % 4;
		}
	} else {
		if(ghost->x < (mapWidth / 2) - 1){
			ghost->direction = 0;
		} else if(ghost->x > (mapWidth / 2) - 1){
			ghost->direction = 2;
		} else {
			if(ghost->y > 7){
				ghost->direction = 3;
			} else ghost->isOutside = true;
		}
	}
}