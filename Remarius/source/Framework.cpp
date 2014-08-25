#include "Framework.hpp"

// Init
//
// Aufgabe: Framework initialisieren
//
bool CFramework::Init ()
{
	// Alle Systeme der SDL initialisieren
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}
	cout << "SDL initialisiert" << endl;
	if (Init_Video ("Remarius Risation Indev 1.6", 1024, 768, false) == false)		// an der Stelle Daten aus Datei einlesen!
	{
		cout << "SDL_Video konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();
		return (false);	
	}
	cout << "Init_Video aufgerufen" << endl;

	// Zeiger auf internes Array für Tastaturstatus ermitteln
	m_pKeystate = SDL_GetKeyboardState(NULL);

	// Alles ging glatt, also true zurückliefern
	return (true);

} // Init

bool CFramework::Init_Video (char* name, int width, int height, bool bFullscreen)
{
	if (sdl_Window != NULL)
	{
		SDL_DestroyWindow(sdl_Window);
	}

	if (bFullscreen == true)
	{
		/*m_pScreen = SDL_SetVideoMode (ScreenWidth, ScreenHeight, ColorDepth,
			SDL_HWSURFACE | SDL_DOUBLEBUF |
			SDL_FULLSCREEN | SDL_ASYNCBLIT);*/

		//erzeugt das Fenster im Fullscreen
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);

	}
	else
	{
		//erzeugt das Fenster 
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		//SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
		/*sdlWindow = SDL_SetVideoMode (ScreenWidth, ScreenHeight, ColorDepth,
			SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_ASYNCBLIT);
			//SDL_OPENGL);*/
		
	}

	//erzeugt den Renderer
	sdl_Renderer = SDL_CreateRenderer(sdl_Window, -1, SDL_RENDERER_ACCELERATED);
	/*sdl_Texture = SDL_CreateTexture(sdl_Renderer,												//wozu allgemeine Textur? Wird vielleicht noch gebraucht
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STATIC,
					window_width, window_height);*/
	//sdl_Texture = SDL_CreateTextureFromSurface(sdl_Renderer, mySurface);



	// Prüfen, ob alles funktioniert hat
	if ((sdl_Window == NULL) || (sdl_Renderer == NULL))
	{
		cout << "Videomodus konnte nicht gesetzt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}
	return (true);
}

// Quit
//
// Aufgabe: Framework (SDL) beenden
//
void CFramework::Quit ()
{
	// SDL beenden
	SDL_DestroyRenderer(sdl_Renderer);
	SDL_DestroyWindow(sdl_Window);
	SDL_Quit ();

} // Quit

// Update
//
// Aufgabe: Timer und Keyboardstatus updaten
//
void CFramework::Update ()
{
	// Timer updaten
	g_pTimer->Update ();

	// Tastaturstatus ermitteln
	SDL_PumpEvents ();

} // Update

// Keydown
//
// Aufgabe: Tastendruck abfragen
//
bool CFramework::KeyDown(Uint8 Key_ID)
{
	// Prüfen, ob Taste gedrückt ist
	return (m_pKeystate[Key_ID] ? true : false);
	
} // KeyDown

// Clear
//
// Aufgabe: Buffer löschen
//
void CFramework::Clear ()
{
	SDL_RenderClear(sdl_Renderer);


} // Clear

// Flip
//
// Aufgabe: Surface umschalten (flippen)
//
void CFramework::Render ()
{
	// Surface umschalten
	//SDL_Flip (m_pScreen);

	//
	SDL_RenderPresent(sdl_Renderer);
	SDL_RenderClear(sdl_Renderer);

} // Flip

