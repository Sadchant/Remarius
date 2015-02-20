#ifndef Bombo_HPP
#define Bombo_HPP
 
#include "Sprite.hpp"
#include "Monster.hpp"
 
class CBombo: public CMonster
{
	public:
		CBombo		(float fXPos, float fYPos, float *pPlayerXPos, float *pPlayerYPos);
		int			GetMode		(){return m_MoveMode;}
		float		GetDistance	(){return m_fDistance;}
 
	private:
		float		m_fCountdown;			// Countdown
		float		m_fDistance;			// Abstand zum Spieler
		float		*pPlyx, *pPlyy;			// Zeiger auf die Position des Spielers
		float		m_fCircularMove;		// Variable, die bei der Kreisbwegeung hilft
		void		Move3();				// Spieler-Verfolgung
		void		Move4();				// Countdown-Bewegung
};
 
#endif
