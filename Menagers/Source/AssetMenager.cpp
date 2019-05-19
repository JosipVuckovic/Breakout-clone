#include "..\\Menagers\Include\AssetMenager.h"

AssetMenager::AssetMenager()
{
}


AssetMenager::~AssetMenager()
{
}

void AssetMenager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture text;
	try
	{
		text.loadFromFile(fileName);
		_mapTexture[name] = text;
	}
	catch (X& x)
	{
		x.err();
	}
	
}

void AssetMenager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	try
	{
		font.loadFromFile(fileName);
		_mapFonts[name] = font;

	}
	catch (X& x)
	{
		x.err();
	}
}


sf::Texture& AssetMenager::GetTexture(const std::string& name)
{ 
	return _mapTexture.at(name);
}

sf::Font& AssetMenager::GetFont(const std::string& name)
{
	return _mapFonts.at(name);
}
