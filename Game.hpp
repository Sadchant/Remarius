#ifndef GAME_HPP
#define GAME_HPP

#include "Stuff.hpp"
#include "Text.hpp"
#include "Sound.hpp"
#include <fstream>
#include <string>
#include <sstream>

class CGame
{
	public:
		CGame	();

		void	Run     ();
		void	Run     (int i);
		void	Quit	();
		void	Save    ();
		bool	Load    ();
		int		m_Savestate;

	private:
		void	ProcessEvents	();
		void	Break			();			// Pausemen�
		void	FpsCounter		();			//gibt FPS aus

		CSprite			*m_pMenubackground;		// Sprite des Men�hintergrunds
		CSprite			*m_pMenubuttons;		// Sprite der Men�buttons
		CStuff			Rectmaster;				// Verwaltung von allem, was ein Rect hat
		bool			m_bGameRun;				// L�uft das Spiel noch?
		bool			m_bEscapeLock;			
		bool			m_bBreakLock;			
		int				m_State;				// Auswahl im Pausemen�
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

		SDL_Event		event;
		CSound			*m_pTrack_1;
};

#endif
