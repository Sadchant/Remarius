#ifndef SPRITE_HPP
#define SPRITE_HPP



#include "Renderlayer.hpp"
#include "Loader.hpp"

class CSprite : public CRenderable
{
public:
	CSprite(){}; // Wird für SpriteObjekt benötigt, dass von Sprite erbt
	CSprite(CTexture* texture);

	void		Render();
	void		Render		(float frameNumber);
	void		Render		(float frameNumber, int direction);
	void		RenderYourself();

	void SetPos(int x, int y);
	void SetPos(float x, float y);


protected:
	SDL_Renderer* renderer;
	SDL_Rect source_Rect;			// Ausschnitt aus der Textur
	CTexture* texture;
	int numFramesX;
	
};

#endif

