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
	void Load();	// läd normale Texturen, warnt, wenn unnötig erneut geladen wird
	void reLoad();	// sollte nur nach Destroyen des Renderers aufgerufen werden!

private:
	SDL_Renderer*	sdl_renderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	sdl_texture;		// Das eigentliche Bild des Sprites
	string			filename;			// der Dateipfad, wo das Bild liegt
	Renderlayers renderlayer;			// der Layer, auf dem es nachher gerendert wird
	int frameWidth;						// Breite eines Frames (nicht der ganzen Textur)
	int frameHeight;					// Höhe eines Frames (nicht der ganzen Textur)
};

#endif

