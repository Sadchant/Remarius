#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Framework.hpp"

class CTexture
{
public:
	CTexture() {}; //wird benötigt, da CSprite davon erbt ._.
	CTexture(string filename);
	CTexture(const CTexture& other);
	CTexture& operator = (const CTexture& other);
	~CTexture();
	void Load();

	SDL_Renderer*	Get_renderer()		{ return renderer; }
	SDL_Texture*	Get_texture()		{ return texture; }

protected:	
	int				numFramesX;		// Anzahl der Animationsphasen in einer Reihe
	SDL_Renderer*	renderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	texture;		// Das eigentliche Bild des Sprites

private:
	string			filename;


};

#endif
