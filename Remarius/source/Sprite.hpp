#ifndef SPRITE_HPP
#define SPRITE_HPP



#include "Renderlayer.hpp"
#include "Loader.hpp"

class CSprite : public CRenderable
{
public:
	CSprite(); // Wird für SpriteObjekt benötigt, dass von Sprite erbt
	CSprite(CTexture* texture, Renderlayers renderlayer, int FrameWidth, int FrameHeight);

	void		Render();
	void		Render		(float frameNumber);
	void		Render		(float frameNumber, int direction);
	void		RenderYourself();


protected:
	CTexture*	texture;
	SDL_Rect source_Rect;			// Ausschnitt aus der Textur
	int numframesX;
	
};

#endif
