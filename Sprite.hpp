#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SDL_image.h"
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
		SDL_Rect	GetRect		(){return m_Rect;};

	protected:
		SDL_Renderer	*m_pRenderer;		// Zeiger auf den Renderer des Frameworks
		SDL_Texture		*m_pTexture;		// Das eigentliche Bild des Sprites
		SDL_Rect		m_Rect;				// Rect des Sprites
		
		int				width;				//die Breite des geladenen Bildes
		int				height;				//die Höhe des geladenen Bildes

	private:
		SDL_Rect		m_FrameRect;		// Ausschnitt für Animationsphase
		int				m_NumFrames;		// Anzahl der Animationsphasen
		int				m_FrameWidth;		// Breite einer Animationsphase
		int				m_FrameHeight;		// Höhe einer Animationsphase
		int				m_NumFramesX;		// Wie viele Anim-Phasen in X-Richtung?

};

#endif
