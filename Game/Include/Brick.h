#ifndef BRICK_H
#define BRICK_H
#include <string>

#include <SFML/Graphics.hpp>
#include "..\\Menagers\Include\AssetMenager.h"


struct BrickAssets{
	sf::Texture texture;
	AssetMenager* assets;
	BrickAssets(std::string& TextureName) : assets(new AssetMenager)
	{
		if (!TextureName.empty())
		{
			try
			{
				texture = assets->GetTexture(TextureName.c_str());
			}
			catch (X& x)
			{
				x.err();
			}
		}
	}
};

class Brick 
{
	BrickAssets* _BAssets;
	sf::Sprite _BrickSprite;
public:

	Brick(std::string TextureName);
	void draw(sf::RenderWindow& window);
};
#endif // !BRICK_H
