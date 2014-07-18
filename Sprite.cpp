#include "Sprite.hpp"

CSprite::CSprite ()																				// Zeiger auf Screen holen
{
	int IMG_INIT ();
	
	//m_pScreen = g_pFramework->GetScreen ();
	m_pRenderer = g_pFramework->GetRenderer ();
	//m_pTexture = g_pFramework->GetTexture ();
}

CSprite::~CSprite ()																			// Surface des Sprites freigeben
{
	//SDL_FreeSurface (m_pImage);	
}

void CSprite::Load (const string sFilename)														// unanimierten Sprite laden
{
	m_pTexture = IMG_LoadTexture (m_pRenderer, sFilename.c_str () );								// Bilddatei laden
	if (m_pTexture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
	
		g_pFramework->Quit ();															// Framework herunterfahren

		exit (1);																		// Gesamtes Spiel beenden
	}

	SDL_QueryTexture(m_pTexture, NULL, NULL, &width, &height);
	m_Rect.x = 0;
	m_Rect.y = 0;
	m_Rect.w = width;
	m_Rect.h = height;

	cout << sFilename.c_str() << ": " << endl;
	cout << "Breite: " << width << endl;
	cout << "Hoehe: " << height << endl;

	//convertedImage = SDL_DisplayFormatAlpha (m_pImage);
}

void CSprite::Load (const string sFilename, int NumFrames, int FrameWidth, int FrameHeight)		// animierten Sprite laden
{
	Load (sFilename);																	// Bilddatei normal laden

	m_NumFrames   = NumFrames;															// Rect für Animationsphase initialisieren
	m_FrameWidth  = FrameWidth;
	m_FrameHeight = FrameHeight;
	m_FrameRect.w = FrameWidth;
	m_FrameRect.h = FrameHeight;
	m_NumFramesX = width / m_FrameWidth;
	m_Rect.w = m_FrameWidth;
	m_Rect.h = m_FrameHeight;

}

void CSprite::SetPos (float fXPos, float fYPos)											// Position des Sprites festlegen
{
	m_Rect.x = static_cast<int>(fXPos);											// Rect updaten
	m_Rect.y = static_cast<int>(fYPos);
}

void CSprite::SetScreenPos (float fXPos, float fYPos, float CameraX, float CameraY)		//schlechter Programmierstil!		
{	
	m_Rect.x = static_cast<int>(fXPos - CameraX);										
	m_Rect.y = static_cast<int>(fYPos - CameraY);
}



void CSprite::Render ()																	// unanimierten Sprite rendern
{
	//SDL_BlitSurface (convertedImage, NULL, m_pScreen, &m_Rect);						// Sprite rendern
	SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, &m_Rect);
}

void CSprite::Render (float fFrameNumber)										// animiertes Sprite (Ausschnitt) rendern
{
	int Column = static_cast<int>(fFrameNumber)%m_NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row = static_cast<int>(fFrameNumber)/m_NumFramesX;

	m_FrameRect.x = Column * m_FrameWidth;
	m_FrameRect.y = Row * m_FrameHeight;


	//SDL_BlitSurface (convertedImage, &m_FrameRect, m_pScreen, &m_Rect);				// Ausschnitt rendern
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_FrameRect, &m_Rect);
}


void CSprite::Render (float fFrameNumber, int Direction)						// animiertes Sprite mit mehreren Richtungen (Ausschnitt) rendern
{
	int Column = static_cast<int>(fFrameNumber)%m_NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row =  Direction;

	m_FrameRect.x = Column * m_FrameWidth;
	m_FrameRect.y = Row * m_FrameHeight;


	//SDL_BlitSurface (convertedImage, &m_FrameRect, m_pScreen, &m_Rect);				// Ausschnitt rendern
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_FrameRect, &m_Rect);
}