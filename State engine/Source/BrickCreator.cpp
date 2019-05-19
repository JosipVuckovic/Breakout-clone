#include "..\\State engine\Include\BrickCreator.h"


void BrickCreator::CreateRedBrick(sf::Texture& texture, int row)
{
	for(int i=0; i<15;++i)
	{
		Brick* b = new Brick(texture, BrickTypes::red, i, row);
		Brick::Bricks.push_back(b);
	}	
}

void BrickCreator::CreateBlueBrick(sf::Texture& texture, int row)
{
	for(int i=0; i<15;++i)
	{
		Brick* b = new Brick(texture, BrickTypes::blue,i, row);
		Brick::Bricks.push_back(b);
	}
}

void BrickCreator::CreateGreenBrick(sf::Texture& texture, int row)
{

	for(int i=0; i<15; ++i) 
	{
		Brick* b = new Brick(texture, BrickTypes::green, i, row);
		Brick::Bricks.push_back(b);
	}
}

void BrickCreator::CreateCyanBrick(sf::Texture& texture, int row)
{
	for (int i = 0; i < 15; ++i)
	{
		Brick* b = new Brick(texture, BrickTypes::cyan, i, row);
		Brick::Bricks.push_back(b);
	}

}