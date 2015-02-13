#ifndef HEXASPIDER_HPP
#define HEXASPIDER_HPP
 
#include "Sprite.hpp"
#include "Monster.hpp"
 
class CSpider: public CMonster
{
	public:
		CSpider		(float fXPos, float fYPos, float *pPlyx, float *pPlyy);
 
	private:
		void		Move3();				// normale Verfolgung
		void		Move4();				// kleines pausieren, dann Sprung

		float		m_fDistance;			// Abstand zum Spieler
		float		*m_pfPlyx;				// Zeiger auf Spieler-Koordinaten
		float		*m_pfPlyy;				//
		float		m_fJumpTimer;
};
 
#endif
