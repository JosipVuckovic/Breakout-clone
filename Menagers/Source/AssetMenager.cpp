#include "..\\Menagers\Include\AssetMenager.h"
#include <iterator>
AssetMenager::AssetMenager()
{
}


AssetMenager::~AssetMenager()
{
}

sf::Texture& AssetMenager::GetTexture(const std::string& name)
{ 
	return _mapTexture.at(name);
}

void AssetMenager::LoadTexturesFromXml()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(XML_FILE);

	
	//if XML file is't loaded print that error
	if (doc.ErrorID())
		std::cerr << "Failed to load file!! " << std::endl;


	tinyxml2::XMLElement* start = doc.FirstChildElement("Game");
	
	LoadBricks(start);
	LoadBoard(start);
	LoadPaddle(start);
	LoadBall(start);
}

void AssetMenager::LoadBricks(tinyxml2::XMLElement* element)
{
	/*set brick assets in map*/
	tinyxml2::XMLElement* BrickType = element->FirstChildElement("GameAssets");
	BrickType = BrickType->FirstChildElement("BrickType");
	sf::Texture texture;
	const char* path = "";
	const char* name = "";

	// iterate in XML and get out data
	for (; BrickType; BrickType = BrickType->NextSiblingElement("BrickType"))
	{
		BrickType->QueryStringAttribute("Texture", &path);
		BrickType->QueryStringAttribute("Name", &name);
		texture.loadFromFile(path);
		_mapTexture[name] = texture;
	}

}

void AssetMenager::LoadBoard(tinyxml2::XMLElement* element)
{
	/*set board assets in map*/
	tinyxml2::XMLElement* GameAssets = element->FirstChildElement("GameAssets");
	GameAssets = GameAssets->FirstChildElement("MapType");
	sf::Texture texture;
	const char* path = "";
	const char* BoardString;


	GameAssets->QueryStringAttribute("Map", &BoardString);
	BoardStr = BoardString;

	GameAssets->QueryStringAttribute("Texture", &path);
	texture.loadFromFile(path);
	_mapTexture["Background"] = texture;
}

void AssetMenager::LoadPaddle(tinyxml2::XMLElement* element)
{
	/*set paddle assets in map*/
	const char* path = "";
	const char* name = "";
	sf::Texture texture;
	tinyxml2::XMLElement* Paddle = element->FirstChildElement("GameAssets");
	Paddle = Paddle->FirstChildElement("Paddle");

	Paddle->QueryStringAttribute("Texture", &path);
	Paddle->QueryStringAttribute("Name", &name);
	texture.loadFromFile(path);
	_mapTexture[name] = texture;

}

void AssetMenager::LoadBall(tinyxml2::XMLElement* element)
{

	/* set ball assets in map*/
	const char* path = "";
	const char* name = "";
	sf::Texture texture;
	tinyxml2::XMLElement* Ball = element->FirstChildElement("GameAssets");
	Ball = Ball->FirstChildElement("Ball");

	Ball->QueryStringAttribute("Texture", &path);
	Ball->QueryStringAttribute("Name", &name);
	texture.loadFromFile(path);
	_mapTexture[name] = texture;
}
