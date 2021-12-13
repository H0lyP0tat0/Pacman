#include "headers.h"
#include "enviroment.h"
#include "pacman.h"
#include "points.h"
#include "gameOver.h"
#include "ghosts.h"
#include "startScreen.h"

SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *file)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = IMG_Load(file);

	if (!surface)
	{
		fprintf(stderr, "SDL_IMG_Load: %s\n", SDL_GetError());
		exit(1);
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG | MIX_INIT_MOD);
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);

	//Window specifications
	SDL_Window *window = SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAP_WIDTH, MAP_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool isRunning = true;
	int gameRunning = 0;
	SDL_Event event;

	SDL_Rect Rect = {.h = 20, .w = 20};

	//Map
	const int mapWidth = 34;
	const int mapHeight = 21;

	const int mapSize = mapWidth * mapHeight;

	char mapa[mapSize];

	loadMap("map1.txt", mapSize, mapa);

	//Textures

	//Enviroment
	SDL_Texture *cherryTexture = LoadTexture(renderer, "assets/Cherry.png");
	SDL_Texture *doorsTexture = LoadTexture(renderer, "assets/Doors.png");
	SDL_Texture *heartTexture = LoadTexture(renderer, "assets/Heart.png");
	SDL_Texture *pointTexture = LoadTexture(renderer, "assets/Point.png");

	//Score
	int t_width = 0;
	int t_height = 0;
	SDL_Color text_color = {255, 255, 255, 255};
	TTF_Font *font = TTF_OpenFont("assets/Fonts/emulogic.ttf", 24);
	SDL_Texture *ftexture = NULL;
	char text[16] = {0};

	//Blinky
	Ghost blinky = {.direction = -1, .isOutside = false};

	getBlinkyCoordinates(&blinky, mapWidth, mapHeight, mapa);
	blinky.origin_x = blinky.x;
	blinky.origin_y = blinky.y;
	blinky.normal_texture = LoadTexture(renderer, "assets/Blinky.png");

	//Inky
	Ghost inky = {.direction = -1};

	getInkyCoordinates(&inky, mapWidth, mapHeight, mapa);
	inky.origin_x = inky.x;
	inky.origin_y = inky.y;
	inky.normal_texture = LoadTexture(renderer, "assets/Inky.png");

	//Pinky
	Ghost pinky = {.direction = -1};

	getPinkyCoordinates(&pinky, mapWidth, mapHeight, mapa);
	pinky.origin_x = pinky.x;
	pinky.origin_y = pinky.y;
	pinky.normal_texture = LoadTexture(renderer, "assets/Pinky.png");

	//Clyde
	Ghost clyde = {.direction = 0};

	getClydeCoordinates(&clyde, mapWidth, mapHeight, mapa);
	clyde.origin_x = clyde.x;
	clyde.origin_y = clyde.y;
	clyde.normal_texture = LoadTexture(renderer, "assets/Clyde.png");

	Ghosts ghosts = {.blinky = &blinky, .pinky = &pinky, .inky = &inky, .clyde = &clyde};

	//Start screen ghosts
	Ghost startScreenGhosts = {.direction = 0};
	startScreenGhosts.x = -80;
	startScreenGhosts.y = MAP_HEIGHT / 2;
	startScreenGhosts.normal_texture = LoadTexture(renderer, "assets/ghostSprites.png");

	//Pacman
	Pacman pacman = {.direction = 3, .health = 3, .collision = 0, .score = 0, .powered = 0};

	getPacmanCoordinates(&pacman, mapWidth, mapHeight, mapa);
	pacman.origin_x = pacman.x;
	pacman.origin_y = pacman.y;
	pacman.normal_texture = LoadTexture(renderer, "assets/pacmanSprites.png");
	pacman.powered_texture = LoadTexture(renderer, "assets/pacmanSprites_powered.png");
	pacman.death_sound = Mix_LoadWAV("assets/Sounds/pacman_death.wav");
	pacman.eat_fruit_sound = Mix_LoadWAV("assets/Sounds/pacman_eatfruit.wav");
	pacman.eat_ghost_sound = Mix_LoadWAV("assets/Sounds/pacman_eatghost.wav");

	//Fonts
	TTF_Font *gameOver_font = TTF_OpenFont("assets/Fonts/emulogic.ttf", 50);
	
	//Colors
	SDL_Color White = {255, 255, 255, 255};
	SDL_Color Red = {255, 0, 0, 255};
	SDL_Color Yellow = {255, 255, 0, 255};

	//Time managment
	unsigned time = SDL_GetTicks();
	int movement_delay_counter = 0;
	int blinky_movement_counter = 0;
	int inky_movement_counter = 0;
	int pinky_movement_counter = 0;
	int clyde_movement_counter = 0;
	int powered_counter = 0;
	int door_timer = 0;
	int point_counter = 0;

	//Intro sound
    Mix_Chunk * introSound = Mix_LoadWAV("assets/Sounds/pacman_beginning.wav");
    Mix_PlayChannel(-1, introSound, 0);

	//Main game cycle
	while (isRunning){ //Input
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym){
					case SDLK_ESCAPE:
						isRunning = false;
						break;
					case SDLK_UP:
						pacman.direction = 3;
						break;
					case SDLK_DOWN:
						pacman.direction = 1;
						break;
					case SDLK_LEFT:
						pacman.direction = 2;
						break;
					case SDLK_RIGHT:
						pacman.direction = 0;
						break;
					case SDLK_r: //Force restart game
						restartGame(&pacman, mapSize, mapa, &ghosts);
						gameRunning = 1;
						break;
					case SDLK_g: //Force game-over
						gameRunning = 2;
						break;
					case SDLK_h: //Force win
						gameRunning = 3;
						break;
					case SDLK_q:
						isRunning = false;
						break;
					case SDLK_s:
						gameRunning = 1;
						break;
					}
				}
			}

		if(gameRunning == 0){
			startScreen_init(renderer, gameOver_font, Yellow);
			Rect.w = 80;
			Rect.x = startScreenGhosts.x;
			Rect.y = startScreenGhosts.y;
			startScreenGhosts.x += 1;
			SDL_RenderCopy(renderer, startScreenGhosts.normal_texture, NULL, &Rect);
			if(startScreenGhosts.x == MAP_WIDTH){
				startScreenGhosts.x = -80;
			} 
		}

		if(gameRunning == 1){
			Rect.w = 20;
			SDL_SetRenderDrawColor(renderer, 50, 50, 50, 0);
			SDL_RenderClear(renderer);

			//Time management
			Uint32 ticks = SDL_GetTicks();
			unsigned delta_time = ticks - time;

			//Movement counter
			movement_delay_counter += delta_time;

			//Ghosts counter
			blinky_movement_counter += delta_time;
			inky_movement_counter += delta_time;
			pinky_movement_counter += delta_time;
			clyde_movement_counter += delta_time;

			if(pacman.powered == 0){
				if(blinky_movement_counter > 200){
					ghostGetClose(&blinky, &pacman, mapWidth, mapa);
					ghostRandomMove(&blinky, mapWidth, mapa);
					blinky_movement_counter = 0;
				}

				if(inky_movement_counter > 300){
					ghostGetClose(&inky, &pacman, mapWidth, mapa);
					ghostRandomMove(&inky, mapWidth, mapa);
					inky_movement_counter = 0;
				}

				if(pinky_movement_counter > 250){
					ghostGetClose(&pinky, &pacman, mapWidth, mapa);
					ghostRandomMove(&pinky, mapWidth, mapa);
					pinky_movement_counter = 0;
				}

				if(clyde_movement_counter > 400){
					ghostGetClose(&clyde, &pacman, mapWidth, mapa);
					ghostRandomMove(&clyde, mapWidth, mapa);
					clyde_movement_counter = 0;
				}
			}

			if(pacman.powered == 1){
				if(blinky_movement_counter > 200){
					ghostGetAway(&blinky, &pacman, mapWidth, mapa);
					ghostRandomMove(&blinky, mapWidth, mapa);
					blinky_movement_counter = 0;
				}

				if(inky_movement_counter > 300){
					ghostGetAway(&inky, &pacman, mapWidth, mapa);
					ghostRandomMove(&inky, mapWidth, mapa);
					inky_movement_counter = 0;
				}

				if(pinky_movement_counter > 250){
					ghostGetAway(&pinky, &pacman, mapWidth, mapa);
					ghostRandomMove(&pinky, mapWidth, mapa);
					pinky_movement_counter = 0;
				}

				if(clyde_movement_counter > 400){
					ghostGetAway(&clyde, &pacman, mapWidth, mapa);
					ghostRandomMove(&clyde, mapWidth, mapa);
					clyde_movement_counter = 0;
				}
			}


			Uint32 pacmanSprite = (ticks / 45) % 9;
			SDL_Rect pacmanSrcrect = {pacmanSprite * 20, 0, 20, 18};

			//Collisions with enviroment
			pointCollision(&pacman, mapWidth, mapa);
			cherryCollision(&pacman, mapWidth, mapa);

			if(pacman.powered == 0){
				if(ghostCollision(&pacman, &blinky) == true){
					resetPacman(&pacman, &ghosts);
				}
				if(ghostCollision(&pacman, &inky) == true){
					resetPacman(&pacman, &ghosts);				
					}
				if(ghostCollision(&pacman, &pinky) == true){
					resetPacman(&pacman, &ghosts);
				}
				if(ghostCollision(&pacman, &clyde) == true){
					resetPacman(&pacman, &ghosts);
				}
			}

			if(movement_delay_counter > 100){
				pacmanMovement(&pacman, mapa, mapWidth);
				movement_delay_counter = 0;
			}

			renderPacman(renderer, Rect, &pacman, pacmanSrcrect);

			//Pacman_powered counter
			if(pacman.powered == 1){
				powered_counter += delta_time;
				if(powered_counter > 15000){
					pacman.powered = 0;
					powered_counter = 0;
				}
				ghostPoweredCollision(&pacman, &blinky);
				ghostPoweredCollision(&pacman, &inky);
				ghostPoweredCollision(&pacman, &pinky);
				ghostPoweredCollision(&pacman, &clyde);
			}

			//Rendering map
			mapRender(renderer, mapWidth, mapHeight, Rect, mapa, cherryTexture, doorsTexture, pointTexture, &point_counter);

			renderGhosts(renderer, &ghosts, Rect);

			//Health rendering
			healthRender(font, Red, renderer, Rect, heartTexture, &pacman);

			//Rendering score
			scoreRender(font, White, renderer, ftexture, &pacman, t_width, t_height, text);

			time = ticks;

			if(pacman.collision >= 3){
				gameRunning = 2;
			}

			if(point_counter == 0){
				gameRunning = 3;
			}

		}

		if(gameRunning == 2){
			gameOver(renderer, gameOver_font, Red);
			scoreRender(font, Red, renderer, ftexture, &pacman, t_width, t_height, text);
		}

		if(gameRunning == 3){
			winningScreen(renderer, gameOver_font, Yellow);
			scoreRender(font, Yellow, renderer, ftexture, &pacman, t_width, t_height, text);
		}
		SDL_RenderPresent(renderer);
		}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	Mix_Quit();
	TTF_Quit();
	SDL_Quit();

	return 0;
}