#include "..\\Game\Include\Ball.h"
#include "..\\Menagers\Include\Definitions.h"


Ball::Ball(sf::Texture& texture) : _BallAssets(new BallAssets(texture)) {}
Ball::~Ball() { delete _BallAssets; _BallAssets = nullptr; }


void Ball::Move()
{

	//if ball is in screen dimension then move
	_BallAssets->Position = _BallAssets->BallSprite.getPosition();
	if (_BallAssets->Position.x<0 || _BallAssets->Position.x>SCREEN_WIDTH) _BallAssets->Direction.x = -_BallAssets->Direction.x;
	if (_BallAssets->Position.y<0 || _BallAssets->Position.y>SCREEN_HEIGHT) _BallAssets->Direction.y = -_BallAssets->Direction.y;


	_BallAssets->BallSprite.move(_BallAssets->Direction);
}


void Ball::Update()
{
	Move();
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(_BallAssets->BallSprite);
}
