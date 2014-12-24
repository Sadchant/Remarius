#ifndef MONSTER_HPP
#define MONSTER_HPP
 
#include "Sprite.hpp"
 
class CMonster
{
	public:
		//CMonster(CSprite pSpriteMonster, float fXPos, float fYPos);
		virtual	void		Update		();
		virtual	void		Render		(float CameraX, float CameraY);
		virtual void		Render		(int CameraX, int CameraY){Render(static_cast<float>(CameraX), static_cast<float>(CameraY));};

		bool		CanDamage		(){if (m_fDamageTimer <= 0) return true; else return false;}	// Fkt für CheCol / Agieren
		void		DoDamage		(int Damage);													// Terrain
		void		DoDamage		(int X, int Y, int Damage);										// Explosion, Monster, Angriff
		void		DoDamage		(float Direction, int Damage);									// Schuss

		void		SetAlive	(bool bIsAlive) {m_bIsAlive = bIsAlive;}
		SDL_Rect	GetRect		(){return m_Rect;}
		float		GetX		(){return m_fXPos;}
		float		GetY		(){return m_fYPos;}
		bool		IsAlive		(){return m_bIsAlive;}

 
	protected:

		virtual void		Knockback();
		virtual void		Orientate();
		virtual void		Move3();
		virtual void		Move4();
		virtual void		Move5();
		virtual	void		OnDeath(){m_bIsAlive = false;}


		CSprite		*m_pSpriteMonster;		// Zeiger auf Monster-Sprite
		SDL_Rect	m_Rect;					// Rect des Monsters
		float		m_fXPos;				// X-Position des Monsters
		float		m_fYPos;				// Y-Position des Monsters
		bool		m_bIsAlive;				// "Lebt" das Monster noch?

		float		m_fDamageTimer;			// Cooldown für eingehende Angriffe
		int			life;					// Leben
		int			m_MoveMode;				// Bewegungsmodus, 1 ist Standart, 2 ist für Knockback
		float		m_fKnockbackDuration;	// Variable für den Knockback
		float		m_fDirection;			// Richtung des Movements als float, gegen den Uhrzeigersinn, 6 Uhr ist 0.0f bzw 1.0f
		int			m_SpriteDirection;		// Richtung des Sprites, als Int, 6 Uhr ist 0 bzw 8

		float		m_fAnimPhase;			// Akt. Animationsphase des Monsters
		bool		m_bAnimFlipper;			// hochzählen oder runterzählen
		float		m_fAnimCounter;			// Bei bestimmten Wert Animationsphase rendern

};
 
#endif
