#include "Menu.hpp"
 
CMenu::CMenu()
{
	menPageIndex = 0;

	m_bFullSize=false;
	m_bMusic=false;
	m_bSound=false;

	m_pMenuBackground = new CSprite("Data/Menuhintergrund.png");
	m_pMenubuttons = new CSprite("Data/Hauptmenubuttons.png", 0, 356, 66);													
	m_pSoundbuttons = new CSprite("Data/Soundbuttons.png", 2, 65, 65);														
	m_pSoundschieber = new CSprite("Data/Soundschieber.png", 0, 19, 29);														
	m_pSoundbalken = new CSprite("Data/Soundbalken.png", 0, 140, 6);

	defaultFont = OpenFont("Data/verdana.ttf", 19);

	generateMenu();
}
void CMenu::generateMenu()
{
	menuPages.clear();
	{
		CMenuPage mainmenu(m_pMenuBackground, "Hauptmenü", defaultFont);
		CMenuItem playbttn(m_pMenubuttons, "Spielen", defaultFont);
		mainmenu.addItem(playbttn);
		menuPages.push_back(mainmenu);
	}
}
void CMenu::Run()
{
	cout << "Menu.Run aufgerufen" << endl;

	//menpage->addItem(menitem);
	while (menPageIndex > -1)
	{
		menuPages[menPageIndex].render();
		g_pFramework->Render();
		Sleep(2000);
	}
	CGame Game;
	Game.Run(false);
	Game.Quit();
}
void CMenu::Quit ()
{
	SAFE_DELETE(m_pMenuBackground);
	SAFE_DELETE(m_pMenubuttons);
	SAFE_DELETE(m_pSoundbuttons);
	SAFE_DELETE(m_pSoundschieber);
	SAFE_DELETE(m_pSoundbalken);
	if (defaultFont != NULL) { TTF_CloseFont(defaultFont); defaultFont = NULL; }
}