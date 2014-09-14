#include "Menu.hpp"
 
CMenu::CMenu()
{
	menPageIndex = 0;
	selectedSave = 1;

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
	{	// Main menu [0]
		CMenuPage mainmenu(m_pMenuBackground, "Hauptmen�", defaultFont);
		CMenuItem playbttn(m_pMenubuttons, "Spielen", defaultFont);
		playbttn.setfunc(bind([](int& mpg){mpg = 1;}, ref(menPageIndex)));
		mainmenu.addItem(playbttn);
		CMenuItem optionsbttn(m_pMenubuttons, "Optionen", defaultFont);
		optionsbttn.setfunc(bind([](int& mpg){mpg = 2; }, ref(menPageIndex)));
		mainmenu.addItem(optionsbttn);
		CMenuItem quitbttn(m_pMenubuttons, "Beenden", defaultFont);
		quitbttn.setfunc(bind([](int& mpg){mpg = 0; }, ref(menPageIndex)));
		mainmenu.addItem(quitbttn);
		menuPages.push_back(mainmenu);
	}
	{
		CMenuPage saveselect(m_pMenuBackground, "Spielstand w�hlen", defaultFont);
		CMenuItem savestatebttn1(m_pMenubuttons, "Spielstand 1", defaultFont);
		savestatebttn1.setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 1; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn1);
		CMenuItem savestatebttn2(m_pMenubuttons, "Spielstand 2", defaultFont);
		savestatebttn2.setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 2; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn2);
		CMenuItem savestatebttn3(m_pMenubuttons, "Spielstand 3", defaultFont);
		savestatebttn3.setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 3; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn3);
	}
}
void CMenu::Run()
{
	cout << "Menu.Run aufgerufen" << endl;

	while (menPageIndex > -1)
	{
		cout << menPageIndex << endl;
		menuPages[0].render();
		g_pFramework->Render();
		cout << menPageIndex << endl;
		Sleep(100);
	}

}
void CMenu::STARTGAME()
{
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