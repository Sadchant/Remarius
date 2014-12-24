#include "Hexaspider.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

CSpider::CSpider (CSprite *pSpriteSpider, float fXPos, float fYPos, float *pPlyx, float *pPlyy)							// Hexaspider initialisieren
{
	m_pSpriteMonster = pSpriteSpider;														// Zeiger auf Sprite kopieren und Koordinaten setzen
	m_fXPos = fXPos;
	m_fYPos = fYPos;
	m_pfPlyx = pPlyx;
	m_pfPlyy = pPlyy;

	m_Rect.x = static_cast<int>(fXPos);														// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = pSpriteSpider->Get_targetRect().w;
	m_Rect.h = pSpriteSpider->Get_targetRect().h;

	m_fAnimPhase = 0.0f;
	m_bIsAlive = true;
	m_bAnimFlipper = 0;
	m_fAnimCounter = 0.0f;
	life = 10;
	m_MoveMode = 3;
	m_fDamageTimer = 0.0f;
}
void CSpider::Move3 ()
{
	m_fDirection = static_cast<float>(1.0f + atan((m_fXPos - *m_pfPlyx)/(m_fYPos - *m_pfPlyy)) / (M_PI * 2));
	m_fDistance = sqrt((pow(m_fXPos - *m_pfPlyx, 2) + pow(m_fYPos - *m_pfPlyy, 2)));
	if (m_fYPos > *m_pfPlyy)
		m_fDirection += 0.5f;

	m_fXPos += static_cast<float>(120.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(120.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());

	m_SpriteDirection = (static_cast <int>(m_fDirection * 8 + 0.5f))%8;

	if (m_fDistance <= 200.0f)
	{
		m_MoveMode = 4;
		m_fJumpTimer = 1.5f;
	}
}
void CSpider::Move4 ()
{
	m_fJumpTimer -= g_pTimer->GetElapsed();
	if (m_fJumpTimer <= 0.0f)
	{
		m_MoveMode = 3;
	} else if (m_fJumpTimer <= 0.5f)
	{
	} else if (m_fJumpTimer <= 1.0f)
	{
		m_fXPos += static_cast<float>(350.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
		m_fYPos += static_cast<float>(350.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
	}
}