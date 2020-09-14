#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
class Texture 
{
private:
	
public:
	static SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);
};

#endif // !



