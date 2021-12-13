#include "enviroment.h"
#include "pacman.h"
#include "ghosts.h"


char loadMap(char * filename, const int mapSize, char * mapa){
    FILE * map = NULL;
    map = fopen(filename, "r");
    assert(map);

   	int read = fread(mapa, sizeof(char), mapSize, map);

    fclose(map);
    
    return 0;
}

void healthRender(TTF_Font * font, SDL_Color color, SDL_Renderer * renderer, SDL_Rect Rect, SDL_Texture * texture, Pacman * pacman){
    	SDL_Surface* healthSurface = TTF_RenderText_Solid(font, "Health:", color);
		SDL_Texture* healthMessage = SDL_CreateTextureFromSurface(renderer, healthSurface);
		SDL_Rect health_rect;

	    health_rect.w = 100;
		health_rect.h = 20;
		health_rect.x = 20;
		health_rect.y = MAP_HEIGHT - 50;

		SDL_RenderCopy(renderer, healthMessage, NULL, &health_rect);

		for (int i = 0; i < pacman->health; i++) {
			Rect.x = (health_rect.x + health_rect.w) + (20 * i);
			Rect.y = health_rect.y + 2;
			SDL_RenderCopy(renderer, texture, NULL, &Rect);
		}
        SDL_FreeSurface(healthSurface);
    	SDL_DestroyTexture(healthMessage);
}

void scoreRender(TTF_Font * font, SDL_Color color, SDL_Renderer * renderer, SDL_Texture * ftexture, Pacman * pacman, int t_width, int t_height, char * text){
    	sprintf(text, "%d", pacman->score);

		SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, color);
		ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);
		t_width = text_surface->w;
		t_height = text_surface->h;

		int scoreWidth = 0;
		int scoreHeight = 0;

		SDL_QueryTexture(ftexture, NULL, NULL, &scoreWidth, &scoreHeight);

		int scoreX = ((MAP_WIDTH) / 2) - (scoreWidth / 2);
		int scoreY = MAP_HEIGHT - 50;
		SDL_Rect dst = {scoreX, scoreY, t_width, t_height};
		SDL_RenderCopy(renderer, ftexture, NULL, &dst);

        SDL_FreeSurface(text_surface);
        SDL_DestroyTexture(ftexture);
}

void mapRender(SDL_Renderer * renderer, int mapWidth, int mapHeight, SDL_Rect Rect, char * mapa, SDL_Texture * cherryTexture, SDL_Texture * doorsTexture, SDL_Texture * pointTexture, int * point_counter){
	*point_counter = 0;
	for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			Rect.x = j * 20;
			Rect.y = i * 20;

			switch (mapa[i * mapWidth + j])
			{
			case 'W':
				SDL_SetRenderDrawColor(renderer, 33, 33, 222, 0);
				SDL_RenderFillRect(renderer, &Rect);
				break;
			case 'C':
				SDL_RenderCopy(renderer, cherryTexture, NULL, &Rect);
				break;
			case '-':
				*(point_counter) += 1;
				SDL_RenderCopy(renderer, pointTexture, NULL, &Rect);
				break;
			case 'T':
				SDL_RenderCopy(renderer, doorsTexture, NULL, &Rect);
				break;
			default:
				break;
			}
		}
	}
}