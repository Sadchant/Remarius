#include "Text.hpp"

CText::CText()
{
	pTexture = NULL;
	pSurface = NULL;
	pFont = NULL;
	Color.r = 0;
	Color.g = 0;
	Color.b = 0;
	Color.a = 0;
	
	Size = 0;
}

CText::CText(const CText& other) :
CSprite(other), Size(0)
{
	pFont = other.pFont;
	pTexture = NULL;
	pSurface = NULL;
	pRenderer = g_pFramework->GetRenderer();
	Color = other.Color;
	SetContent(string(other.Content));
}

CText& CText::operator = (const CText& other)
{
	CSprite::operator=(other);
	pFont = other.pFont;
	pTexture = NULL;
	pSurface = NULL;
	pRenderer = g_pFramework->GetRenderer();
	Color = other.Color;
	SetContent(string(other.Content));
	return *this;
}

CText::~CText ()																			// Surface des Sprites freigeben
{
	if (pSurface != NULL) SDL_FreeSurface (pSurface);
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
	if (TTF_SizeText(pFont, pContent, &width, &height))
		cout << TTF_GetError() << endl;		//ermittelt Breite und Höhe des Textes abhängig vom Inhalt
	Rect.w = width;
	Rect.h = height;
	createTexture();
}

// Surface erzeugen und in die Textur überführen
void CText::createTexture()
{	
	if (pSurface != NULL)
		SDL_FreeSurface(pSurface);
	if (pTexture != NULL)
		SDL_DestroyTexture(pTexture);
	const char* pContent = Content.c_str();
	if (!Content.empty())
	{
		if ((pSurface = TTF_RenderText_Blended(pFont, pContent, Color)) == NULL)		// Surface wird gefüllt
		{
			cout << "Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
	}	
}