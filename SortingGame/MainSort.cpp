#include "Game.h"
sortGame::Game* game = nullptr;
int main(int argc, char* args[]) {
	const int FRAME_DELAY = 1000 / ANIMATION_FRAMES;
	Uint32 FRAME_START;
	int FRAME_TIME;
	game = new sortGame::Game();
	game->gameOn("SortingGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,600);
	game->update();
	game->gameOff();
	

	return 0;
}