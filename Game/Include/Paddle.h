#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>
struct PaddleAssets
{
	sf::Texture texture;
	sf::Vector2f Velocity;
	sf::Vector2f MovementSpeed;
	sf::Sprite Paddle;
	PaddleAssets(sf::Texture texture) : MovementSpeed(0.f, 0.f),Velocity(0.f,0.f)
	{
		this->texture = texture;
		Paddle.setTexture(this->texture);
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

};
#endif // !PADDLE_H
