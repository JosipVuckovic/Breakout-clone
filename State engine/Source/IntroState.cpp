

#include "..\\State engine\Include\IntroState.h"
#include "..\\State engine\Include\MenuState.h"
#include "..\\Menagers\Include\Definitions.h"
IntroState::IntroState(GameDataRef data): data(data)
{

}


IntroState::~IntroState()
{
}

void IntroState::Init()
{

}

void IntroState::HandleInput()
{
	sf::Event Tetris;
	while (data->window.pollEvent(Tetris))
	{
		if (sf::Event::Closed == Tetris.type)
		{
			data->window.close();
		}
	}
}

void IntroState::Update(const float& deltaTime)
{
	if(clock.getElapsedTime().asSeconds()>3)
	{
		data->machine.AddState((StateRef)new MenuState(data),true);
	}
}

void IntroState::Draw(const float& DeltaTime)
{
	data->window.clear();

	//handle update
	data->window.display();
}
