#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
#include "Game.h"

class MenuState :
	public State
{
	GameDataRef data;
	sf::Sprite backgroundSprite;
	sf::Sprite playButton;
public:
	MenuState(GameDataRef data);
	~MenuState();

	/*
		FOR INFO OF THIS METHODS GO INTO STATE.H  
	*/
	virtual void Init()override;
	virtual void HandleInput()override;
	virtual void Update(const float& deltaTime)override;
	virtual void Draw(const float& DeltaTime)override;
};
#endif 