#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "Framework.hpp"

class CRenderable
{
public:
	CRenderable();
	~CRenderable();
	void		SetPos(float fXPos, float fYPos);
	void		Render();

protected:
	SDL_Renderer*	pRenderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	pTexture;		// Das eigentliche Bild des Sprites
	SDL_Rect		Rect;			// Rect des Sprites		
	int				width;			//die Breite des geladenen Bildes
	int				height;			//die Höhe des geladenen Bildes

};

#endif
