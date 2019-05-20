#ifndef ASSETMENAGER_H
#define ASSETMENAGER_H
#include <map>
#include <array>
#include <string>
#include <iostream>
#include "..\\tinyxml2\tinyxml2.h"
#include "Definitions.h"
#include <SFML/Graphics.hpp>


class X { public: void err() { std::cout << "Unable to load file"; } };

class AssetMenager
{
	std::map<std::string, sf::Texture> _mapTexture;
	std::string BoardStr; 
public:
	AssetMenager();
	~AssetMenager();

	sf::Texture& GetTexture(const std::string& name);

	void LoadTexturesFromXml();
	void LoadBricks(tinyxml2::XMLElement* element);
	void LoadBoard(tinyxml2::XMLElement* element);
	void LoadPaddle(tinyxml2::XMLElement* element);
	std::string GetMap()const { return BoardStr; };
};

#endif
