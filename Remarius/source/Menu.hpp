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
	void		generateMenu();
	void		STARTGAME(int i, bool b = false);

	bool		m_bFullSize;
	bool		m_bMusic;
	bool		m_bSound;
	bool		menuState;
	SDL_Event	event;
	CSprite		*m_pMenuBackground;
	CSprite		*m_pMenubuttons;
	CSprite		*m_pSoundbuttons;
	CSprite		*m_pSoundschieber;
	CSprite		*m_pSoundbalken;
	vector<CMenuPage> menuPages;
	TTF_Font*	defaultFont;
	int			menPageIndex;
	int			selectedSave;
};

#endif