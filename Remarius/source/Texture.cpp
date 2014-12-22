#include "Texture.hpp"

CTexture::CTexture(string filename)
{
	this->filename = filename;
	texture = NULL;
	Load();
}

CTexture::CTexture(const CTexture& other)
{
	filename = other.filename;
	texture = NULL;
	Load();
}

CTexture& CTexture::operator = (const CTexture& other)
{
	filename = other.filename;
	texture = NULL;
	Load();
	return *this;
}

CTexture::~CTexture()																// Surface des Sprites freigeben
{
	SDL_DestroyTexture(texture);
}

SDL_Texture* CTexture::get() {
	if (texture != NULL)
		return texture;
	//TODO: Warnung ausgeben falls nach ungeladener Textur gefragt wird
	Load();
	return texture;
}


void CTexture::unLoad()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}

// holt sich Zeiger auf den Renderer und läd Textur
void CTexture::Load()
{
	texture = IMG_LoadTexture(g_pFramework->GetRenderer(), filename.c_str());
	if (texture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << filename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;
		g_pFramework->Quit();															// Framework herunterfahren
		exit(1);																		// Gesamtes Spiel beenden
	}
}
