#include "game.h"


Game::Game()
{
	running = false;
	
	window = nullptr;
}
Game::~Game()
{
	close();
}
//initialized SDL subsystems, can be made to take init flags
void Game::init() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		std::cout << "Could not initialize SDL subsystems" << std::endl;
		running = false;
	}
	
	if (IMG_Init(IMG_INIT_PNG) != 2) {
		std::cout << "Did not load png from SDL_Image" << std::endl;
		running = false;
	}

	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!");
	}

	std::cout << "SDL subsystems initialized" << std::endl;

	window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
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
	running = true;
	blueBombs = new Bomb("assets/bombs/Sheets/Blue.png", renderer, 400, 300);
	yellowBombs = new Bomb("assets/bombs/Sheets/Yellow.png", renderer, 400, 533);
	redBombs = new Bomb("assets/bombs/Sheets/Red.png", renderer, 0, 320);
	greenBombs = new Bomb("assets/bombs/Sheets/Green.png", renderer, 733, 320);

	bombs.push_back(blueBombs);
	bombs.push_back(yellowBombs);
	bombs.push_back(redBombs);
	bombs.push_back(greenBombs);
	
	scorebox1 = new ScoreBox("assets/map/Wall.png", renderer, 0, 0);

}
//handles events
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
		}
	}
}

//updates the objects
void Game::update()
{
	for (auto b : bombs) {
		b->update();
		b->movement(scorebox1->getBox());
		
	}
	
}

//renders the objects
void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto b : bombs) {
		b->render();
	}
	scorebox1->render();
	SDL_RenderPresent(renderer);


}

//cleans up
void Game::close()
{
	SDL_DestroyRenderer(renderer);
	std::cout << "Renderer Destroyed" << std::endl;
	renderer = NULL;
	SDL_DestroyWindow(window);
	std::cout << "Window Destroyed" << std::endl;
	window = NULL;
	SDL_Quit();
	IMG_Quit();
	std::cout << "Subsystems Quit" << std::endl;
	for (auto e : bombs) {
		delete[] e;
	}
}




//getters
bool Game::isRunning()
{
	return running;
}
SDL_Window* Game::getWindow()
{
	return this->window;
}
