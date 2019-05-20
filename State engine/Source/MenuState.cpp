
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
	data->assets.LoadTexturesFromXml();
	//data->assets.LoadTexture("Background", BACKGROUND);
	backgroundSprite.setTexture(data->assets.GetTexture("Background"));
}

void MenuState::HandleInput()
{
	sf::Event Event;
	while (data->window.pollEvent(Event))
	{
		
		if (sf::Event::Closed == Event.type)
			data->window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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
	data->window.display();
}
