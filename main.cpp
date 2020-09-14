#include "./core/game.h"

int main(int argc, char* args[]) 
{
	const int fps = 60;
	const int frameDelay = 1000 / fps;
	Uint32 frameStart;
	int frameTime;
	Game* game = new Game;
	game->init();
	while(game->isRunning())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->render();
		game->update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	return 0;
}