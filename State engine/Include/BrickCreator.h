#ifndef BRICKCREATOR_H
#define BRICKCREATOR_H
#include "..\\Game\Include\Brick.h"
class BrickCreator
{
public: 
	 /*allocate memory and create bricks on screen */
	void CreateBrick(sf::Texture& texture, int row, BrickTypes type);
};
#endif // !BRICKCREATOR_H
