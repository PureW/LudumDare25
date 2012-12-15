
#ifndef RES_HANDLER_H_
#define RES_HANDLER_H_


#include <map>



/** Handles global loading of textures */
class ResourceHandler
{
public:

	/** Load all textures */
	void loadAllResources();




private:

	void loadTextures();


	std::map<char*, sf::Image> spriteMap;

};











#endif
