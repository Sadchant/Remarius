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

CText::~CText ()																			// Surface des Sprites freigeben
{
	SDL_FreeSurface (pSurface);
	TTF_CloseFont (pFont);
}

// Schriftart in der richtigen Größe laden
void CText::OpenFont (const string sFilename, int Size)														
{
	pFont = TTF_OpenFont (sFilename.c_str (), Size);										
	if (pFont == NULL)																	
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << TTF_GetError () << endl;	
		g_pFramework->Quit ();															
		exit (1);																		
	}
}

// Schriftart in der richtigen Größe laden und festlegen ob es fett sein soll
void CText::OpenFont(const string sFilename, int Size, bool bold, bool italic)
{
	pFont = TTF_OpenFont(sFilename.c_str(), Size);
	if (pFont == NULL)
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << TTF_GetError() << endl;
		g_pFramework->Quit();
		exit(1);
	}
	if (bold)
	{
		TTF_SetFontStyle(pFont, TTF_STYLE_BOLD);
	}
	if (italic)
	{
		TTF_SetFontStyle(pFont, TTF_STYLE_ITALIC);
	}
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
	TTF_SizeText(pFont, pContent, &width, &height);		//ermittelt Breite und Höhe des Textes abhängig vom Inhalt
	Rect.w = width;
	Rect.h = height;
	createTexture();
}

// Surface erzeugen und in die Textur überführen
void CText::createTexture()
{	
	const char* pContent = Content.c_str();
	if (pContent != NULL)
	{
		if (!(pSurface = TTF_RenderText_Blended(pFont, pContent, Color)))		// Surface wird gefüllt
		{
			cout << "Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
	}	
}