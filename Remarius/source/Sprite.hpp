#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Camera.hpp"
#include "Framework.hpp"

class CSprite
{
	public:
		CSprite ();
		~CSprite ();
		void		Load		(const string sFilename);
		void		Load		(const string sFilename, int NumFrames, int FrameWidth, int FrameHeight);
		void		SetPos		(float fXPos, float fYPos);
		void		SetScreenPos(float fXPos, float fYPos, float CameraX, float CameraY);
		void		Render		();
		void		Render		(float fFrameNumber);
		void		Render		(float fFrameNumber, int Direction);
		SDL_Rect	GetRect		(){return Rect;};

	protected:
		SDL_Renderer*	pRenderer;		// Zeiger auf den Renderer des Frameworks
		SDL_Texture*	pTexture;		// Das eigentliche Bild des Sprites
		SDL_Rect		Rect;			// Rect des Sprites		
		int				width;			//die Breite des geladenen Bildes
		int				height;			//die Höhe des geladenen Bildes

	private:
		SDL_Rect		FrameRect;		// Ausschnitt für Animationsphase
		int				NumFrames;		// Anzahl der Animationsphasen
		int				FrameWidth;		// Breite einer Animationsphase
		int				FrameHeight;		// Höhe einer Animationsphase
		int				NumFramesX;		// Wie viele Anim-Phasen in X-Richtung?

};

#endif
