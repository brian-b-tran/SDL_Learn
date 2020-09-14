#ifndef BOMB_GAME_OBJECT_H
#define BOMB_GAME_OBJECT_H
#include "GameObject.h"
#include "Collisionh.h"
class Bomb : public GameObject
{
public:
	Bomb(const char* sheetPath, SDL_Renderer* renderer, int xpos = 0, int ypos = 0);
	void animate();
	void update () override;
	void movement(SDL_Rect box[]);
	bool inside;
	int movementRate;
private:
	int frames;
	SDL_Rect animatedFrames[60];

	int randomDirectionX;
	int randomDirectionY;


};
#endif // !BOMB_GAME_OBJECT_H

