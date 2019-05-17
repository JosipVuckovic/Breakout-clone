
#include "..\\State engine\Include\GameState.h"
#include "..\\Menagers\Include\Definitions.h"

GameState::GameState(GameDataRef data): data(data)
{

}


GameState::~GameState()
{
}

void GameState::Init()
{

}

void GameState::HandleInput()
{
	sf::Event Tetris;
	while (data->window.pollEvent(Tetris))
	{
		if (sf::Event::Closed == Tetris.type)
			data->window.close();
	}
}

void GameState::Update(const float& deltaTime)
{
	data->window.clear();

	//handle game update

	data->window.display();
}

void GameState::Draw(const float& DeltaTime){}
