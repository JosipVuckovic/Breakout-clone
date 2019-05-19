
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
	data->assets.LoadTexturesFromXml();

	//data->assets.LoadTexture("Background", BACKGROUND);
	//data->assets.LoadTexture("RedBlock", RED);
	//data->assets.LoadTexture("BlueBlock", BLUE);
	//data->assets.LoadTexture("GreenBlock", GREEN);
	//data->assets.LoadTexture("CyanBlock", CYAN);


	BackgroundSprite.setTexture(data->assets.GetTexture("Background"));

	brickC->CreateRedBrick(data->assets.GetTexture("Red"), 1);
	
	brickC->CreateBlueBrick(data->assets.GetTexture("Blue"), 2);
	brickC->CreateBlueBrick(data->assets.GetTexture("Blue"), 3);

	brickC->CreateGreenBrick(data->assets.GetTexture("Green"), 4);
	brickC->CreateGreenBrick(data->assets.GetTexture("Green"), 5);
	brickC->CreateGreenBrick(data->assets.GetTexture("Green"), 6);

	brickC->CreateCyanBrick(data->assets.GetTexture("Cyan"), 7);
	brickC->CreateCyanBrick(data->assets.GetTexture("Cyan"), 8);
	brickC->CreateCyanBrick(data->assets.GetTexture("Cyan"), 9);
	brickC->CreateCyanBrick(data->assets.GetTexture("Cyan"), 10);

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

