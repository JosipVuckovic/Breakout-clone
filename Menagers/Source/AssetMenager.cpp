#include "..\\Menagers\Include\AssetMenager.h"

AssetMenager::AssetMenager()
{
}


AssetMenager::~AssetMenager()
{
}

void AssetMenager::LoadTexture(const std::string& name,const std::string& fileName)
{
	sf::Texture tempTexture;
	if(!tempTexture.loadFromFile(fileName))
	{
		throw std::runtime_error("Unable to load texture: " + fileName);
	}
	else
	{
		_mapTexture[name] = tempTexture;
	}

}

void AssetMenager::LoadFont(std::string& name, std::string& fileName)
{
	sf::Font tempFont;
	if(!tempFont.loadFromFile(fileName))
	{
		throw std::runtime_error("Unable to load Font: " + fileName);
	}
	else
	{
		_mapFonts[name] = tempFont;
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
