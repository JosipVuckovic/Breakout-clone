#ifndef INPUTMENAGER_H
#define INPUTMENAGER_H
#include <SFML/Graphics.hpp>
class InputMenager
{
public:
	InputMenager();
	~InputMenager();
	bool IsSpriteClicked(sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window)const;
	sf::Vector2i GetMousePosition(const sf::RenderWindow& window);
};
#endif