#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP


#include "Framework.hpp"

class CRenderable
{
public:
	CRenderable();
	CRenderable(const CRenderable& other);
	CRenderable& operator = (const CRenderable& other);
	~CRenderable();
	void		SetPos(float fXPos, float fYPos);
	void		Render();
	SDL_Rect	GetRect(){ return Rect; };

protected:
	SDL_Renderer*	pRenderer;		// Zeiger auf den Renderer des Frameworks
	SDL_Texture*	pTexture;		// Das eigentliche Bild des Sprites
	SDL_Rect		Rect;			// Rect des Sprites		
	int				width;			//die Breite des geladenen Bildes
	int				height;			//die Höhe des geladenen Bildes

};

#endif
