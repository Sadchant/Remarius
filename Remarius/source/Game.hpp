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

		void	Run     (bool Safegame);
		void	Quit	();
		void	Save    ();
		bool	Load    ();
		int		m_Savestate;

	private:
		void	ProcessEvents	();
		void	Break			();			// Pausemenü
		void	FpsCounter		();			//gibt FPS aus

		
		CSprite			*m_pMenubackground;		// Sprite des Menühintergrunds
		CSprite			*m_pMenubuttons;		// Sprite der Menübuttons
		CStuff			Rectmaster;				// Verwaltung von allem, was ein Rect hat
		bool			m_bGameRun;				// Läuft das Spiel noch?
		bool			m_bEscapeLock;			
		bool			m_bBreakLock;			
		int				m_State;				// Auswahl im Pausemenü
		CText			*m_pTextMenucaption;
		CText			*m_pTextMenutext;
		CText			*m_pTextMenuSave;
		int				Framecounter;
		float			Timecounter;
		char            *m_cSavename;
		bool			m_bBreakLock2;
		bool			m_bEnterLock;
		bool			m_bStateLock;
		int				m_State2;
		TTF_Font*		pFont;

		SDL_Event		event;
		CMusic*			pTrack_1;
};

#endif
