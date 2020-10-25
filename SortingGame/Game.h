#ifndef SORT_GAME_H
#define SORT_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureWrapper.h"
const int ANIMATION_FRAMES = 60;
namespace sortGame {
	class Game {
	private:
		SDL_Renderer* renderer = NULL;
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;
		//SDL_Texture* texture = NULL;
		SDL_Event event;
		//LoadMedia mediaLoader;
		LTexture bomb;
		LTexture bg;
		LTexture sheet;
		SDL_Rect clips [ANIMATION_FRAMES];
		bool running = true;
		
		
	public:
		Game();
		~Game();
		void gameOn(const char* title, int posx, int posy, int width, int height, bool fullscreen = false);
		void update();
		void handleEvents();
		void gameOff();
		bool isRunning();
	};
}


#endif 
