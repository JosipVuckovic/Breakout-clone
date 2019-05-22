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
	std::list<Brick*> Bricks;

public:
	GameState(GameDataRef data);
	~GameState();
	/*
		FOR INFO OF THIS METHODS GO INTO STATE.H
	*/
	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;

private:
	void CreateRedBrick(sf::Texture& texture, int i, int j);
	void CreateBlueBrick(sf::Texture& texture, int i, int j);
	void CreateCyanBrick(sf::Texture& texture, int i, int j);
	void CreateGreenBrick(sf::Texture& texture, int i, int j);
	void CreateScene();


	// universal method for creating bricks
	void CreateBrick(sf::Texture& texture, int row, BrickTypes type);
	

	// see if ball is collided with object paddle or brick! 
	bool isCollided(sf::FloatRect RectOne, sf::FloatRect RectTwo)const { return RectOne.intersects(RectTwo);};


	// if ball hit brick then erase brick from list
	void UpdateBorad();
};
#endif