#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

struct BallAssets
{
	sf::Texture Texture;
	sf::Sprite BallSprite;
	sf::Vector2f Velocity;
	sf::Vector2f Position;
	sf::Vector2f Direction;

	BallAssets(sf::Texture& texture): Velocity(0.f,0.f), Position(300. , 300.f), Direction(5.,6.)
	{	
		this->Texture = texture;
		BallSprite.setTexture(this->Texture);
		BallSprite.setPosition(Position);
	}
};

class Ball
{
	BallAssets* _BallAssets;
public:
	Ball(sf::Texture& texture);
	~Ball();



	void Move();
	void Update();
	void Draw(sf::RenderWindow& window);

	sf::FloatRect GetSize()const { return _BallAssets->BallSprite.getGlobalBounds(); }
	void SetDirection(const int& Y_dir) { _BallAssets->Direction.y = (float)Y_dir; }
	void ReverseDirection() { _BallAssets->Direction = -_BallAssets->Direction; }

	
};
#endif // !1
