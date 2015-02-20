#include "Texture.hpp"

CTexture::CTexture(string filename, Renderlayers renderlayer, int frameWidth, int frameHeight)
{
	this->filename = filename;
	this->renderlayer = renderlayer;
	this->frameWidth = frameWidth;
	this->frameHeight = frameHeight;
	sdl_renderer = NULL;
	sdl_texture = NULL;
	Load();
}

CTexture::CTexture(const CTexture& other)
{
	filename = other.filename;
	renderlayer = other.renderlayer;
	frameWidth = other.frameWidth;
	frameHeight = other.frameHeight;
	sdl_renderer = NULL;
	sdl_texture = NULL;
	Load();
}

CTexture& CTexture::operator = (const CTexture& other)
{
	filename = other.filename;
	renderlayer = other.renderlayer;
	frameWidth = other.frameWidth;
	frameHeight = other.frameHeight;
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

/* Warum sind Load und reLoad so komisch?
   ---> Weil die SDL verbuggt ist!
*/

// löscht eventuell vorhandene Textur und läd sie dann in reLoad()
void CTexture::Load()
{
	if (sdl_texture != NULL) //sollte eine Textur versehentlich erneut geladen werden
	{
		SDL_DestroyTexture(sdl_texture);
		cout << SDL_GetError();
		cout << "Diese Textur gibt es schon! Sie sollte nicht erneut geladen werden! (CTexture::Load)" << endl;		
		sdl_texture = NULL;
	}
	reLoad();
}

// holt sich Zeiger auf den Renderer und läd Textur, sollte nur nach Destroyen des Renderers aufgerufen werden!
void CTexture::reLoad()
{
	sdl_renderer = g_pFramework->GetRenderer();

	/* an dieser Stelle wird nicht die alte Textur destroyed,
	da Texturen schon beim Destroyen des Renderers zerstört werden,
	dabei aber NICHT!! auf NULL gesetzte werden
	*/

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

