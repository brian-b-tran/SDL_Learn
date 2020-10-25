#ifndef SORT_GAME_TEXTURE_WRAPPER_H
#define SORT_GAME_TEXTURE_WRAPPER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
namespace sortGame {
    class LTexture
    {
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        void loadFromFile(std::string path, SDL_Renderer* renderer);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = NULL);

        //Gets image dimensions
        int getWidth();
        int getHeight();

 
    };
}
#endif // !SORT_GAME_TEXTURE_WRAPPER_H
