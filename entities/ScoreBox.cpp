#include "ScoreBox.h"
SDL_Rect ScoreBox::box[4] = {};
ScoreBox::ScoreBox(const char* sheetPath, SDL_Renderer* renderer, int xpos, int ypos) : GameObject(sheetPath, renderer, xpos, ypos)
{
	
}
ScoreBox::~ScoreBox()
{
}

void ScoreBox::render()
{
	setBox();
	SDL_RenderCopyEx(m_renderer, m_displayTexture, &m_srcRect, &box[0], 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(m_renderer, m_displayTexture, &m_srcRect, &box[1], 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(m_renderer, m_displayTexture, &m_srcRect, &box[2], 0, NULL, SDL_FLIP_NONE);
	SDL_RenderCopyEx(m_renderer, m_displayTexture, &m_srcRect, &box[3], 0, NULL, SDL_FLIP_NONE);
}

void ScoreBox::setBox()
{
	m_srcRect.x = 0;
	m_srcRect.y = 0;
	m_srcRect.h = 32;
	m_srcRect.w = 32;

	box[0].w = 16;
	box[0].h = 128;
	box[0].x = 336;
	box[0].y = 240;

	box[1].w = 16;
	box[1].h = 128;
	box[1].x = 464;
	box[1].y = 240;

	box[2].w = 128;
	box[2].h = 16;
	box[2].x = 336;
	box[2].y = 240;

	box[3].w = 144;
	box[3].h = 16;
	box[3].x = 336;
	box[3].y = 368;
}

SDL_Rect* ScoreBox::getBox()
{
	return box;
}
