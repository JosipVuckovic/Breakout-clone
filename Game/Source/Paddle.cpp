#include "..\\Game\Include\Paddle.h"
#include "..\\Menagers\Include\Definitions.h"
#include <iostream>
using std::endl;
using std::cout;
Paddle::Paddle(sf::Texture texture) : _PaddleAssets(new PaddleAssets(texture))
{
	
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
	}else // if key is not pressed, the reset velocity, because it causes bugs if its not set on 0
	{
		_PaddleAssets->Velocity.x = 0;
	}

	Move(_PaddleAssets->Velocity);
}

void Paddle::Move(sf::Vector2f velocity)
{
	// constant update position
	_PaddleAssets->Position = _PaddleAssets->Paddle.getPosition();

	// swap places
	 /* if position is greater then screen width then set position before left begin of the screen*/
	if (_PaddleAssets->Position.x > SCREEN_WIDTH ) 
	{
		_PaddleAssets->Paddle.setPosition(-_PaddleAssets->GlobalBounds.width, _PaddleAssets->Position.y);
	}
	/* if paddle goes negative (left of the screen) then set paddle after right side of the screen */

	else if(_PaddleAssets->Position.x <-_PaddleAssets->GlobalBounds.width)
	{
		_PaddleAssets->Paddle.setPosition(SCREEN_WIDTH,_PaddleAssets->Position.y);
	}

	_PaddleAssets->Paddle.move(velocity);
}
