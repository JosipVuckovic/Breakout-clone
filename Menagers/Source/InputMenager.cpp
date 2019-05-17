#include "..\\Menagers\Include\InputMenager.h"

InputMenager::InputMenager()
{
}


InputMenager::~InputMenager()
{
}

bool InputMenager::IsSpriteClicked(sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window) const
{
	if(sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,
			object.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

sf::Vector2i InputMenager::GetMousePosition(const sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}
