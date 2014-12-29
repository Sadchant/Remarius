#ifndef SPRITE_HPP
#define SPRITE_HPP



#include "Renderlayer.hpp"
#include "Loader.hpp"

class CSprite : public CRenderable
{
public:
	CSprite(CTexture* texture);

	void		Render();
	void		Render		(int frameNumber);
	void		Render		(int frameNumber, int direction);
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

