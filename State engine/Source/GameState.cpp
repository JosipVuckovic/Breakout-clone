
#include "..\\State engine\Include\GameState.h"
#include "..\\Menagers\Include\Definitions.h"
#include <time.h>
#include "..\\State engine\Include\MenuState.h"
typedef std::list<Brick*>::iterator iter;
GameState::GameState(GameDataRef data): data(data)
{
	std::srand(static_cast<unsigned>(time(NULL)));
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
	paddle = new Paddle(data->assets.GetTexture("Paddle"));
	CreateBall();
	CreateScene();
	
}

void GameState::HandleInput()
{
	sf::Event Event;
	while (data->window.pollEvent(Event))
	{
		if (sf::Event::Closed == Event.type)
			data->window.close();
		if (balls.empty())
			data->machine.AddState((StateRef)new MenuState(data), true);
	}
}
void GameState::Update(const float& deltaTime)
{
	if(balls.size())
		DeleteBall();
	
	for (auto i : balls)
	{
		sf::FloatRect ballBounds = i->GetGlobalBounds();

		for (auto it : Bricks)
		{
			if (!isCollided(it->GetGlobalBounds(), ballBounds))
				continue;

			it->SetBrickDestroyed();
			i->ReverseDirection();
			++HitTimes;
			break;
		}



		if (isCollided(i->GetGlobalBounds(), paddle->GetGlobalBounds()))
		{
			int NewBallDir = -(rand() % 5 + 2);
			i->SetDirection(NewBallDir);
		}
	}

	paddle->UpdateMovement(deltaTime);

	if (HitTimes > 5) {
		CreateBall();
		HitTimes = 0;
	}


	std::for_each(balls.begin(), balls.end(), [&](Ball* ball) {ball->Update(); });
	
	
	
	UpdateBorad();
}

void GameState::Draw(const float& DeltaTime)
{

	data->window.clear();
	data->window.draw(BackgroundSprite);

//draw every brick in vector
	std::for_each(Bricks.begin(), Bricks.end(), [&](Brick* brick) {brick->draw(data->window); });

	paddle->Draw(data->window);
	
//draw every ball in vector
	std::for_each(balls.begin(), balls.end(), [&](Ball* ball) {ball->Draw(data->window); });

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
			CreateBrick(data->assets.GetTexture("Red"), i, BrickTypes::red);
			break;
		case 'B':
			CreateBrick(data->assets.GetTexture("Blue"), i, BrickTypes::blue);
			break;
		case 'C':
			CreateBrick(data->assets.GetTexture("Cyan"), i, BrickTypes::cyan);
			break;
		case 'G':
			CreateBrick(data->assets.GetTexture("Green"), i, BrickTypes::green);
			break;
		};
	}
}

void GameState::CreateBall()
{
	balls.push_back(new Ball(data->assets.GetTexture("Ball")));
}

void GameState::CreateBrick(sf::Texture& texture, int row, BrickTypes type)
{
	for (int i = 0; i < NUMBER_OF_BRICKS; ++i)
	{
		Brick* b = new Brick(texture, type, i, row);
		Bricks.push_back(b);
	}
}

void GameState::UpdateBorad()
{
	// see flag, if flag is destroyed delete it from list! 
	Bricks.erase(std::remove_if(Bricks.begin(), Bricks.end(), isvalid()), Bricks.end());
}

void GameState::CheckBall()
{
	balls.erase(std::remove_if(balls.begin(), balls.end(),

		[&](Ball* ball) 
	{
		sf::Vector2f ballpos = ball->GetBallPosition();
		if (ballpos.y < paddle->GetPaddlePosition().y+paddle->GetGlobalBounds().height)
			return false;
		return true;
	
	}
	
	), balls.end());
}