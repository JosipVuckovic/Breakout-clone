#include "..\\Game\Include\Ball.h"
#include "..\\Menagers\Include\Definitions.h"

Ball::Ball(sf::Texture& texture): _BallAssets (new BallAssets(texture))
{

}
Ball::~Ball() { delete _BallAssets; _BallAssets = nullptr; }


void Ball::Move()
{
	if (_BallAssets->Position.x<0 || _BallAssets->Position.x>SCREEN_WIDTH) _BallAssets->Direction.x = -_BallAssets->Direction.x;
	if (_BallAssets->Position.y<0 || _BallAssets->Position.y>SCREEN_HEIGHT) _BallAssets->Direction.y = -_BallAssets->Direction.y;

	_BallAssets->Direction *= BALL_SPEED;
	_BallAssets->BallSprite.move(_BallAssets->Direction);
}


void Ball::Update(const float& deltaTime)
{
	_BallAssets->Position = _BallAssets->BallSprite.getPosition();
	Move();
}
