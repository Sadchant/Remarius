#include "Texture.hpp"

CTexture::CTexture(string filename)
{
	this->filename = filename;
	sdl_renderer = NULL;
	sdl_texture = NULL;
	Load();
}

CTexture::CTexture(const CTexture& other)
{
	filename = other.filename;
	sdl_renderer = NULL;
	sdl_texture = NULL;
	Load();
}

CTexture& CTexture::operator = (const CTexture& other)
{
	filename = other.filename;
	sdl_renderer = NULL;
	sdl_texture = NULL;
	Load();
	return *this;
}

CTexture::~CTexture()																// Surface des Sprites freigeben
{
	SDL_DestroyTexture(sdl_texture);
	sdl_texture = NULL;
}

// holt sich Zeiger auf den Renderer und läd Textur
void CTexture::Load()
{
	sdl_renderer = g_pFramework->GetRenderer();
	sdl_texture = IMG_LoadTexture(sdl_renderer, filename.c_str());
	if (sdl_texture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << filename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;
		g_pFramework->Quit();															// Framework herunterfahren
		exit(1);																		// Gesamtes Spiel beenden
	}
}
