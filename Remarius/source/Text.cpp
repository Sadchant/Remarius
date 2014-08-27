#include "Text.hpp"

CText::CText()
{
	pTexture = NULL;
	pSurface = NULL;
	pFont = NULL;
	Color.r = 0;
	Color.g = 0;
	Color.b = 0;
	pContent = NULL;
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

// RGB-Wert der Farbe festlegen
void CText::SetColor (int R, int G, int B)										
{
	Color.r = R;
	Color.g = G;
	Color.b = B;
}

// Inhalt festlegen und Breite und Höhe ermitteln
void CText::SetContent (char* pContent)
{
	int h = 0;
	int w = 0;
	this->pContent = pContent;	
	TTF_SizeText(pFont, pContent, &width, &height);		//ermittelt Breite und Höhe des Textes abhängig vom Inhalt
	Rect.w = width;
	Rect.h = height;
}

// für den Renderer fertig machen und hineinkopieren
void CText::Render ()																	
{
	pSurface = TTF_RenderText_Blended (pFont, pContent, Color);		// Surface wird gefüllt
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);	// Surface wird in Textur umgewandelt
	SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect);				// Textur wird in der Renderer kopiert		
}