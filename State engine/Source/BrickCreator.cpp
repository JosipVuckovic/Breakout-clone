#include "..\\State engine\Include\BrickCreator.h"
#include "..\\Menagers\Include\Definitions.h"

void BrickCreator::CreateBrick(sf::Texture& texture, int row, BrickTypes type)
{
	for (int i = 0; i < NUMBER_OF_BRICKS; ++i)
	{
		Brick* b = new Brick(texture, type, i, row);
		Brick::Bricks.push_back(b);
	}
}
