#ifndef GAME_HPP
#define GAME_HPP

#include "Programpart.hpp"
#include "Debugscreen.hpp"
#include "Stuff.hpp"
#include "Terrain.hpp"
#include "Text.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include "Util.hpp"
//#include <fstream>
#include <string>
//#include <sstream>
#include <functional>

class CGame: public CProgrampart
{
	public:
		CGame	();
		void	Quit	();
		void	Save    ();
		bool	Load    ();
		int		m_Savestate;
		void	setfunc(function<void()> func){ openPause = func; }
		void	startUp	(int save);

	private:
		void	ProcessEvents	();
		void	Break			();			// Pausemenü
		void	FpsCounter		();			//gibt FPS aus
		void	eventprocessing();
		void	rendering();

		
		CStuff			Rectmaster;				// Verwaltung von allem, was ein Rect hat
		CTerrain		terrain;
		SDL_Rect		camera;
		bool			m_bGameRun;				// Läuft das Spiel noch?
		int				Framecounter;
		float			Timecounter;
		char            *m_cSavename;

		SDL_Event		event;
		CMusic*			pTrack_1;
		function<void()> openPause;
};

#endif
