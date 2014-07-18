#include "Shot.hpp"

CShot::CShot (CSprite *pSpriteShot, float fXPos, float fYPos)								// Schuss initialisieren
{
	m_pSpriteShot = pSpriteShot;														// Parameter übernehmen
	m_fXPos = fXPos;
	m_fYPos = fYPos;

	m_Rect.x = static_cast<int>(fXPos);													// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = pSpriteShot->GetRect().w;
	m_Rect.h = pSpriteShot->GetRect().h;

	m_bIsAlive = true;
}

void CShot::Update ()																			// Schuss bewegen
{
	m_fYPos -= 600.0f * g_pTimer->GetElapsed ();
	m_Rect.y = static_cast<int>(m_fYPos);

	if (m_fYPos < -15.0f)																// Deaktivieren, falls außerhalb des Bildschirms
		m_bIsAlive = false;
}

void CShot::Render (float CameraX, float CameraY)																			// Schuss rendern
{
	if (m_bIsAlive == true)
	{
		m_pSpriteShot->SetScreenPos (m_fXPos, m_fYPos, CameraX, CameraY);
		m_pSpriteShot->Render ();
	}
}