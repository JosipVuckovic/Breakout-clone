#ifndef ASSETMENAGER_H
#define ASSETMENAGER_H
#include <map>
#include <array>
#include <string>
#include <SFML/Graphics.hpp>

class AssetMenager
{
	std::map<std::string, sf::Texture> _mapTexture;
	std::map<std::string, sf::Font> _mapFonts;
public:
	AssetMenager();
	~AssetMenager();

	void LoadTexture(const std::string& name, const std::string& fileName);
	void LoadFont(std::string& name, std::string& fileName);

	sf::Texture& GetTexture(const std::string& name);
	sf::Font& GetFont(const std::string& name);
};

#endif
