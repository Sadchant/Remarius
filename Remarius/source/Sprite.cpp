#include "Sprite.hpp"

CSprite::CSprite(const string Filename, TextureLayers TextureLayer, int FrameWidth, int FrameHeight)
{
	cout << "erstes Sprite wird erzeugt..." << endl;
	this->Filename = Filename;
	this->Renderer = g_pFramework->GetRenderer();
	this->TargetTexture = g_pRenderlayer->GetTexture(TextureLayer);	
	Rect.w = FrameWidth;
	Rect.h = FrameHeight;	
	ImageRect.x = 0;
	ImageRect.y = 0;
	ImageRect.w = FrameWidth;
	ImageRect.h = FrameHeight;

	Load();
	cout << "erstes Sprite fertig erzeugt" << endl;
}

CSprite::CSprite(const CSprite& other)
{
	ImageRect = other.ImageRect;
	NumFramesX = other.NumFramesX;
}

CSprite& CSprite::operator = (const CSprite& other)
{
	ImageRect = other.ImageRect;
	NumFramesX = other.NumFramesX;
	return *this;
}

CSprite::~CSprite ()																		// Surface des Sprites freigeben
{

}

void CSprite::Load ()														// unanimierten Sprite laden
{	
	Texture = IMG_LoadTexture (Renderer, Filename.c_str () );								// Bilddatei laden
	if (Texture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << Filename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;	
		g_pFramework->Quit ();															// Framework herunterfahren
		exit (1);																		// Gesamtes Spiel beenden
	}
	SDL_QueryTexture(Texture, NULL, NULL, &width, &height);

	NumFramesX = width / Rect.w;
}

void CSprite::Reload()
{
	Renderer = g_pFramework->GetRenderer();
	Load();
}


void CSprite::Render (float fFrameNumber)										// animiertes Sprite (Ausschnitt) rendern
{
	if ((SDL_SetRenderTarget(Renderer, TargetTexture)) < 0)
	{
		cout << "Fehler beim Setzen des Rendertargets: " << SDL_GetError() << endl;
	}
	int Column = static_cast<int>(fFrameNumber)%NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row = static_cast<int>(fFrameNumber)/NumFramesX;

	ImageRect.x = Column * Rect.w;
	ImageRect.y = Row * Rect.h;

	if ((SDL_RenderCopy(Renderer, Texture, &ImageRect, &Rect)) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}


void CSprite::Render (float FrameNumber, int Direction)						// animiertes Sprite mit mehreren Richtungen (Ausschnitt) rendern
{
	if ((SDL_SetRenderTarget(Renderer, TargetTexture)) < 0)
	{
		cout << "Fehler beim Setzen des Rendertargets: " << SDL_GetError() << endl;
	}

	int Column = static_cast<int>(FrameNumber)%NumFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row =  Direction;

	ImageRect.x = Column * Rect.w;
	ImageRect.y = Row * Rect.h;

	if (SDL_RenderCopy(Renderer, Texture, &ImageRect, &Rect) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}
