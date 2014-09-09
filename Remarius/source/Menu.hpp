#ifndef MENU_HPP
#define MENU_HPP

#include "Game.hpp"
#include "MenuPage.hpp"
#include "windows.h"
#include "Util.hpp"

class CMenu
{
public:
	CMenu ();
	void Run ();
	void Quit ();
	TTF_Font* getDefaultFont() { return defaultFont; }

private:
	void		PlayMenuMusic (int Volume);
	int			m_State;
	int			m_State2;
	int			m_State3;
	int			m_State4;
	bool		m_bMenu1End;
	bool		m_bMenu2End;
	bool		m_bMenu3End;
	bool		m_bMenu4End;
	bool		m_bStateLock;
	bool		m_bEnterLock;
	bool		m_bEscapeLock;
	bool		m_bFullSize;
	bool		m_bMusic;
	bool		m_bSound;
	CSprite		*m_pBackground;
	CText		*m_pText;
	SDL_Event	event;
	CSprite		*m_pMenuBackground;
	CSprite		*m_pMenubuttons;
	CSprite		*m_pSoundbuttons;
	CSprite		*m_pSoundschieber;
	CSprite		*m_pSoundbalken;
	CText		*m_pTextMenutext;
	CText		*m_pTextMenucaption;
	CText		*m_pTextMenutextd;
	vector<CMenuPage> menuPages;
	CMenuPage* menpage;
	CMenuItem* menItem;
	TTF_Font* defaultFont;

	void		Options ();
	void		Play ();
	void		generateMenu();
};

#endif