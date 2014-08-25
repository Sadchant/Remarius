#ifndef SHOT_HPP
#define SHOT_HPP

#include "Sprite.hpp"

class CShot
{
	public:
		CShot			(CSprite *pSpriteShot, float fXPos, float fYPos);
		void Update			();
		void Render			(float CameraX, float CameraY);
		bool IsAlive		(){return m_bIsAlive;}
		void SetAlive		(bool bIsAlive){m_bIsAlive = bIsAlive;}
		SDL_Rect GetRect	(){return m_Rect;}

	private:
		CSprite		*m_pSpriteShot;		// Zeiger auf Laser-Sprite
		float		m_fXPos;			// X-Position des Schusses
		float		m_fYPos;			// Y-Position des Schusses
		bool		m_bIsAlive;			// "Lebt" der Schuss noch?
		SDL_Rect	m_Rect;				// Rect des Schusses

};

#endif
