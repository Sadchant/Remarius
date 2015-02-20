#ifndef SPRITE_HPP
#define SPRITE_HPP



#include "Renderlayer.hpp"
#include "Loader.hpp"

class CSprite : public CRenderable, public CTexture
{
public:
	CSprite(); // Wird für SpriteObjekt benötigt, dass von Sprite erbt
	CSprite(CTexture* temp_texture, Renderlayers renderlayer, int FrameWidth, int FrameHeight);

	void		Render();
	void		Render		(float frameNumber);
	void		Render		(float frameNumber, int direction);
	void		RenderYourself();


protected:
	SDL_Rect source_Rect;			// Ausschnitt aus der Textur
	int numframesX;
	
};

#endif
