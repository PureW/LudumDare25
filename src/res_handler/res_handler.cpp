

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <list>


#include "common.h"
#include "res_handler.h"



#define  RESOURCE_FILE_SPRITES "res/res_graphics"

ResourceHandler* ResourceHandler::instance = NULL;


ResourceHandler* ResourceHandler::getInstance()
{
	if(instance == NULL) {
		instance = new ResourceHandler();
		instance->loadAllResources();
	}
	return instance;	
}


void ResourceHandler::loadAllResources()
{
	loadTextures();
}


void ResourceHandler::loadTextures()
{

	// Load list of sprites
	std::ifstream fin( RESOURCE_FILE_SPRITES,std::ifstream::in);

	//std::string content << file.read();
	std::list<std::string> fileList;

	if (fin.is_open() == false)
		ERROR( "Failed to open " << RESOURCE_FILE_SPRITES );

	while (fin.peek() != EOF)
	{
		int buf = 256;
		char tmp[buf];
		fin.getline(tmp,buf);
		std::string fileToAdd(tmp);
		fileList.push_back(fileToAdd);

		sf::Image* sprite = new sf::Image;
		if (!sprite->LoadFromFile(fileToAdd.c_str()))
			ERROR("Could not load "<<fileToAdd);

		sf::Color cornerColour = sprite->GetPixel(0,0);
		sprite->CreateMaskFromColor(cornerColour);
		spriteMap.insert( std::pair<std::string,sf::Image*>(fileToAdd, sprite) );

	}
}



sf::Image* ResourceHandler::getImage(std::string filename)
{
	std::map<std::string, sf::Image*>::iterator it;
	it = spriteMap.find(filename);

	if (it != spriteMap.end())
		return it->second;
	else

		ERROR("Could not find "<<filename<<" in ResourceHandler");

	return 0;
}


sf::Sprite* ResourceHandler::createSprite(std::string filename)
{
	sf::Image* image = getImage(std::string(filename));
	sf::Sprite* sprite = new sf::Sprite;
	sprite->SetImage(*image);
	//sf::Vector2f spriteSize = sprite->GetSize();
	//sprite->SetCenter(spriteSize.x/2, spriteSize.y/2);
	return sprite;
}


