#include "Explosion.hpp"
 
CExplosion::CExplosion (CSprite *pSpriteExplosion, int XPos, int YPos)										// Explosion Initialisieren
{
	m_pSpriteExplosion = pSpriteExplosion;															// Sprite übernehmen, Startposition setzen
	m_XPos = XPos;
	m_YPos = YPos;

	m_Rect.x = XPos;															// Rect erzeugen
	m_Rect.y = YPos;
	m_Rect.w = pSpriteExplosion->Get_targetRect().w;
	m_Rect.h = pSpriteExplosion->Get_targetRect().h;

	m_fDuration = 0.0f;
	m_StateExplosion = 0;
	m_bIsAlive = true;
	m_bActive = true;
 }
void CExplosion::Render (float CameraX, float CameraY)														// Explosion rendern
{
	m_fDuration += g_pTimer->GetElapsed();


	if (m_fDuration >= 0.05f)
	{
		m_fDuration = 0.0f;
		m_StateExplosion++;
	}

	if (m_StateExplosion < 10)
	{
		m_pSpriteExplosion->SetPos (m_XPos - CameraX, m_YPos - CameraY);
		m_pSpriteExplosion->Render (static_cast<float>(m_StateExplosion));
		if (m_StateExplosion > 3) m_bActive = false;
	} else m_bIsAlive = false;
}