#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>
struct PaddleAssets
{
	sf::Texture texture;
	sf::Vector2f Velocity;
	sf::Vector2f MovementSpeed;
	sf::Sprite Paddle;
	sf::Vector2f Position;
	sf::FloatRect GlobalBounds;
	PaddleAssets(sf::Texture texture) : MovementSpeed(0.f, 0.f),Velocity(0.f,0.f), Position(300.f,400.f)
	{
		this->texture = texture;
		Paddle.setTexture(this->texture);
		GlobalBounds = this->Paddle.getGlobalBounds();
		this->Paddle.setPosition(Position);
	}
};
class Paddle 
{  
	PaddleAssets* _PaddleAssets;
public: 
	Paddle(sf::Texture texture);
	~Paddle();
	void Draw(sf::RenderWindow& window);
	void UpdateMovement(const float& deltaTime);
	void Move(sf::Vector2f velocity);


	sf::FloatRect GetGlobalBounds()const {return _PaddleAssets->Paddle.getGlobalBounds(); }
};
#endif // !PADDLE_H
