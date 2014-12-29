#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>
#include "Renderlayer.hpp"
#include "SpriteObject.hpp"
#include "Shot.hpp"
#include "Monster.hpp"
#include "Debugscreen.hpp"
#include "Loader.hpp"

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
		void            SetLife			(int Life){life = Life;}
		bool			IsAttack		(){if (m_fAttackTimer > 0) return true; else return false;}
		int				GetLife			(){return life;}
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
		void	OnDeath			(){Reset();}

		CSprite			*m_pSpriteShot;					// Sprite für Laserschüsse
		CSpriteObject	*spriteLife;					// Sprite für Herzleiste
		list<CShot>		m_ShotList;						// Liste der Schüsse
		SDL_Rect		m_AttackRect;					// Rect des Angriffs

		float			lifeAnimphase;				// Ausschnitt aus der Herz-Animtaion
		float			m_fAttackTimer;					// deaktiviert das Attackenrect nach einer Weile
		int				maxLife;						// maximal mögliches Leben (in halben Herzen)
		bool			m_bToolLock;					// Darf ein Hotkey verwendet werden (Schwert, Bogen, Zauber)
		bool			m_bLifeLock;					// Darf ein Herz gefüllt/geleert werden?
		bool			m_bBlock;						// Blockiert die Steuerung?
		int				Map_Width;
        int				Map_Height;
		float			fAnimphase;
 
};

#endif
