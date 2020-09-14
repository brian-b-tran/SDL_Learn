#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "bomb.h"
#include "Collisionh.h"
#include "ScoreBox.h"
class Game {
private:
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 640;
	bool running;
	SDL_Window* window;

	Bomb* blueBombs;
	Bomb* yellowBombs;
	Bomb* redBombs;
	Bomb* greenBombs;

	ScoreBox* scorebox1;
	std::vector<Bomb*> bombs;
	SDL_Renderer* renderer;
public:
	Game();
	~Game();
	SDL_Window* getWindow();
	void init();
	bool isRunning();
	void handleEvents();
	void close();
	void update();
	void render();
	 
};

#endif // !1



