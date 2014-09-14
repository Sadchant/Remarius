#ifndef MENU_HPP
#define MENU_HPP

#include "Game.hpp"
#include "MenuPage.hpp"
#include "windows.h"
#include "Util.hpp"
#include <functional>

class CMenu
{
public:
	CMenu ();
	void Run ();
	void Quit ();
	TTF_Font* getDefaultFont() { return defaultFont; }

private:
	void		PlayMenuMusic (int Volume);
	bool		m_bStateLock;
	bool		m_bEnterLock;
	bool		m_bEscapeLock;
	bool		m_bFullSize;
	bool		m_bMusic;
	bool		m_bSound;
	SDL_Event	event;
	CSprite		*m_pMenuBackground;
	CSprite		*m_pMenubuttons;
	CSprite		*m_pSoundbuttons;
	CSprite		*m_pSoundschieber;
	CSprite		*m_pSoundbalken;
	vector<CMenuPage> menuPages;
	TTF_Font*	defaultFont;
	int			menPageIndex;

	void		generateMenu();
	void		STARTGAME();

	void		TO_MAINMENU() { menPageIndex = 1; }
	void		TO_SAVESELECT() { menPageIndex = 2; }
	void		TO_OPTIONSMENU() { menPageIndex = 3; }

};

#endif