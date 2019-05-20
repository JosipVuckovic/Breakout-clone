#include "..\\Game\Include\Paddle.h"
#include "..\\Menagers\Include\Definitions.h"
Paddle::Paddle(sf::Texture texture) : _PaddleAssets(new PaddleAssets(texture))
{
	
	_PaddleAssets->Paddle.setPosition(300,400);
}

Paddle::~Paddle()
{
	delete _PaddleAssets; _PaddleAssets = nullptr;
}

void Paddle::Draw(sf::RenderWindow& window)
{
	window.draw(_PaddleAssets->Paddle);
}

void Paddle::UpdateMovement(const float& deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		_PaddleAssets->Velocity.x = -(deltaTime * PADDLE_SPEED);
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		_PaddleAssets->Velocity.x = deltaTime * PADDLE_SPEED;
	}else
	{
		_PaddleAssets->Velocity.x = 0;
	}

	Move(_PaddleAssets->Velocity);
}

void Paddle::Move(sf::Vector2f velocity)
{
	_PaddleAssets->Paddle.move(velocity);
}
