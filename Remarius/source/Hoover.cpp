#include "Hoover.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
 
CHoover::CHoover() :
hooverSprite(g_pLoader->getTexture("T_SPIDER"))
{
}

void CHoover::Init ()						// Staubsauger Initialisieren
{
	m_fXPos = 360.0f;
	m_fYPos = 10.0f;
 
	m_fDirection = 0.75f;											// Startrichtung nach links
	m_iSpriteDirection = 6;
	m_AnimFlipper = 0;
	m_fAnimCounter = 0;
 
	animPhase = 0;
}
void CHoover::Update ()											// Staubsauger bewegen
{
	m_fDirection += 0.02f * g_pTimer->GetElapsed();					// Richtung erhöhen/resetten
	if (m_fDirection >= 1)
		m_fDirection --;
 
	m_iSpriteDirection = static_cast <int> (m_fDirection * 8 + 0.5f);	// Sprite-Richtung berechnen/resetten
	if (m_iSpriteDirection == 8)
		m_iSpriteDirection = 0;

	m_fXPos += static_cast<float>(20.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());	// Bewegung
	m_fYPos += static_cast<float>(20.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
}
void CHoover::Render (float CameraX, float CameraY)                                                                                                                                 // Stachelsteinen rendern
{

	if (m_AnimFlipper == 0)
		m_fAnimCounter += 15.0f * g_pTimer->GetElapsed ();
	if  (m_AnimFlipper == 1)
		m_fAnimCounter -= 15.0f * g_pTimer->GetElapsed ();

	if ((m_fAnimCounter > 0.0f) && (m_fAnimCounter <=1.0f))
		animPhase = 0;


	if ((m_fAnimCounter <= 0.0f))
		m_AnimFlipper = 0;

	if ((m_fAnimCounter >1.0f) && (m_fAnimCounter <=3.0f))
		animPhase = 1;

	if ((m_fAnimCounter >3.0f) && (m_fAnimCounter <=5.0f))
		animPhase = 2;

	if ((m_fAnimCounter >5.0f) && (m_fAnimCounter <=6.0f))
		animPhase = 3;


	if ((m_fAnimCounter > 6.0f))
	{
		animPhase = 3;
		m_AnimFlipper = 1;
	}


	hooverSprite.SetPos (m_fXPos - CameraX, m_fYPos - CameraY);
	hooverSprite.Render (animPhase, m_iSpriteDirection);

}