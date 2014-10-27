#ifndef MENU_HPP
#define MENU_HPP

#include "Game.hpp"
#include "MenuPage.hpp"
#include "MenuButton.hpp"
#include "MenuSlider.hpp"
#include "MenuCheckBox.hpp"
#include "windows.h"
#include "Util.hpp"
#include <functional>
#include "Music.hpp"
#include "XMLhandler.hpp"

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
	void        ReloadSprites();

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
	CMusic*		menuMusic;
	int			menPageIndex;
	int			selectedSave;
};

#endif