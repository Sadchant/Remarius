#ifndef MENU_HPP
#define MENU_HPP

#include "Programpart.hpp"
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

class CMenu: public CProgrampart
{
public:
	CMenu ();
	void	Quit ();
	TTF_Font* getDefaultFont() { return defaultFont; }
	void	setfunc(function<void()> func){ startGame = func; }
	void	setquitfunc(function<void()> func){ quitProgram = func; }
	void	startUp();
	int			selectedSave;

private:
	void		PlayMenuMusic (int Volume);
	void		generateMenu();
	void        ReloadSprites();
	void		eventprocessing();
	void		rendering();
	
	bool		m_bFullSize;
	bool		m_bMusic;
	bool		m_bSound;
	bool		menuState;
	SDL_Event	event;
	vector<CMenuPage> menuPages;
	TTF_Font*	defaultFont;
	CMusic*		menuMusic;
	int			menPageIndex;
	function<void()> startGame;
	function<void()> quitProgram;
};

#endif