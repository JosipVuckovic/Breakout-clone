#include "..\\Include\Brick.h"

Brick::Brick(std::string TextureName) : _BAssets(new BrickAssets(TextureName))
{
	_BrickSprite.setTexture(_Assets->assets->GetTexture(TextureName));
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(_BrickSprite);
}
