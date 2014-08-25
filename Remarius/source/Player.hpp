#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include "Sprite.hpp"
#include "Shot.hpp"
#include "Monster.hpp"

class CPlayer: public CMonster
{
	public:  

		CPlayer							();
		void			Quit			();
		void			LifeRender		();
		void			Render			(float CameraX, float CameraY);
		void			Update			();
		void			Reset			();
		void			LifeDec			();

		list<CShot>		*GetShotList	(){return &m_ShotList;}
		SDL_Rect		GetAttackRect	(){return m_AttackRect;}
		void            SetLife			(int Life){m_Life = Life;}
		bool			IsAttack		(){if (m_fAttackTimer > 0) return true; else return false;}
		int				GetLife			(){return m_Life;}
		float			*pGetX			(){return &m_fXPos;}
		float			*pGetY			(){return &m_fYPos;}
		int				GetX			(){return static_cast<int>(m_fXPos);}
		int				GetY			(){return static_cast<int>(m_fYPos);}
		void            Set_x			(float X){m_fXPos = X;}
		void            Set_y			(float Y){m_fYPos = Y;}
		void			Set_Map (int Width, int Height) {Map_Width= Width; Map_Height=Height;}
		void			ProcessMoving	(float Speed);

	private:
		void	ProcessMoving	();
		void	ProcessTools	();
		void	CheckPosition	();
		void	OnDeath			(){Reset(); cout << "resetted" << endl;}

		CSprite			*m_pSpriteShot;					// Sprite f�r Lasersch�sse
		CSprite			*m_pSpriteLife;					// Sprite f�r Herzleiste
		list<CShot>		m_ShotList;						// Liste der Sch�sse
		SDL_Rect		m_AttackRect;					// Rect des Angriffs

		float			m_fLifeAnimphase;				// Ausschnitt aus der Herz-Animtaion
		float			m_fAttackTimer;					// deaktiviert das Attackenrect nach einer Weile
		int				m_maxLife;						// maximal m�gliches Leben (in halben Herzen)
		bool			m_bToolLock;					// Darf ein Hotkey verwendet werden (Schwert, Bogen, Zauber)
		bool			m_bLifeLock;					// Darf ein Herz gef�llt/geleert werden?
		bool			m_bBlock;						// Blockiert die Steuerung?
		int				Map_Width;
        int				Map_Height;
 
};

#endif