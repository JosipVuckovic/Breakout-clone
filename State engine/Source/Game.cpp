#include "..\\State engine\Include\Game.h"
#include "..\\State engine\Include\IntroState.h"

Game::Game(int width, int height, std::string title)
{
	data->window.create(sf::VideoMode(width,height),title);
	data->machine.AddState((StateRef)new IntroState(data));
	Run();
}


Game::~Game()
{
}

void Game::Run()
{
	float newTime, frameTime, interpolation;
	float currentTime = clock.getElapsedTime().asSeconds();
	float accumulator=0.0f;
	while (data->window.isOpen())
	{
		data->machine.ProcessStateChanges();
		newTime = clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f)
		{
			frameTime = 0.025f;
		}
		currentTime = newTime;
		accumulator += frameTime;
		while (accumulator>deltaTime)
		{
			data->machine.GetActiveState()->HandleInput();
			data->machine.GetActiveState()->Update(deltaTime);
			accumulator -= deltaTime;
		}
		interpolation = accumulator / deltaTime;
		data->machine.GetActiveState()->Draw(interpolation);
	}
}
