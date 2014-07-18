#include "Stachelstein.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

CStachelstein::CStachelstein (CSprite *pSpriteStachelstein, float fXPos, float fYPos)										// Stachelsteinen initialisieren
{
	m_pSpriteMonster = pSpriteStachelstein;													// Zeiger auf Sprite kopieren und Koordinaten setzen
	m_fXPos = fXPos;
	m_fYPos = fYPos;

	m_Rect.x = static_cast<int>(fXPos);														// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = pSpriteStachelstein->GetRect().w;
	m_Rect.h = pSpriteStachelstein->GetRect().h;

	m_iDirections = 4096;																	// Integer-Wert, der durch 4 teilbar ist
	m_fDirection = static_cast<float>(rand()%m_iDirections);
	m_fDirection /= m_iDirections;															// Eine der [m_iDirections] Richtungen
	m_iDChanger = 30;																		// Richtungs-Halte-Variable (Je höher, desto geringer ein Wechsel)
	m_fAnimPhase = 0.0f;
	m_bIsAlive = true;
	m_bAnimFlipper = 0;
	m_fAnimCounter = 0.0f;
	m_Life = 5;
	m_MoveMode = 3;
	m_fDamageTimer = 0.0f;
}
void CStachelstein::Orientate()
{
	m_MoveMode = 3;
}
void CStachelstein::Move3 ()
{
	if (m_fYPos >= 530.0f)
	{
		if (m_fXPos >= 730.0f)
			m_iAllowed = 9;
		else if (m_fXPos <= 10.0f)                                      // Wenn außerhalb der erlaubten Zone, dann Bereich ändern
			m_iAllowed = 7;
		else m_iAllowed = 8;
	} else if (m_fYPos <= 10.0f)
		{
			if (m_fXPos >= 730.0f)
				m_iAllowed = 3;
			else if (m_fXPos <= 10.0f)
				m_iAllowed = 1;
			else m_iAllowed = 2;
		} else if (m_fXPos >= 730.0f)
			m_iAllowed = 6;
		else if (m_fXPos <= 10.0f)
			m_iAllowed = 4;
		else m_iAllowed = 5;

	switch (m_iAllowed)
	{
		case 5:{
			if (rand()%m_iDChanger == 0)
			{
				m_fDirection = static_cast<float>(rand()% m_iDirections);									// Freies Lauffeld
				m_fDirection /= m_iDirections;
			}
				} break;
		case 1:{
			m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/4 + 1)));				// Links oben
			m_fDirection /= m_iDirections;
				} break;
		case 2:{
			if (( (m_fDirection > 0.25f) || (m_fDirection < 0.75f) ) || (rand()%m_iDChanger == 0))			// am oberen Rand
				{
					m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/2 + 1)));
					(m_fDirection /= m_iDirections) += 0.75f;
				}
				} break;
		case 3:{
			m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/4 + 1)));				// Rechts oben
			(m_fDirection /= m_iDirections) += 0.75;
				} break;
		case 4:{
			if ( (m_fDirection > 0.5f) || (rand()%m_iDChanger == 0) )
				{
					m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/2 + 1)));		// Linker Rand
					m_fDirection /= m_iDirections;
				}               
				} break;
		case 6:{
			if (( (m_fDirection < 0.5f) && (m_fDirection != 0) ) || (rand()%m_iDChanger == 0))				// Rechter Rand
				{
					m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/2 + 1)));
					(m_fDirection /= m_iDirections) += 0.5f;
				}
				} break;
		case 7:{
				if ( (m_fDirection < 0.25f) || (m_fDirection > 0.5f) )										// Links unten
					{
						m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/4 + 1)));
						(m_fDirection /= m_iDirections) += 0.25f;
					}
				} break;
		case 8:{
			if (( (m_fDirection < 0.25f) || (m_fDirection > 0.75f) ) || (rand()%m_iDChanger == 0) )			// unterer Rand
				{
					m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/2 + 1)));
					(m_fDirection /= m_iDirections) += 0.25f;
				}
				} break;
		case 9:{
			if ( (m_fDirection < 0.5f) || (m_fDirection > 0.75f) )											// unten rechts
				{
					m_fDirection = static_cast<float>(rand() %(static_cast<int>(m_iDirections/4 + 1)));
					(m_fDirection /= m_iDirections) += 0.5f;
				}
				}
	}
	m_fXPos += static_cast<float>(180.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(180.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());

	m_SpriteDirection = static_cast <int> (m_fDirection * 8 + 0.5f);

	if (m_SpriteDirection > 7)
		m_SpriteDirection = 7;
	if (m_SpriteDirection < 0)
		m_SpriteDirection = 0;
}