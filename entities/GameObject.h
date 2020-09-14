
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class GameObject {
protected:
	int m_xpos, m_ypos;
	SDL_Texture* m_displayTexture;
	SDL_Rect m_srcRect, m_destRect;
	SDL_Renderer* m_renderer;
	bool directionRight;
	
public:
	GameObject();
	GameObject(const char* sheetPath, SDL_Renderer* renderer, int xpos = 0, int ypos = 0);
	~GameObject();
	virtual void update();
	virtual void render();
	int getXpos() const;
	int getYpos()const;

	void resetPos(bool up);
	void changeDirection(bool direction);
};

#endif
