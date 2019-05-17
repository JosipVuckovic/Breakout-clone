
#include "..\\Menagers\Include\Definitions.h"
#include "..\\State engine\Include\GameState.h"
#include "..\\State engine\Include\MenuState.h"
#include <iostream>
MenuState::MenuState(GameDataRef data): data(data)
{
}


MenuState::~MenuState()
{
}

void MenuState::Init()
{

	data->assets.LoadTexture("PlayButton", PLAY_BUTTON);
	data->assets.LoadTexture("initBackground", INIT_STATE_BACKGROUND);


	backgroundSprite.setTexture(data->assets.GetTexture("initBackground"));
	playButton.setTexture(data->assets.GetTexture("PlayButton"));

	playButton.setPosition(SCREEN_WIDTH /2-(playButton.getGlobalBounds().width/2),
		0);
}

void MenuState::HandleInput()
{
	sf::Event Tetris;
	while (data->window.pollEvent(Tetris))
	{
		if (sf::Event::Closed == Tetris.type)
			data->window.close();
		if (data->input.IsSpriteClicked(playButton, sf::Mouse::Left, data->window))
			data->machine.AddState((StateRef)new GameState(data), true);
	}
}

void MenuState::Update(const float& deltaTime)
{

}

void MenuState::Draw(const float& DeltaTime)
{
	data->window.clear();
	data->window.draw(backgroundSprite);
	data->window.draw(playButton);
	data->window.display();
}
