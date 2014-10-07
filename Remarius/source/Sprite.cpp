#include "Sprite.hpp"

CSprite::CSprite ()																				// Zeiger auf Screen holen
{
	pRenderer = NULL;
	pTexture = NULL;
	pRenderer = g_pFramework->GetRenderer ();
}

CSprite::CSprite(const CSprite& other)
{
	pRenderer = g_pFramework->GetRenderer();
	pTexture = NULL;
	width = other.width;
	height = other.height;
	Rect = other.Rect;
	FrameRect = other.FrameRect;
	NumFrames = other.NumFrames;
	NumFramesX = other.NumFramesX;
	FrameWidth = other.FrameWidth;
	FrameHeight = other.FrameHeight;
}

CSprite::CSprite(string sFilename) : CSprite()
{
	Load(sFilename);
}

CSprite::CSprite(const string sFilename, int NumFrames, int FrameWidth, int FrameHeight) : CSprite()
{
	Load(sFilename, NumFrames, FrameWidth, FrameHeight);
}

CSprite::~CSprite ()																			// Surface des Sprites freigeben
{
	//SDL_FreeSurface (pImage);	
}

CSprite& CSprite::operator = (const CSprite& other)
{
	pRenderer = g_pFramework->GetRenderer();
	pTexture = NULL;
	width = other.width;
	height = other.height;
	Rect = other.Rect;
	FrameRect = other.FrameRect;
	NumFrames = other.NumFrames;
	NumFramesX = other.NumFramesX;
	FrameWidth = other.FrameWidth;
	FrameHeight = other.FrameHeight;
	return *this;
}

void CSprite::Load (const string sFilename)														// unanimierten Sprite laden
{
	pRenderer = g_pFramework->GetRenderer();
	pTexture = IMG_LoadTexture (pRenderer, sFilename.c_str () );								// Bilddatei laden
	if (pTexture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
	
		g_pFramework->Quit ();															// Framework herunterfahren

		exit (1);																		// Gesamtes Spiel beenden
	}

	SDL_QueryTexture(pTexture, NULL, NULL, &width, &height);
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = width;
	Rect.h = height;

	//cout << sFilename.c_str() << ": " << endl;
	//cout << "Breite: " << width << endl;
	//cout << "Hoehe: " << height << endl;

	//convertedImage = SDL_DisplayFormatAlpha (pImage);
}

void CSprite::Load (const string sFilename, int NumFrames, int FrameWidth, int FrameHeight)		// animierten Sprite laden
{
	pRenderer = g_pFramework->GetRenderer();
	Load (sFilename);																	// Bilddatei normal laden

	this->NumFrames   = NumFrames;															// Rect für Animationsphase initialisieren
	this->FrameWidth = FrameWidth;
	this->FrameHeight = FrameHeight;
	this->FrameRect.w = FrameWidth;
	this->FrameRect.h = FrameHeight;
	NumFramesX = width / FrameWidth;
	Rect.w = FrameWidth/2;
	Rect.h = this->FrameHeight/2;

}

void CSprite::SetPos (float fXPos, float fYPos)											// Position des Sprites festlegen
{
	Rect.x = static_cast<int>(fXPos);											// Rect updaten
	Rect.y = static_cast<int>(fYPos);
}

void CSprite::SetScreenPos (float fXPos, float fYPos, float CameraX, float CameraY)		//schlechter Programmierstil!		
{	
	Rect.x = static_cast<int>(fXPos - CameraX);										
	Rect.y = static_cast<int>(fYPos - CameraY);
}



void CSprite::Render ()																	// unanimierten Sprite rendern
{
	if (SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
		cout << pTexture << endl;
	}
}

void CSprite::Render (float fFrameNumber)										// animiertes Sprite (Ausschnitt) rendern
{
	int Column = static_cast<int>(fFrameNumber)%NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row = static_cast<int>(fFrameNumber)/NumFramesX;

	FrameRect.x = Column * FrameWidth;
	FrameRect.y = Row * FrameHeight;


	//SDL_BlitSurface (convertedImage, &FrameRect, pScreen, &Rect);				// Ausschnitt rendern
	SDL_RenderCopy(pRenderer, pTexture, &FrameRect, &Rect);
}


void CSprite::Render (float fFrameNumber, int Direction)						// animiertes Sprite mit mehreren Richtungen (Ausschnitt) rendern
{
	int Column = static_cast<int>(fFrameNumber)%NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row =  Direction;

	FrameRect.x = Column * FrameWidth;
	FrameRect.y = Row * FrameHeight;


	//SDL_BlitSurface (convertedImage, &FrameRect, pScreen, &Rect);				// Ausschnitt rendern
	SDL_RenderCopy(pRenderer, pTexture, &FrameRect, &Rect);
}