#include "Bombo.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
 
CBombo::CBombo (CSprite *pSpriteBombo, float fXPos, float fYPos, float *pPlayerXPos, float *pPlayerYPos)										// Bombos initialisieren
{
	m_pSpriteMonster = pSpriteBombo;													// Zeiger auf Sprite kopieren und Koordinaten setzen
	m_fXPos = fXPos;
	m_fYPos = fYPos;
	pPlyx = pPlayerXPos;
	pPlyy = pPlayerYPos;

	m_Rect.x = static_cast<int>(fXPos);														// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = pSpriteBombo->Get_targetRect().w;
	m_Rect.h = pSpriteBombo->Get_targetRect().h;

	m_fDirection = 0.0f;
	m_fCircularMove = 0.0f;
	animPhase = 0;
	m_bIsAlive = true;
	m_bAnimFlipper = 0;
	m_fAnimCounter = 0.0f;
	m_MoveMode = 2;
	m_fCountdown = 0.0f;
	m_fDistance = 0.0f;
	life = 10;
	m_fDamageTimer = 0.0f;
}
void CBombo::Move3 ()
{
	m_fDistance = sqrt((pow(m_fXPos - *pPlyx, 2) + pow(m_fYPos - *pPlyy, 2)));
	m_fDirection = static_cast<float>(1.0f + atan((m_fXPos - *pPlyx)/(m_fYPos - *pPlyy)) / (M_PI * 2));
	if (m_fYPos > *pPlyy)
		m_fDirection += 0.5f;

	m_SpriteDirection = (static_cast<int>(m_fDirection * 8 + 0.5f)) % 8;

	if (m_fDistance <= 100.0f)
	{
		m_MoveMode = 4;
		m_fCircularMove = m_fDirection;
	}

	m_fXPos += static_cast<float>(120.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(120.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
}
void CBombo::Move4 ()
{
	m_fDistance = sqrt((pow(m_fXPos - *pPlyx, 2) + pow(m_fYPos - *pPlyy, 2)));
	m_fDirection = static_cast<float>(1.0f + atan((m_fXPos - *pPlyx)/(m_fYPos - *pPlyy)) / (M_PI * 2));
	if (m_fYPos > *pPlyy)
		m_fDirection += 0.5f;

	m_fCountdown += g_pTimer->GetElapsed();
	m_SpriteDirection = static_cast<int>(m_fCountdown*50)%8;

	if (m_fCountdown >= 2.0f)
		m_MoveMode = 5;
	else if (m_fDistance >= 160.0f)
	{
		m_MoveMode = 3;
		m_fCountdown = 0.0f;
	}
	m_fXPos += static_cast<float>(200.0f * sin((m_fDirection + 0.25f) * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(200.0f * cos((m_fDirection + 0.25f) * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fXPos += static_cast<float>(40.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(40.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
}