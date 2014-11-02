#include "Text.hpp"

CText::CText()
{
	TextureLayer = TEXT_LAYER;
	this->TargetTexture = g_pRenderlayer->GetTexture(TextureLayer);
	Texture = NULL;
	Surface = NULL;
	Font = NULL;
	Color.r = 0;
	Color.g = 0;
	Color.b = 0;
	Color.a = 0;
	
	Size = 0;
}

CText::CText(const CText& other) :
CRenderable(other), Size(0)
{
	Font = other.Font;
	Texture = NULL;
	Surface = NULL;
	Renderer = g_pFramework->GetRenderer();
	Color = other.Color;
	SetContent(string(other.Content));
}

CText& CText::operator = (const CText& other)
{
	CRenderable::operator=(other);
	Font = other.Font;
	Texture = NULL;
	Surface = NULL;
	Renderer = g_pFramework->GetRenderer();
	Color = other.Color;
	SetContent(string(other.Content));
	return *this;
}

CText::~CText()																			// Surface des Sprites freigeben
{
	if (Surface != NULL) SDL_FreeSurface(Surface);
	if (Texture != NULL) SDL_DestroyTexture(Texture);
}

// RGB-Wert der Farbe festlegen
void CText::SetColor (int R, int G, int B)										
{
	Color.r = R;
	Color.g = G;
	Color.b = B;
	createTexture();
}

// Setzt den Alphawert der Farbe
void CText::SetAlpha(int Alpha)
{
	Color.a = Alpha;
	createTexture();
}

// Inhalt festlegen und Breite und Höhe ermitteln
void CText::SetContent (string Content)
{
	int h = 0;
	int w = 0;
	this->Content = Content;
	const char* pContent = Content.c_str();
	if (TTF_SizeText(Font, pContent, &width, &height))
		cout << TTF_GetError() << endl;		//ermittelt Breite und Höhe des Textes abhängig vom Inhalt
	Rect.w = width;
	Rect.h = height;
	createTexture();
}

// Surface erzeugen und in die Textur überführen
void CText::createTexture()
{	
	if (Surface != NULL)
		SDL_FreeSurface(Surface);
	if (Texture != NULL)
		SDL_DestroyTexture(Texture);
	const char* pContent = Content.c_str();
	if (!Content.empty())
	{
		if ((Surface = TTF_RenderText_Blended(Font, pContent, Color)) == NULL)		// Surface wird gefüllt
		{
			cout << "Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((Texture = SDL_CreateTextureFromSurface(Renderer, Surface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
	}	
}