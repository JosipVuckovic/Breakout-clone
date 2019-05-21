#ifndef BRICK_H
#define BRICK_H
#include <string>
#include <list>
#include <SFML/Graphics.hpp>

enum BrickTypes { red, green, blue, cyan, grey };

struct BrickAssets{
	sf::Texture texture;
	sf::Vector2f size;
	BrickTypes ID;
	BrickAssets(sf::Texture& texture, BrickTypes ID) : size(42.0f, 20.0f)
	{
		this->texture = texture;
		this->ID = ID;
	}
};

class Brick 
{
	BrickAssets* _BAssets;
	sf::Sprite _BrickSprite;
	int row;
public:

	Brick(sf::Texture& texture, BrickTypes ID, int i, int j);
	
	// used for drawing brick
	virtual void draw(sf::RenderWindow& window);

	// used for polymorf
	static std::list<Brick*> Bricks;
};
#endif // !BRICK_H
