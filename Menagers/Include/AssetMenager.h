#ifndef ASSETMENAGER_H
#define ASSETMENAGER_H
#include <map>
#include <string>

#include <iostream>
#include <SFML/Graphics.hpp>

#include "..\\tinyxml2\tinyxml2.h"
#include "Definitions.h"


/*Exceptin message class */
class X { public: void err() { std::cout << "Unable to load file"; } };

class AssetMenager
{
	std::map<std::string, sf::Texture> _mapTexture;
	std::string BoardStr; 
public:
	AssetMenager();
	~AssetMenager();

	sf::Texture& GetTexture(const std::string& name);

	// first load XML file  
	void LoadTexturesFromXml();

	// load bricks from XML file 
	void LoadBricks(tinyxml2::XMLElement* element);
	
	//Load Board assets from XML file
	void LoadBoard(tinyxml2::XMLElement* element);
	
	//Load Paddle assets from XML file
	void LoadPaddle(tinyxml2::XMLElement* element);

	//string is representing bricks on map
	std::string GetMap()const { return BoardStr; };
};

#endif
