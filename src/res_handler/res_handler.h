
#ifndef RES_HANDLER_H_
#define RES_HANDLER_H_


#include <map>



/** Handles global loading of textures */
class ResourceHandler
{
public:
	static ResourceHandler* getInstance();
	
	/** Load all textures */
	void loadAllResources();

	// Retrieve pointer to filename
	sf::Image* getImage(std::string filename);
	
	sf::Sprite* createSprite(std::string filename);


private:
	static ResourceHandler* instance;
	
	void loadTextures();


	std::map<std::string, sf::Image*> spriteMap;

};




#endif
