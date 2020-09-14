#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H
#include "GameObject.h"
class Collision {
public:
	static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
private:
};
#endif // !GAME_COLLISION_H
