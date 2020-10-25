//#include "LoadMedia.h"
//#include "TextureWrapper.h"
//namespace sortGame {
//	SDL_Surface* LoadMedia::loadMedia(SDL_Surface* surface, std::string path) 
//	{
//		SDL_Surface* PNGSurface = NULL;
//		//Load PNG surface
//		PNGSurface = loadSurface(path, surface);
//		if (PNGSurface == NULL) {
//			std::cout << "could not load media" << std::endl;
//		}
//		return PNGSurface;
//
//	}
//
//	SDL_Surface* LoadMedia::loadSurface(std::string path, SDL_Surface* surface)
//	{
//		SDL_Surface* optimized = NULL;
//		SDL_Surface* loadSurface = IMG_Load(path.c_str());
//		if (loadSurface == NULL) {
//			std::cout << "could not load surface" << std::endl;
//		}
//		else {
//			optimized = SDL_ConvertSurface(loadSurface, surface->format, 0);
//		}
//		SDL_FreeSurface(loadSurface);
//		return optimized;
//	}
//
//	SDL_Texture* LoadMedia::loadMedia(sortingGame::LTexture texture, std::string path) {
//		 SDL_Texture* returnTexture = loadTexture(renderer, path);
//		 return returnTexture;
//	}
//
//	SDL_Texture* LoadMedia::loadTexture(SDL_Renderer* renderer, std::string path)
//	{
//		SDL_Texture* returnTexture = NULL;
//		//load the image from the path
//		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//		if (loadedSurface == NULL) {
//			std::cout << "Could not load surface for renderer" << std::endl;
//		}
//		else {
//			returnTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
//			SDL_FreeSurface(loadedSurface);
//		}
//
//		return returnTexture;
//	}
//}
