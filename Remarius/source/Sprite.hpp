#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Camera.hpp"
#include "Framework.hpp"
#include "Renderable.hpp"

class CSprite : public CRenderable
{
	public:
		CSprite ();
		CSprite(const string sFilename);
		CSprite(const string sFilename, int NumFrames, int FrameWidth, int FrameHeight);
		CSprite(const CSprite& other);
		CSprite& operator = (const CSprite& other);
		~CSprite ();
		void		Load		(const string sFilename);
		void		Load		(const string sFilename, int NumFrames, int FrameWidth, int FrameHeight);
		void		SetScreenPos(float fXPos, float fYPos, float CameraX, float CameraY);
		void		Render		(float fFrameNumber);
		void		Render		(float fFrameNumber, int Direction);

	private:
		SDL_Rect		FrameRect;		// Ausschnitt für Animationsphase
		int				NumFrames;		// Anzahl der Animationsphasen
		int				FrameWidth;		// Breite einer Animationsphase
		int				FrameHeight;		// Höhe einer Animationsphase
		int				NumFramesX;		// Wie viele Anim-Phasen in X-Richtung?

};

#endif
