#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Framework.hpp"
#include"Renderable.hpp"

class CTexture	
{
	friend class CSprite;
	friend class CSpriteObject;
public:
	CTexture(string filename, Renderlayers renderlayer, int frameWidth, int frameHeight);
	CTexture(const CTexture& other);
	CTexture& operator = (const CTexture& other);
	~CTexture();
	void Load();

private:
	SDL_Renderer*	sdl_renderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	sdl_texture;		// Das eigentliche Bild des Sprites
	string			filename;
	Renderlayers renderlayer;
	int frameWidth;
	int frameHeight;
};

#endif

