#include "GameObject.h"

GameObject::GameObject()
{
	m_xpos = 0;
	m_ypos = 0;
	directionRight = true;
}

GameObject::GameObject(const char* sheetPath, SDL_Renderer* renderer, int xpos, int ypos)
{
	directionRight = true;
	m_xpos = xpos;
	m_ypos = ypos;
	m_renderer = renderer;
	m_displayTexture = Texture::loadTexture(sheetPath, renderer);
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
	m_xpos = 0;
	m_ypos = 0;

	m_srcRect.w = 482;
	m_srcRect.h = 482;
	m_srcRect.x = 0;
	m_srcRect.y = 0;


	m_destRect.w = 64;
	m_destRect.h = 64;
	m_destRect.x = m_xpos;
	m_destRect.y = m_ypos;

}

void GameObject::render()
{
	SDL_RendererFlip flip;
	if (!directionRight) {
		flip = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		flip = SDL_FLIP_NONE;
	}
	SDL_RenderCopyEx(m_renderer, m_displayTexture, &m_srcRect, &m_destRect, 0 , NULL, flip );
}

int GameObject::getXpos() const
{
	return m_xpos;
}

int GameObject::getYpos() const
{
	return m_ypos;
}

void GameObject::resetPos(bool up)
{
	//top of the screen
	if (up) {
		m_destRect.x = 400;
		m_destRect.y = 0;
	}
	else { //bottom of the screen
		m_destRect.x = 400;
		m_destRect.y = 533;
	}
}

void GameObject::changeDirection(bool direction)
{
	directionRight = direction;
}
