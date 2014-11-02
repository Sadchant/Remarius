#include "Framework.hpp"

// initialisiert die benötigten SDL-Teile und ruft Init_Video auf
bool CFramework::Init ()
{
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)		// Alle benötigten Systeme der SDL initialisieren
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
		Quit ();
		return false;
	}
	if (Init_Video("Remarius Risation Indev 1.6", window_Width, window_Height, false) == false)		// an der Stelle Daten aus Datei einlesen!
	{
		cout << "SDL_Video konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
		Quit ();
		return false;	
	}	
	pKeystate = SDL_GetKeyboardState(NULL);					// Zeiger auf internes Array für Tastaturstatus ermitteln
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(0);																	// mit 0 werden alle Mixer-Systeme initialisiert
	if (TTF_Init() == -1)
	{
		cout << "Fehler beim Initialsieren von TTF" << TTF_GetError() << endl;
		Quit();
		return false;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "Fehler beim Aufruf von Mix_OpenAudio: " << Mix_GetError() << endl;
		Quit();
		return false;
	}	
	return true;
}

// erzeugt ein SDL_Window mit den übergebenen Werten und einen SDL_Renderer
bool CFramework::Init_Video (char* name, int width, int height, bool bFullscreen)
{
	
	if (sdl_Window != NULL)						// sollte bereits ein Fenster vorhanden sein, zerstöre es
	{
		SDL_DestroyWindow(sdl_Window);
	}
	if (sdl_Renderer != NULL)					// sollte bereits ein Fenster vorhanden sein, zerstöre es
	{
		SDL_DestroyRenderer(sdl_Renderer);
	}
	
	if (bFullscreen == true)					//erzeugt das Fenster im Fullscreen oder Fenstermodus
	{		
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);
	}
	else
	{		
		sdl_Window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	}
	sdl_Renderer = SDL_CreateRenderer(sdl_Window, -1, SDL_RENDERER_ACCELERATED);
	
	if ((sdl_Window == NULL) || (sdl_Renderer == NULL))								// Prüfen, ob alles funktioniert hat
	{
		cout << "Fehler beim Erzeugen des Fensters!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
		Quit ();
		return (false);
	}
	return (true);
}

bool CFramework::Pressed(SDL_Scancode e)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN
			&& event.key.repeat == 0
			&& event.key.keysym.scancode == e)
			return true;
	}
	return false;
}

// beendet das Framework und fährt die SDL herunter
void CFramework::Quit ()
{
	SDL_DestroyWindow(sdl_Window);
	SDL_DestroyRenderer(sdl_Renderer);		
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	Mix_CloseAudio();
	SDL_Quit ();
}

// updatet Timer und Tastaturstatus
void CFramework::Update ()
{
	g_pTimer->Update ();			// Timer updaten	
	SDL_PumpEvents ();				// updated die Event-Warteschlange
	SDL_PollEvent(&Event);
	if (Event.type == SDL_QUIT) 
	{
		exit(0);
	}
}


// schaut, ob die übergebene Tasten-ID in pKeystate drin ist, wenn ja, wird true zurückgegeben
bool CFramework::KeyDown(Uint8 Key_ID)
{
	return (pKeystate[Key_ID] ? true : false);	
}

// rendert alles aus dem Renderer und reinigt ihn danach
void CFramework::Render()
{
	if ((SDL_SetRenderTarget(sdl_Renderer, NULL)) < 0)
	{
		cout << "Fehler beim Setzen des Rendertargets im Framework: " << SDL_GetError() << endl;
	}
	SDL_RenderPresent(sdl_Renderer);
	if ((SDL_RenderClear(sdl_Renderer)) < 0)
	{
		cout << "Fehler beim Clearen des Renderers:" << SDL_GetError() << endl;
	}	
}

