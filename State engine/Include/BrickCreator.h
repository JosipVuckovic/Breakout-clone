#ifndef BRICKCREATOR_H
#define BRICKCREATOR_H
#include "..\\Game\Include\Brick.h"
class BrickCreator
{

public: 

	void CreateRedBrick(sf::Texture& texture, int row);
	void CreateBlueBrick(sf::Texture& texture, int row);
	void CreateGreenBrick(sf::Texture& texture, int row);
	void CreateCyanBrick(sf::Texture& texture, int row);
};
#endif // !BRICKCREATOR_H
