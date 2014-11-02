#include "Renderable.hpp"

CRenderable::CRenderable()																				// Zeiger auf Screen holen
{
	Renderer = NULL;
	Texture = NULL;
	Renderer = g_pFramework->GetRenderer();
	Rect.x = 0;
	Rect.y = 0;
}

CRenderable::CRenderable(const CRenderable& other)
{
	Renderer = g_pFramework->GetRenderer();
	Texture = NULL;
	TargetTexture = g_pRenderlayer->GetTexture(other.TextureLayer);
	width = other.width;
	height = other.height;
	Rect = other.Rect;
}


CRenderable::~CRenderable()																// Surface des Sprites freigeben
{
	SDL_DestroyTexture (Texture);	
}

CRenderable& CRenderable::operator = (const CRenderable& other)
{
	Renderer = g_pFramework->GetRenderer();
	TargetTexture = g_pRenderlayer->GetTexture(other.TextureLayer);
	Texture = NULL;
	width = other.width;
	height = other.height;
	Rect = other.Rect;
	return *this;
}

void CRenderable::SetPos(int XPos, int YPos)											// Position des Sprites festlegen
{
	Rect.x = XPos;											// Rect updaten
	Rect.y = YPos;
}

void CRenderable::SetPos(float fXPos, float fYPos)											// Position des Sprites festlegen
{
	Rect.x = static_cast<int>(fXPos);											// Rect updaten
	Rect.y = static_cast<int>(fYPos);
}


void CRenderable::Render()																	// Textur in den Renderer laden
{
	if ((SDL_SetRenderTarget(Renderer, TargetTexture)) < 0)
	{
		cout << "Fehler beim Setzen des Rendertargets: " << SDL_GetError() << endl;
	}
	if (SDL_RenderCopy(Renderer, Texture, NULL, &Rect) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}