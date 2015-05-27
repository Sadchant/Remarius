#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "Singleton.hpp"
#include "Timer.hpp"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "Options.hpp"
//#include "Debugscreen.hpp"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
	public:
		bool  Init		 ();
		bool  Init_Video (string name, int window_width, int window_height, bool bFullscreen);
		void  Quit		 ();
		void  Update	 ();
		void  Render	 ();
		bool  KeyDown	(Uint8 Key_ID);
		bool  Pressed	(SDL_Scancode e);
		SDL_Renderer*	GetRenderer() { return sdl_Renderer; }	
		SDL_Window*	GetWindow() { return sdl_Window; }	

	private:
		SDL_Window*		sdl_Window;						// Fenster, in dem alles stattfindet		
		SDL_Renderer*	sdl_Renderer;					// Renderer, der alles rendert
		SDL_Event		event;
		const Uint8*	pKeystate;						// Array für aktuellen Tastaturstatus
};

#endif
