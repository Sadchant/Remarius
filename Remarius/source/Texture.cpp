#include "Texture.hpp"

CTexture::CTexture(string filename)
{
	this->filename = filename;
	this->numFramesX = numFramesX;
	renderer = NULL;
	texture = NULL;
	Load();
}

CTexture::CTexture(const CTexture& other)
{
	filename = other.filename;
	numFramesX = other.numFramesX;
	renderer = NULL;
	texture = NULL;
	Load();
}

CTexture& CTexture::operator = (const CTexture& other)
{
	filename = other.filename;
	numFramesX = other.numFramesX;
	renderer = NULL;
	texture = NULL;
	Load();
	return *this;
}

CTexture::~CTexture()																// Surface des Sprites freigeben
{
	SDL_DestroyTexture(texture);
	//delete(texture);
}

// holt sich Zeiger auf den Renderer und läd Textur
void CTexture::Load()
{
	renderer = g_pFramework->GetRenderer();
	texture = IMG_LoadTexture(renderer, filename.c_str());
	if (texture == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << filename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;
		g_pFramework->Quit();															// Framework herunterfahren
		exit(1);																		// Gesamtes Spiel beenden
	}
}
