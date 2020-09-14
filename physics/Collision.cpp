#include "Collision.h"

bool Collision::AABB(const SDL_Rect& a, const SDL_Rect& b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x  ;
	rightA = a.x + a.w  ;
	topA = a.y;
	bottomA = a.y + a.h ;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;


		if (leftA < rightB &&
			rightA > leftB &&
			topA < bottomB &&
			bottomA > topB)
		{
			return true;
		}
		return false;
	
	
}
