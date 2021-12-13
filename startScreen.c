#include "startScreen.h"

void startScreen_init(SDL_Renderer * renderer, TTF_Font * font, SDL_Color color){
    SDL_Rect startScreen = {0, 0, MAP_WIDTH, MAP_HEIGHT};

    //Pacman text 
    SDL_Surface* pacmanText_Surface = TTF_RenderText_Solid(font, "Pac-Man", color);
    SDL_Texture* pacmanTextMessage = SDL_CreateTextureFromSurface(renderer, pacmanText_Surface);
    SDL_Rect pacman_rect;

    pacman_rect.w = 400;
    pacman_rect.h = 75; 
    pacman_rect.x = (MAP_WIDTH / 2) - (pacman_rect.w / 2);
    pacman_rect.y = (MAP_HEIGHT / 3) - (pacman_rect.h / 2);

    //Version text
    SDL_Surface* versionSurface = TTF_RenderText_Solid(font, "Version 1.0", color);
    SDL_Texture* versionMessage = SDL_CreateTextureFromSurface(renderer, versionSurface);
    SDL_Rect version_rect;

    version_rect.w = 120;
    version_rect.h = 15;
    version_rect.x = MAP_WIDTH - version_rect.w - 10;
    version_rect.y = MAP_HEIGHT - 25;

    //S to start
    SDL_Surface* startSurface = TTF_RenderText_Solid(font, "Press 'S' to start", color);
    SDL_Texture* startMessage = SDL_CreateTextureFromSurface(renderer, startSurface);
    SDL_Rect start_rect;

    start_rect.w = 560;
    start_rect.h = 40;
    start_rect.x = (MAP_WIDTH / 2) - (start_rect.w / 2);
    start_rect.y = MAP_HEIGHT / 2 + 100;

    //Q to quit
    SDL_Surface* quitSurface = TTF_RenderText_Solid(font, "Press 'Q' to quit", color);
    SDL_Texture* quitMessage = SDL_CreateTextureFromSurface(renderer, quitSurface);
    SDL_Rect quit_rect;

    quit_rect.w = 530;
    quit_rect.h = 40;
    quit_rect.x = (MAP_WIDTH / 2) - (quit_rect.w / 2);
    quit_rect.y = (MAP_HEIGHT / 2) + 150;

    //Made by
    SDL_Surface* madeBySurface = TTF_RenderText_Solid(font, "Made by: Jan Fojtik", color);
    SDL_Texture* madeByMessage = SDL_CreateTextureFromSurface(renderer, madeBySurface);
    SDL_Rect madeBy_rect;

    madeBy_rect.w = 200;
    madeBy_rect.h = 15;
    madeBy_rect.x = 10;
    madeBy_rect.y = MAP_HEIGHT - 25;

    SDL_SetRenderDrawColor(renderer, 25, 25, 166, 255);

    SDL_RenderFillRect(renderer, &startScreen);
    SDL_RenderCopy(renderer, pacmanTextMessage, NULL, &pacman_rect);
    SDL_RenderCopy(renderer, versionMessage, NULL, &version_rect);
    SDL_RenderCopy(renderer, startMessage, NULL, &start_rect);
    SDL_RenderCopy(renderer, quitMessage, NULL, &quit_rect);
    SDL_RenderCopy(renderer, madeByMessage, NULL, &madeBy_rect);

    SDL_FreeSurface(pacmanText_Surface);
    SDL_DestroyTexture(pacmanTextMessage);
    SDL_FreeSurface(versionSurface);
    SDL_DestroyTexture(versionMessage);
    SDL_FreeSurface(startSurface);
    SDL_DestroyTexture(startMessage);
    SDL_FreeSurface(quitSurface);
    SDL_DestroyTexture(quitMessage);
    SDL_FreeSurface(madeBySurface);
    SDL_DestroyTexture(madeByMessage);
}