#include "bomb.h"

Bomb::Bomb(const char* sheetPath, SDL_Renderer* renderer, int xpos, int ypos) : GameObject(sheetPath, renderer, xpos, ypos)
{
	inside = false;
	movementRate = 2;
	randomDirectionX = 1;
	randomDirectionY = 1;
	frames = 0;
	animate();
}

void Bomb::animate()
{
	//takes the sprite sheet loaded by GameObject and clips it into indvidual frames for animation
	int nextRow = 0;
	int nextClip = 0;
	int nextSprite = 0;
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 8; j++) {
			animatedFrames[nextClip].x = nextSprite;
			animatedFrames[nextClip].y = nextRow;
			animatedFrames[nextClip].w = 482;
			animatedFrames[nextClip].h = 482;
			nextSprite += 482;
			++nextClip;
		}
		nextSprite = 0;
		nextRow += 482;
	}
	for (int i = 0; i < 4; i++) {
		animatedFrames[nextClip].x = nextSprite;
		animatedFrames[nextClip].y = 3374;
		animatedFrames[nextClip].w = 482;
		animatedFrames[nextClip].h = 482;
		++nextClip;
		nextSprite += 482;
	}
}

void Bomb::update()
{
	//takes the srcrect and places the animated frames into it depending on current frames
		m_srcRect = animatedFrames[frames];
		++frames;
		if (frames >= 60) {
			frames = 0;
			randomDirectionX = rand() % 2;
			randomDirectionY = rand() % 2;
		}
	m_destRect.w = 64;
	m_destRect.h = 64;
	m_destRect.x = m_xpos;
	m_destRect.y = m_ypos;
}

void Bomb::movement(SDL_Rect box[])
{
	//this if statement checks if it's inside the scorebox
		if (m_xpos > box[0].x  && 
			m_xpos < box[1].x && 
			m_ypos > box[2].y && 
			m_ypos < box[3].x) 
		{
			inside = true;
		}
		else { inside = false; }
	
		//if not inside then move randomly outside
	if (!inside) {

		if (randomDirectionX == 1)
		{
			if (!Collision::AABB(m_destRect, box[0]) && m_xpos < 733)
			{
				m_xpos += movementRate;
			
			}
			else if (!Collision::AABB(m_destRect, box[1]))
			{
				m_xpos -= movementRate;
			}
		}
		else {
			if (!Collision::AABB(m_destRect, box[1]) && m_xpos > 0)
			{
				m_xpos -= movementRate;			
			}
			else if (!Collision::AABB(m_destRect, box[0]))
			{
				m_xpos += movementRate;
			}
		}
		if (randomDirectionY == 1) {
			if (!Collision::AABB(m_destRect, box[2]) && m_ypos < 586 )
			{
				m_ypos += movementRate;
			}
			else if (!Collision::AABB(m_destRect, box[3]))
			{
				m_ypos -= movementRate;
			}
		}
		else {
			if (!Collision::AABB(m_destRect, box[3]) && m_ypos > 0) {
				m_ypos -= movementRate;
			
			}
			else if (!Collision::AABB(m_destRect, box[2])) {
				m_ypos += movementRate;
			
			}
		}
	}
	else //otherwise move randombly inside
	{
		if (randomDirectionX == 1) 
		{
			if (!Collision::AABB(m_destRect, box[0])) 
			{
				m_xpos -= movementRate;
			}
			else if (!Collision::AABB(m_destRect, box[1]))
			{
				m_xpos += movementRate;
			}
		}
		else {
			if (!Collision::AABB(m_destRect, box[1]))
			{
				m_xpos += movementRate;
			}
			else if(!Collision::AABB(m_destRect, box[0])) 
			{
				m_xpos -= movementRate;
			}
		}

		if (randomDirectionY == 1) {
			if (!Collision::AABB(m_destRect, box[2])) 
			{
				m_ypos -= movementRate;
			}
			else if (!Collision::AABB(m_destRect, box[3])) 
			{
				m_ypos += movementRate;
			}
		}
		else {
			if (!Collision::AABB(m_destRect, box[3])) {
				m_ypos += movementRate;
			}
			else if (!Collision::AABB(m_destRect, box[2]) ) {
				m_ypos -= movementRate;
			}
		}
		
	}

	
	

}



