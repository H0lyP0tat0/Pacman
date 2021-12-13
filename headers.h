#ifndef HEADERS_H
#define HEADERS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#define MAP_WIDTH 660
#define MAP_HEIGHT 500

typedef struct Pacman {
	int direction;
	int x;
	int y;
	int origin_x;
	int origin_y;
	int health;
	int collision;
	int score;
    Mix_Chunk * eat_fruit_sound;
    Mix_Chunk * eat_ghost_sound;
    Mix_Chunk * death_sound;
	SDL_Texture * normal_texture;
	SDL_Texture * powered_texture;
	int powered;
} Pacman;

typedef struct {
    int x;
    int y;
    int origin_x;
    int origin_y;
    int direction;
    bool isOutside;
    SDL_Texture * normal_texture;
    SDL_Texture * chased_texture;
} Ghost;

typedef struct {
    Ghost * blinky;
    Ghost * inky;
    Ghost * pinky;
    Ghost * clyde;
} Ghosts;

#endif //HEADERS_H