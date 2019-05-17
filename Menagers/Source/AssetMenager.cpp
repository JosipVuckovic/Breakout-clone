#include "..\\Menagers\Include\AssetMenager.h"

AssetMenager::AssetMenager()
{
}


AssetMenager::~AssetMenager()
{
}

void AssetMenager::LoadInitParameters(const std::string& filename)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename.c_str());
	if(doc.ErrorID)
	{
		throw X();
	}
	tinyxml2::XMLElement* el = doc.FirstChildElement("Menustate");
}

void AssetMenager::LoadBrickTextures(tinyxml2::XMLElement* file, BrickTypes type)
{
	const char* texture;
	tinyxml2::XMLElement* xmlBricks = file->FirstChildElement("MenuState");

}


sf::Texture& AssetMenager::GetTexture(const std::string& name)
{
	return _mapTexture.at(name);
}

sf::Font& AssetMenager::GetFont(const std::string& name)
{
	return _mapFonts.at(name);
}
