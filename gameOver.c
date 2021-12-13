#include "gameOver.h" 
#include "pacman.h"
#include "enviroment.h"
#include "ghosts.h"

bool ghostCollision(Pacman * pacman, Ghost * ghost){
    if(pacman->x == ghost->x && pacman->y == ghost->y){
        //printf("true\n");
        (pacman->collision)++;
        (pacman->health)--;
		//printf("Health: %d\n", *pacmanHealth);
        return true;
    }
    return false;
}

void gameOver(SDL_Renderer * renderer, TTF_Font * font, SDL_Color color){
    SDL_Rect blackBox = {0, 0, MAP_WIDTH, MAP_HEIGHT};

    //Game over text 
    SDL_Surface* gameOverMessage_Surface = TTF_RenderText_Solid(font, "Game Over!", color);
    SDL_Texture* gameOverMessage = SDL_CreateTextureFromSurface(renderer, gameOverMessage_Surface);
    SDL_Rect gameOver_rect;

    gameOver_rect.w = 400;
    gameOver_rect.h = 75; 
    gameOver_rect.x = (MAP_WIDTH / 2) - (gameOver_rect.w / 2);
    gameOver_rect.y = (MAP_HEIGHT / 2) - (gameOver_rect.h / 2); 

    //Final score text
    SDL_Surface* FinalScore_Surface = TTF_RenderText_Solid(font, "Final score:", color);
    SDL_Texture* FinalScoreMessage = SDL_CreateTextureFromSurface(renderer, FinalScore_Surface);
    SDL_Rect FinalScore_rect;

    FinalScore_rect.w = 200;
    FinalScore_rect.h = 25;
    FinalScore_rect.x = (MAP_WIDTH / 2) - (FinalScore_rect.w / 2);
    FinalScore_rect.y = MAP_HEIGHT - 100;

    //R to restart
    SDL_Surface* Restart_Surface = TTF_RenderText_Solid(font, "Press 'R' to restart", color);
    SDL_Texture* RestartMessage = SDL_CreateTextureFromSurface(renderer, Restart_Surface);
    SDL_Rect Restart_rect;

    Restart_rect.w = 560;
    Restart_rect.h = 40;
    Restart_rect.x = (MAP_WIDTH / 2) - (Restart_rect.w / 2);
    Restart_rect.y = 50;

    //Q to quit
    SDL_Surface* quitSurface = TTF_RenderText_Solid(font, "Press 'Q' to quit", color);
    SDL_Texture* quitMessage = SDL_CreateTextureFromSurface(renderer, quitSurface);
    SDL_Rect quit_rect;

    quit_rect.w = 480;
    quit_rect.h = 40;
    quit_rect.x = (MAP_WIDTH / 2) - (quit_rect.w / 2);
    quit_rect.y = 100;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	    SDL_RenderFillRect(renderer, &blackBox);
        SDL_RenderCopy(renderer, gameOverMessage, NULL, &gameOver_rect);
        SDL_RenderCopy(renderer, FinalScoreMessage, NULL, &FinalScore_rect);
        SDL_RenderCopy(renderer, RestartMessage, NULL, &Restart_rect);
        SDL_RenderCopy(renderer, quitMessage, NULL, &quit_rect);

    SDL_FreeSurface(gameOverMessage_Surface);
    SDL_DestroyTexture(gameOverMessage);
    SDL_FreeSurface(FinalScore_Surface);
    SDL_DestroyTexture(FinalScoreMessage);
    SDL_FreeSurface(Restart_Surface);
    SDL_DestroyTexture(RestartMessage);
    SDL_FreeSurface(quitSurface);
    SDL_DestroyTexture(quitMessage);
}

void winningScreen(SDL_Renderer * renderer, TTF_Font * font, SDL_Color color){
    SDL_Rect blackBox = {0, 0, MAP_WIDTH, MAP_HEIGHT};

    //You won text 
    SDL_Surface* winningMessageSurface = TTF_RenderText_Solid(font, "You won!", color);
    SDL_Texture* winningMessage = SDL_CreateTextureFromSurface(renderer, winningMessageSurface);
    SDL_Rect winningMessage_rect;

    winningMessage_rect.w = 400;
    winningMessage_rect.h = 75; 
    winningMessage_rect.x = (MAP_WIDTH / 2) - (winningMessage_rect.w / 2);
    winningMessage_rect.y = (MAP_HEIGHT / 2) - (winningMessage_rect.h / 2); 

    //Final score text
    SDL_Surface* FinalScore_Surface = TTF_RenderText_Solid(font, "Final score:", color);
    SDL_Texture* FinalScoreMessage = SDL_CreateTextureFromSurface(renderer, FinalScore_Surface);
    SDL_Rect FinalScore_rect;

    FinalScore_rect.w = 200;
    FinalScore_rect.h = 25;
    FinalScore_rect.x = (MAP_WIDTH / 2) - (FinalScore_rect.w / 2);
    FinalScore_rect.y = MAP_HEIGHT - 100;

    //R to restart
    SDL_Surface* Restart_Surface = TTF_RenderText_Solid(font, "Press 'R' to restart", color);
    SDL_Texture* RestartMessage = SDL_CreateTextureFromSurface(renderer, Restart_Surface);
    SDL_Rect Restart_rect;

    Restart_rect.w = 560;
    Restart_rect.h = 40;
    Restart_rect.x = (MAP_WIDTH / 2) - (Restart_rect.w / 2);
    Restart_rect.y = 50;

    //Q to quit
    SDL_Surface* quitSurface = TTF_RenderText_Solid(font, "Press 'Q' to quit", color);
    SDL_Texture* quitMessage = SDL_CreateTextureFromSurface(renderer, quitSurface);
    SDL_Rect quit_rect;

    quit_rect.w = 480;
    quit_rect.h = 40;
    quit_rect.x = (MAP_WIDTH / 2) - (quit_rect.w / 2);
    quit_rect.y = 100;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

	    SDL_RenderFillRect(renderer, &blackBox);
        SDL_RenderCopy(renderer, winningMessage, NULL, &winningMessage_rect);
        SDL_RenderCopy(renderer, FinalScoreMessage, NULL, &FinalScore_rect);
        SDL_RenderCopy(renderer, RestartMessage, NULL, &Restart_rect);
        SDL_RenderCopy(renderer, quitMessage, NULL, &quit_rect);

    SDL_FreeSurface(winningMessageSurface);
    SDL_DestroyTexture(winningMessage);
    SDL_FreeSurface(FinalScore_Surface);
    SDL_DestroyTexture(FinalScoreMessage);
    SDL_FreeSurface(Restart_Surface);
    SDL_DestroyTexture(RestartMessage);
    SDL_FreeSurface(quitSurface);
    SDL_DestroyTexture(quitMessage);
}

void restartGame(Pacman * pacman, int mapSize, char * mapa, Ghosts * ghosts){
    loadMap("map1.txt", mapSize, mapa);

	resetPacman(pacman, ghosts);

    pacman->direction = 3;
    pacman->collision = 0;
    pacman->health = 3;
    pacman->score = 0;
    pacman->powered = 0;
}