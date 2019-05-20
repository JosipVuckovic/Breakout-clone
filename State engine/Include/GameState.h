#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Game.h"
#include "BrickCreator.h"
#include "..\\Game\Include\Paddle.h"
class GameState :
	public State
{
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite BackgroundSprite;
	BrickCreator* brickC;
	Paddle* paddle;
public:
	GameState(GameDataRef data);
	~GameState();
	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;
	
protected:
	void CreateRedBrick(sf::Texture& texture, int i, int j);
	void CreateBlueBrick(sf::Texture& texture, int i, int j);
	void CreateCyanBrick(sf::Texture& texture, int i, int j);
	void CreateGreenBrick(sf::Texture& texture, int i, int j);
	void CreateScene();
};
#endif