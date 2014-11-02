#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP


#include "Framework.hpp"
#include "Renderlayer.hpp"

class CRenderable
{
public:
	CRenderable();
	CRenderable(const CRenderable& other);
	CRenderable& operator = (const CRenderable& other);
	~CRenderable();
	void		SetPos(float fXPos, float fYPos);
	void		SetPos(int XPos, int YPos);
	void		Render();
	SDL_Rect	GetRect(){ return Rect; };

protected:
	SDL_Renderer*	Renderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	Texture;		// Das eigentliche Bild des Sprites
	SDL_Texture*	TargetTexture;	// Die ZielTextur aus dem Renderlayer	
	SDL_Rect		Rect;			// Rect des Sprites		
	TextureLayers	TextureLayer;
	int				width;			//die Breite des geladenen Bildes
	int				height;			//die Höhe des geladenen Bildes

};

#endif
