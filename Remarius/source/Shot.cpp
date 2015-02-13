#include "Shot.hpp"

CShot::CShot (float fXPos, float fYPos):								// Schuss initialisieren
shotSprite(g_pLoader->getTexture("T_LASER"))
{
	m_fXPos = fXPos;
	m_fYPos = fYPos;

	m_Rect.x = static_cast<int>(fXPos);													// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = shotSprite.Get_targetRect().w;
	m_Rect.h = shotSprite.Get_targetRect().h;

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
		shotSprite.SetPos (m_fXPos - CameraX, m_fYPos - CameraY);
		shotSprite.Render ();
	}
}