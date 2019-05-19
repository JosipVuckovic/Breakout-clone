#include "..\\Include\Brick.h"

#include <iostream>
std::list<Brick*> Brick::Bricks;
Brick::Brick(sf::Texture& texture, BrickTypes ID, int i, int j): _BAssets(new BrickAssets(texture, ID))
{
	_BrickSprite.setTexture(_BAssets->texture);
	_BrickSprite.setPosition(_BAssets->size.x+_BAssets->size.x*i, _BAssets->size.y*j);
	
	std::cout << _BrickSprite.getPosition().x << " " << _BrickSprite.getPosition().y << std::endl;
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(_BrickSprite);
}
