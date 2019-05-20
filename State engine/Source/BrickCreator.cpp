#include "..\\State engine\Include\BrickCreator.h"
#include "..\\Menagers\Include\Definitions.h"
void BrickCreator::CreateRedBrick(sf::Texture& texture, int row)
{
	for(int i=0; i<NUMBER_OF_BRICKS;++i)
	{
		Brick* b = new Brick(texture, BrickTypes::red, i, row);
		Brick::Bricks.push_back(b);
	}	
}

void BrickCreator::CreateBlueBrick(sf::Texture& texture, int row)
{
	for(int i=0; i<NUMBER_OF_BRICKS;++i)
	{
		Brick* b = new Brick(texture, BrickTypes::blue,i, row);
		Brick::Bricks.push_back(b);
	}
}

void BrickCreator::CreateGreenBrick(sf::Texture& texture, int row)
{

	for(int i=0; i<NUMBER_OF_BRICKS; ++i) 
	{
		Brick* b = new Brick(texture, BrickTypes::green, i, row);
		Brick::Bricks.push_back(b);
	}
}

void BrickCreator::CreateCyanBrick(sf::Texture& texture, int row)
{
	for (int i = 0; i < NUMBER_OF_BRICKS; ++i)
	{
		Brick* b = new Brick(texture, BrickTypes::cyan, i, row);
		Brick::Bricks.push_back(b);
	}

}