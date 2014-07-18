#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "Singleton.hpp"
#include "Timer.hpp"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
	public:
		bool  Init		 ();
		bool  Init_Video (char* name, int window_width, int window_height, bool bFullscreen);
		void  Quit		 ();
		void  Update	 ();
		void  Clear		 ();
		void  Render	 ();
		bool  KeyDown	(Uint8 Key_ID);
		SDL_Window *GetScreen ()	{return sdl_Window;}
		SDL_Renderer *GetRenderer() { return sdl_Renderer; }
		SDL_Texture *GetTexture()	{ return sdl_Texture; }
		

	private:
		SDL_Window		*sdl_Window;							// Fenster, in dem alles stattfindet
		
		SDL_Renderer	*sdl_Renderer;							// Renderer, der alles rendert
		SDL_Texture		*sdl_Texture;							// hier vermutlich nicht benötigt
		//SDL_Surface		*sdl_Surface;						// war früher das Ding, wo draufgerendert wurde
		const Uint8		*m_pKeystate;							// Array für aktuellen Tastaturstatus				

};

#endif
