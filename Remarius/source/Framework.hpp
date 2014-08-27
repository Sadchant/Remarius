#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "Singleton.hpp"
#include "Timer.hpp"
#include "SDL_image.h"
#include "SDL_ttf.h"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
	public:
		bool  Init		 ();
		bool  Init_Video (char* name, int window_width, int window_height, bool bFullscreen);
		void  Quit		 ();
		void  Update	 ();
		void  Render	 ();
		bool  KeyDown	(Uint8 Key_ID);
		SDL_Renderer*	GetRenderer() { return sdl_Renderer; }		

	private:
		SDL_Window*		sdl_Window;						// Fenster, in dem alles stattfindet		
		SDL_Renderer*	sdl_Renderer;					// Renderer, der alles rendert
		const Uint8*	pKeystate;						// Array für aktuellen Tastaturstatus
		int				Size;
};

#endif
