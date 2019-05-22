#ifndef GAME_H
#define GAME_H
#include <memory>


#include <SFML/Graphics.hpp>


#include "..\\Menagers\Include\AssetMenager.h"
#include "..\\State engine\Include\StateMachine.h"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetMenager assets;
	
};
typedef std::shared_ptr<GameData> GameDataRef;
class Game
{
	const float deltaTime = 1.0f / 60.0f; //framerate;
	sf::Clock clock;
	GameDataRef data = std::make_shared<GameData>();
public:
	Game(int width, int height, std::string title);
	~Game();

	// init game 
	void Run();
};

#endif 
