
#include "..\\State engine\Include\GameState.h"
#include "..\\Menagers\Include\Definitions.h"


GameState::GameState(GameDataRef data): data(data), brickC(new BrickCreator)
{

}

GameState::~GameState()
{
}

void GameState::Init()
{

	/*	
	data->assets.LoadTexture("Background", BACKGROUND);
	data->assets.LoadTexture("RedBlock", RED);
	data->assets.LoadTexture("BlueBlock", BLUE);
	data->assets.LoadTexture("GreenBlock", GREEN);
	data->assets.LoadTexture("CyanBlock", CYAN);
	*/

	BackgroundSprite.setTexture(data->assets.GetTexture("Background"));
	CreateScene();

}

void GameState::HandleInput()
{
	sf::Event Event;
	while (data->window.pollEvent(Event))
	{
		if (sf::Event::Closed == Event.type)
			data->window.close();
	}
}
void GameState::Update(const float& deltaTime)
{
	
}

void GameState::Draw(const float& DeltaTime){

	data->window.clear();
	data->window.draw(BackgroundSprite);
	for (auto i : Brick::Bricks)
		i->draw(data->window);
	data->window.display();

}

void GameState::CreateScene()
{
	std::string board(data->assets.GetMap());

	// XML FILE PUTS ' ' in string so you need to remove that! 
	board.erase(std::remove_if(board.begin(), board.end(), [](char c) {return c == ' '; }), board.end());

	// translate from i=0 to i=1 because i=0 will draw brick outside of a window
	for( int i = 1; i!=board.length()+1; ++i) 
	{
		switch (board[i-1])
		{
		case 'R':
			brickC->CreateRedBrick(data->assets.GetTexture("Red"), i);
			break;
		case 'B':
			brickC->CreateBlueBrick(data->assets.GetTexture("Blue"), i);
			break;
		case 'C':
			brickC->CreateCyanBrick(data->assets.GetTexture("Cyan"), i);
			break;
		case 'G':
			brickC->CreateCyanBrick(data->assets.GetTexture("Green"), i);
			break;
		};
	}
}

