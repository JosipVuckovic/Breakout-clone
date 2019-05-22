#include "..\\Include\Brick.h"
#include <iostream>


Brick::Brick(sf::Texture& texture, BrickTypes ID, int i, int j): _BAssets(new BrickAssets(texture, ID))
{
	// first set texture then position 
	_BrickSprite.setTexture(_BAssets->texture);
	// first parameter is on X axis, second on Y axis
	//FIRST-> translate brick by _BAssets->size.x and draw it!

	_BrickSprite.setPosition(_BAssets->size.x + _BAssets->size.x * i, _BAssets->size.y * j);
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(_BrickSprite);
}
