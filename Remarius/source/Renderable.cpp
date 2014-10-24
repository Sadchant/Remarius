#include "Renderable.hpp"

CRenderable::CRenderable()																				// Zeiger auf Screen holen
{
	pRenderer = NULL;
	pTexture = NULL;
	pRenderer = g_pFramework->GetRenderer();
}

CRenderable::CRenderable(const CRenderable& other)
{
	pRenderer = g_pFramework->GetRenderer();
	pTexture = NULL;
	width = other.width;
	height = other.height;
	Rect = other.Rect;
}


CRenderable::~CRenderable()																			// Surface des Sprites freigeben
{
	SDL_DestroyTexture (pTexture);	
}

CRenderable& CRenderable::operator = (const CRenderable& other)
{
	pRenderer = g_pFramework->GetRenderer();
	pTexture = NULL;
	width = other.width;
	height = other.height;
	Rect = other.Rect;
	return *this;
}


void CRenderable::SetPos(float fXPos, float fYPos)											// Position des Sprites festlegen
{
	Rect.x = static_cast<int>(fXPos);											// Rect updaten
	Rect.y = static_cast<int>(fYPos);
}



void CRenderable::Render()																	// Textur in den Renderer laden
{
	if (SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
		cout << pTexture << endl;
	}
}