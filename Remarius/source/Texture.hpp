#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Framework.hpp"

class CTexture	
{
	friend class CSprite;
public:
	CTexture() {}; //wird benötigt, da CSprite davon erbt ._.
	CTexture(string filename);
	CTexture(const CTexture& other);
	CTexture& operator = (const CTexture& other);
	~CTexture();
	void Load();

protected:
	SDL_Renderer*	sdl_renderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	sdl_texture;		// Das eigentliche Bild des Sprites

private:
	string			filename;


};

#endif
