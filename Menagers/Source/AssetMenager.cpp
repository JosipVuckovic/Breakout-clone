#include "..\\Menagers\Include\AssetMenager.h"
#include <iterator>
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

void AssetMenager::LoadTexturesFromXml()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XML_FILE);

	if (doc.ErrorID())
		std::cerr << "Failed to load file!! " << std::endl;

	tinyxml2::XMLElement* start = doc.FirstChildElement("Game");
	LoadBricks(start);
	LoadBoard(start);
}

void AssetMenager::LoadBricks(tinyxml2::XMLElement* element)
{
	tinyxml2::XMLElement* BrickType = element->FirstChildElement("GameAssets");
	BrickType = BrickType->FirstChildElement("BrickType");
	sf::Texture texture;
	const char* path = "";


	BrickType->QueryStringAttribute("Texture", &path);
	texture.loadFromFile(path);
	_mapTexture["Red"] = texture;
	BrickType = BrickType->NextSiblingElement("BrickType");


	BrickType->QueryStringAttribute("Texture", &path);
	texture.loadFromFile(path);
	_mapTexture["Blue"] = texture;
	BrickType = BrickType->NextSiblingElement("BrickType");


	BrickType->QueryStringAttribute("Texture", &path);
	texture.loadFromFile(path);
	_mapTexture["Green"] = texture;
	BrickType = BrickType->NextSiblingElement("BrickType");


	BrickType->QueryStringAttribute("Texture", &path);
	texture.loadFromFile(path);
	_mapTexture["Cyan"] = texture;
	BrickType = BrickType->NextSiblingElement("MapType");

	const char* BoardString;
	BrickType->QueryStringAttribute("Map", &BoardString);
	BoardStr = BoardString;
	BrickType = BrickType->NextSiblingElement("MapTexture");


	BrickType->QueryStringAttribute("MapTexture", &path);
	texture.loadFromFile(path);
	_mapTexture["Background"] = texture;

}

void AssetMenager::LoadBoard(tinyxml2::XMLElement* element)
{

}
