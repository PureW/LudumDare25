

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <list>


#include "common.h"
#include "res_handler.h"



#define  RESOURCE_FILE_SPRITES "res/res_graphics"


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

		spriteMap.insert( std::pair<std::string,sf::Image*>(fileToAdd, sprite) );

	}
}


sf::Image* ResourceHandler::getSprite(std::string filename)
{
	return spriteMap[filename];
}
