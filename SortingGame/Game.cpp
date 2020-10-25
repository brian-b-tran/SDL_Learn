#include "Game.h"
namespace sortGame {
	Game::Game() {};
	Game::~Game() {};
	void Game::gameOn(const char* title, int posx, int posy, int width, int height, bool fullscreen)
	{
		int flags = 0;
		if (fullscreen == true) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
		{
			std::cout << "SDL Initialized" << std::endl;
			
			//Set texture filtering to linear
			if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			{
				printf("Warning: Linear texture filtering not enabled!");
			}
			//create the window
			window = SDL_CreateWindow(title, posx, posy, width, height, flags);
			if (window != NULL) 
			{
				std::cout << "Window created" << std::endl;
				//create the renderer
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (renderer != NULL)
				{
					std::cout << "Renderer created" << std::endl;
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					//initialize SDLimg
					int imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags)) 
					{
						std::cout << "Could not Initialize image" << std::endl;
						running = false;
					}
					else {
						std::cout << "SDLImage Initialized" << std::endl;
					}
				}
				else 
				{
					std::cout << "Renderer could not be initialized" << std::endl;
					running = false;
				}
			}
			else {
				std::cout << "Window could not be created" << std::endl;
				running = false;
			}
		}
		else {
				std::cout << "SDL_Init failed" << std::endl;
				running = false;
		}
		
		running = true;
	}
	void Game::update()
	{
		sheet.loadFromFile("assets/bombs/Sheets/Blue.png", renderer);
		
		int nextRow = 0;
		int nextClip = 0;
		int nextSprite = 0;
		for (int i = 0; i < 7; i++) {
			
			for (int j = 0; j < 8; j++) {
				clips[nextClip].x = nextSprite;
				clips[nextClip].y = nextRow;
				clips[nextClip].w = 482;
				clips[nextClip].h = 482;
				nextSprite += 482;
				++nextClip;
			}
			nextSprite = 0;
			nextRow += 482;
		}
		for (int i = 0; i < 4; i++) {
			clips[nextClip].x = nextSprite;
			clips[nextClip].y = 3374;
			clips[nextClip].w = 482;
			clips[nextClip].h = 482;
			++nextClip;
			nextSprite += 482;
		}
		int frame = 0;
		while (isRunning()) {
			handleEvents();
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			SDL_Rect* currentFrame = &clips[frame/10];
			sheet.render((800 - currentFrame->w)/2, (500 - currentFrame->h)/2, 
				renderer, currentFrame);
			
			SDL_RenderPresent(renderer);
			++frame;
			std::cout << frame <<std::endl;
			if (frame/10 >= ANIMATION_FRAMES)
			{
				frame = 0;
			}
		}
		
	}

	void Game::gameOff()
	{
		bg.free();
		bomb.free();
		std::cout << "Textures Freed" << std::endl;
		SDL_DestroyRenderer(renderer);
		std::cout << "Renderer Destroyed" << std::endl;
		renderer = NULL;
		SDL_DestroyWindow(window);
		std::cout << "Window Destroyed" << std::endl;
		window = NULL;
		IMG_Quit();
		SDL_Quit();
		std::cout << "Subsystems Ended" << std::endl;
	}

	bool Game::isRunning() {
		return running;
	}

	void Game::handleEvents(){
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
			}
		}
	}

}

