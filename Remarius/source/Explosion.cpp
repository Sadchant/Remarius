#include "Explosion.hpp"
 
CExplosion::CExplosion (int XPos, int YPos):										// Explosion Initialisieren
explosionSprite(g_pLoader->getTexture("T_EXPLOSION"))
{
	m_XPos = XPos;
	m_YPos = YPos;

	m_Rect.x = XPos;															// Rect erzeugen
	m_Rect.y = YPos;
	m_Rect.w = explosionSprite.Get_targetRect().w;
	m_Rect.h = explosionSprite.Get_targetRect().h;

	m_fDuration = 0.0f;
	m_StateExplosion = 0;
	m_bIsAlive = true;
	m_bActive = true;
 }
void CExplosion::Render (float CameraX, float CameraY)														// Explosion rendern
{
	m_fDuration += g_pTimer->GetElapsed();


	//if (m_fDuration >= 0.05f)
	if (m_fDuration >= 0.08f)
	{
		m_fDuration = 0.0f;
		m_StateExplosion++;
	}

	if (m_StateExplosion < 10)
	{
		explosionSprite.SetPos (m_XPos - CameraX, m_YPos - CameraY);
		explosionSprite.Render (m_StateExplosion);
		if (m_StateExplosion > 3) m_bActive = false;
	} else m_bIsAlive = false;
}