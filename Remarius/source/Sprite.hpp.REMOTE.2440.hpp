#ifndef SPRITE_HPP
#define SPRITE_HPP



#include "Renderlayer.hpp"
#include "Loader.hpp"

class CSprite : public CRenderable
{
public:
	CSprite(CTexture* texture, Renderlayers renderlayer, int FrameWidth, int FrameHeight);

	void		Render();
	void		Render		(float frameNumber);
	void		Render		(float frameNumber, int direction);
	void		RenderYourself();


protected:
	static SDL_Renderer* renderer;
	SDL_Rect source_Rect;			// Ausschnitt aus der Textur
	CTexture* texture;
	int numFramesX;
	
};

#endif
