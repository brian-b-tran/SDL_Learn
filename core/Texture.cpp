#include "Texture.h"


SDL_Texture* Texture::loadTexture(const char* path , SDL_Renderer* renderer)
{
	SDL_Texture* theTexture = nullptr;
	SDL_Surface* tempSurface = IMG_Load(path);
	if (tempSurface == nullptr)
	{
		std::cout << "Could not load image from file" << std::endl 
			<< IMG_GetError() << std::endl;
	}
	else
	{
		theTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		
	}
	SDL_FreeSurface(tempSurface);
	
	return theTexture;
}
