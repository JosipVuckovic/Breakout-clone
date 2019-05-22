#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Game.h"
#include "..\\Game\Include\Paddle.h"
#include "..\\Game\Include\Ball.h"
#include "..\\Game\Include\brick.h"
class GameState :
	public State
{
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite BackgroundSprite;
	
	Paddle* paddle;
	Ball* ball;
public:
	GameState(GameDataRef data);
	~GameState();
	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;
	std::list<Brick*> Bricks;

protected:
	void CreateRedBrick(sf::Texture& texture, int i, int j);
	void CreateBlueBrick(sf::Texture& texture, int i, int j);
	void CreateCyanBrick(sf::Texture& texture, int i, int j);
	void CreateGreenBrick(sf::Texture& texture, int i, int j);
	void CreateScene();

	void CreateBrick(sf::Texture& texture, int row, BrickTypes type);
	
	bool isCollided(sf::FloatRect RectOne, sf::FloatRect RectTwo)const { return RectOne.intersects(RectTwo);};
};
#endif