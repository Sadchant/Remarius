#include "Text.hpp"

CText::CText ()																				
{
	//m_pScreen = g_pFramework->GetScreen ();													// Zeiger auf Screen holen
	m_pRenderer = g_pFramework->GetRenderer();
	m_pTextcontent = NULL;
	m_pFont = NULL;
	if (TTF_Init () == -1)
	{
		cout << "Fehler beim Initialsieren von TTF" << SDL_GetError() << endl;
		SDL_FreeSurface (m_pTextcontent);
		TTF_CloseFont (m_pFont);
		TTF_Quit ();
	}
	TextColor.r = 0;
	TextColor.g = 0;
	TextColor.b = 0;
}

CText::~CText ()																			// Surface des Sprites freigeben
{
	SDL_FreeSurface (m_pTextcontent);
	TTF_CloseFont (m_pFont);
	TTF_Quit ();
	
}

void CText::Open (const string sFilename, int Size)														
{
	m_pFont = TTF_OpenFont (sFilename.c_str (), Size);										// Font in bestimmter Größe laden
	//cout << "Schrift geladen" << endl;
	if (m_pFont == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
	
		g_pFramework->Quit ();															// Framework herunterfahren

		exit (1);																		// Gesamtes Spiel beenden
	}

}

void CText::SetTextColor (int R, int G, int B)											// RGB-Wert der Farbe festlegen
{
	TextColor.r = R;
	TextColor.g = G;
	TextColor.b = B;
	//cout << "Farbe gesetzt" << endl;
}


void CText::SetText (const char *sentence)									 // eigentlicher Text wird übergeben und gerendert
{
	m_pTextcontent = TTF_RenderText_Blended (m_pFont, sentence, TextColor);
	if (m_pTextcontent == NULL)
	{
		cout << "Fehler: Text ist NULL" << endl;
	}
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pTextcontent);
	if (m_pTexture == NULL)
	{
		cout << "Fehler: Textur ist NULL" << endl;
	}
	//cout << "Text gesetzt" << endl;
	int h = 0;
	int w = 0;
	TTF_SizeText(m_pFont, sentence, &w, &h);
	text_height = h;
	text_width = w;
}

void CText::Render (float TextxPos, float TextyPos)																	
{
	m_TextRect.x = static_cast<int>(TextxPos);
	//m_TextRect.y = static_cast<Sint16>(TextyPos);
	m_TextRect.y = static_cast<int>(TextyPos);
	m_TextRect.w = text_width;
	m_TextRect.h = text_height;

	// SDL_BlitSurface (m_pTextcontent, NULL, m_pScreen, &m_TextRect);						// Text wird auf m_pScreen kopiert und auf den Bildsschirm gerendert

	if (SDL_RenderCopy(m_pRenderer, m_pTexture, NULL, &m_TextRect) < 0)						// Text wird in den Renderer kopiert
	{
		cout << "Fehler beim Rendern von Text" << SDL_GetError() <<  endl;
	}
		
								
}