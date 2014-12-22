#include "Shot.hpp"

CShot::CShot (CSprite *pSpriteShot, float fXPos, float fYPos)								// Schuss initialisieren
{
	m_pSpriteShot = pSpriteShot;														// Parameter �bernehmen
	m_fXPos = fXPos;
	m_fYPos = fYPos;

	m_Rect.x = static_cast<int>(fXPos);													// Rect initialisieren
	m_Rect.y = static_cast<int>(fYPos);
	m_Rect.w = pSpriteShot->Get_targetRect().w;
	m_Rect.h = pSpriteShot->Get_targetRect().h;

	m_bIsAlive = true;
}

void CShot::Update ()																			// Schuss bewegen
{
	m_fYPos -= 600.0f * g_pTimer->GetElapsed ();
	m_Rect.y = static_cast<int>(m_fYPos);

	if (m_fYPos < -15.0f)																// Deaktivieren, falls au�erhalb des Bildschirms
		m_bIsAlive = false;
}

void CShot::Render (float CameraX, float CameraY)																			// Schuss rendern
{
	if (m_bIsAlive == true)
	{
		m_pSpriteShot->SetPos (m_fXPos - CameraX, m_fYPos - CameraY);
		m_pSpriteShot->Render ();
	}
}