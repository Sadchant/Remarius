#ifndef Stachelstein_HPP
#define Stachelstein_HPP
 
#include "Sprite.hpp"
#include "Monster.hpp"
 
class CStachelstein: public CMonster
{
	public:
		CStachelstein		(CSprite *pSpriteStachelstein, float fXPos, float fYPos);
 
	private:
		int			m_iDirections;			// Anzahl der Richtungen, in die sich der Stachelstein bewegen darf, muss/sollte durch 4 teilbar sein
		int			m_iAllowed;				// Position auf dem Spielfeld(am Rand/Ecken); Tic-Tac-Toe-Feld durchnummerieren. 1 ist links oben
		int			m_iDChanger;			// Chance auf Richtungsänderung/Tick: 1/m_iDChanger
		void		Orientate();
		void		Move3();
};
 
#endif
