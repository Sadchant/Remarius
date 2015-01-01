#ifndef GAME_HPP
#define GAME_HPP

#include "Debugscreen.hpp"
#include "Stuff.hpp"
#include "Text.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include "Util.hpp"
#include <fstream>
#include <string>
#include <sstream>

class CGame
{
	public:
		CGame	();

		void	Run     (int save, bool savegame = false);
		void	Quit	();
		void	Save    ();
		bool	Load    ();
		int		m_Savestate;

	private:
		void	ProcessEvents	();
		void	Break			();			// Pausemenü
		void	FpsCounter		();			//gibt FPS aus

		
		CStuff			Rectmaster;				// Verwaltung von allem, was ein Rect hat
		bool			m_bGameRun;				// Läuft das Spiel noch?
		int				Framecounter;
		float			Timecounter;
		char            *m_cSavename;

		SDL_Event		event;
		CMusic*			pTrack_1;
};

#endif
