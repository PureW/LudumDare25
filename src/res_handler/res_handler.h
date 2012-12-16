
#ifndef RES_HANDLER_H_
#define RES_HANDLER_H_


#include <map>



/** Handles global loading of textures */
class ResourceHandler
{
public:
	ResourceHandler* getInstance();
	
	/** Load all textures */
	void loadAllResources();

	// Retrieve pointer to filename
	sf::Image* getSprite(std::string filename);


private:
	ResourceHandler* instance;
	
	void loadTextures();


	std::map<std::string, sf::Image*> spriteMap;

};











#endif
