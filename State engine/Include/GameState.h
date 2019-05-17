#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Game.h"

class GameState :
	public State
{
	GameDataRef data;
	sf::Clock clock;
public:
	GameState(GameDataRef data);
	~GameState();
	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;
};
#endif