#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include "headers.h"
#include "pacman.h"
#include "ghosts.h"

#define LEFT 2
#define RIGHT 0
#define UP 3
#define DOWN 1

typedef struct {
    int height;
    int width;
    int mapSize;
    char * symbol;
} Maze;

char loadMap(char * filename, const int mapSize, char * mapa);

void healthRender(TTF_Font * font, SDL_Color color, SDL_Renderer * renderer, SDL_Rect Rect, SDL_Texture * texture, Pacman * pacman);

void scoreRender(TTF_Font * font, SDL_Color color, SDL_Renderer * renderer, SDL_Texture * ftexture, Pacman * pacman, int t_width, int t_height, char * text);

void mapRender(SDL_Renderer * renderer, int mapWidth, int mapHeight, SDL_Rect Rect, char * mapa, SDL_Texture * cherryTexture, SDL_Texture * doorsTexture, SDL_Texture * pointTexture, int * point_counter);

#endif //ENVIROMENT_H