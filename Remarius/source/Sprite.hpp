#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Framework.hpp"
#include "Renderable.hpp"
#include "Renderlayer.hpp"

class CSprite : public CRenderable
{
	public:
		CSprite(const string Filename, TextureLayers TextureLayer, int FrameWidth, int FrameHeight);
		CSprite(const CSprite& other);
		CSprite& operator = (const CSprite& other);
		~CSprite ();
		
		void		Reload		();
		CRenderable::Render;
		void		Render		(float fFrameNumber);
		void		Render		(float fFrameNumber, int Direction);

	private:
		void		Load();

		SDL_Rect		ImageRect;		// repräsntiert den Ausschnitt aus dem geladenen Bild für richtige Animationsphase
		int				NumFramesX;		// Anzahl der Animationsphasen in einer Reihe
		string			Filename;

};

#endif
