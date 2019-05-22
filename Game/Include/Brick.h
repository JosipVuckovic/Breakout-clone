#ifndef BRICK_H
#define BRICK_H

#include <string>
#include <list>
#include <SFML/Graphics.hpp>

enum BrickTypes { red, green, blue, cyan, grey };

struct BrickAssets{
	sf::Texture texture;
	sf::Vector2f size;
	bool isDestroyed;
	BrickTypes ID;
	int row;
	BrickAssets(sf::Texture& texture, BrickTypes ID) : size(42.0f, 20.0f), isDestroyed(false)
	{
		this->texture = texture;
		this->ID = ID;
	}
};

class Brick 
{
	BrickAssets* _BAssets;
	sf::Sprite _BrickSprite;
public:

	Brick(sf::Texture& texture, BrickTypes ID, int i, int j);
	
	// used for drawing brick
	virtual void draw(sf::RenderWindow& window);

	// used for polymorf

	sf::FloatRect GetSize()const { return _BrickSprite.getGlobalBounds(); }


	void SetBrickDestroyed() { _BAssets->isDestroyed = true; }

	bool IsDestroyed()const { return _BAssets->isDestroyed; }
};

#endif // !BRICK_H
