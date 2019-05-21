#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "State.h"

class IntroState:
	public State
{
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
public:
	IntroState(GameDataRef data);
	~IntroState();

	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;
};
#endif 
