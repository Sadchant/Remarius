#include "Framework.hpp"

// initialisiert die benötigten SDL-Teile und ruft Init_Video auf
bool CFramework::Init ()
{
	// Alle benötigten Systeme der SDL initialisieren
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
		Quit ();
		return (false);
	}

	if (Init_Video ("Remarius Risation Indev 1.6", 1024, 768, false) == false)		// an der Stelle Daten aus Datei einlesen!
	{
		cout << "SDL_Video konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
		Quit ();
		return (false);	
	}

	// Zeiger auf internes Array für Tastaturstatus ermitteln
	pKeystate = SDL_GetKeyboardState(NULL);

	// Alles ging glatt, also true zurückliefern
	return (true);

}

// erzeugt ein SDL_Window mit den übergebenen Werten und einen SDL_Renderer
bool CFramework::Init_Video (char* name, int width, int height, bool bFullscreen)
{
	// sollte bereits ein Fenster vorhanden sein, zerstöre es
	if (sdl_Window != NULL)
	{
		SDL_DestroyWindow(sdl_Window);
	}

	//erzeugt das Fenster im Fullscreen oder Fenstermodus
	if (bFullscreen == true)
	{		
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);
	}
	else
	{		
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	}
	sdl_Renderer = SDL_CreateRenderer(sdl_Window, -1, SDL_RENDERER_ACCELERATED);
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


// beendet das Framework und fährt die SDL herunter
void CFramework::Quit ()
{
	// SDL beenden
	SDL_DestroyWindow(sdl_Window);
	SDL_DestroyRenderer(sdl_Renderer);	
	SDL_Quit ();
}

// updatet Timer und Tastaturstatus
void CFramework::Update ()
{
	// Timer updaten
	g_pTimer->Update ();

	// Tastaturstatus ermitteln
	SDL_PumpEvents ();

} // Update


// schaut, ob die übergebene Tasten-ID in pKeystate drin ist
bool CFramework::KeyDown(Uint8 Key_ID)
{
	// Prüfen, ob Taste gedrückt ist
	return (pKeystate[Key_ID] ? true : false);
	
}

// rendert alles aus dem renderer und reinigt ihn danach
void CFramework::Render()
{
	cout << "Render aufgerufen" << endl;	
	SDL_RenderPresent(sdl_Renderer);
	SDL_RenderClear(sdl_Renderer);
	
}

