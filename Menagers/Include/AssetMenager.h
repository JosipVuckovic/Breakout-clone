#ifndef ASSETMENAGER_H
#define ASSETMENAGER_H
#include <map>
#include <array>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "..\\TinyXml\tinyxml2.h"

class X { public: void err() { std::cout << "Unable to load file"; } };

enum BrickTypes{brick1, brick2, brick3, brick4};
class AssetMenager
{
	std::map<std::string, sf::Texture> _mapTexture;
	std::map<std::string, sf::Font> _mapFonts;
public:
	AssetMenager();
	~AssetMenager();

	void LoadInitParameters(const std::string& filename);
	void LoadBrickTextures(tinyxml2::XMLElement* file, BrickTypes type);
	sf::Texture& GetTexture(const std::string& name);
	sf::Font& GetFont(const std::string& name);
};

#endif
