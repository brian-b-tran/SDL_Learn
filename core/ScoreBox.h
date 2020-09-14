#ifndef GAME_OBJECT_SCOREBOX_H
#define GAME_OBJECT_SCOREBOX_H
#include "GameObject.h"
class ScoreBox : public GameObject
{
public:
	ScoreBox(const char* sheetPath, SDL_Renderer* renderer, int xpos = 0, int ypos = 0);
	~ScoreBox(); 
	void render() override;
	void setBox();
	SDL_Rect* getBox();
	static SDL_Rect box[4];
private:
	
};
#endif // !GAME_OBJECT_SCOREBOX_H
