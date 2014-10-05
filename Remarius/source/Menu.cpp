#include "Menu.hpp"
 
CMenu::CMenu()
{
	menPageIndex = 0;
	selectedSave = 1;

	m_bFullSize=false;
	m_bMusic=false;
	m_bSound=false;
	menuState = true;

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
		CMenuPage mainmenu(m_pMenuBackground, "Hauptmenü", defaultFont);
		CMenuButton* playbttn = new CMenuButton(m_pMenubuttons, "Spielen", defaultFont);
		playbttn->setfunc(bind([](int& mpg){mpg = 1;}, ref(menPageIndex)));
		mainmenu.addItem(playbttn);
		CMenuButton* optionsbttn = new CMenuButton(m_pMenubuttons, "Optionen", defaultFont);
		optionsbttn->setfunc(bind([](int& mpg){mpg = 2; }, ref(menPageIndex)));
		mainmenu.addItem(optionsbttn);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Beenden", defaultFont);
		quitbttn->setfunc(bind([](bool& ms){ms = false; }, ref(menuState)));
		mainmenu.addItem(quitbttn);
		CMenuSlider* testslider = new CMenuSlider("test", defaultFont, 20);
		mainmenu.addItem(testslider);
		menuPages.push_back(mainmenu);
	}
	{
		CMenuPage saveselect(m_pMenuBackground, "Spielstand wählen", defaultFont);
		CMenuButton* savestatebttn1 = new CMenuButton(m_pMenubuttons, "Spielstand 1", defaultFont);
		savestatebttn1->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 1; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn1);
		CMenuButton* savestatebttn2 = new CMenuButton(m_pMenubuttons, "Spielstand 2", defaultFont);
		savestatebttn2->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 2; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn2);
		CMenuButton* savestatebttn3 = new CMenuButton(m_pMenubuttons, "Spielstand 3", defaultFont);
		savestatebttn3->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 3; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn3);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 0; }, ref(menPageIndex)));
		saveselect.addItem(quitbttn);
		menuPages.push_back(saveselect);
	}
	{
		CMenuPage options(m_pMenuBackground, "Optionen", defaultFont);
		CMenuButton* fullscrbttn = new CMenuButton(m_pMenubuttons, "Vollbild", defaultFont);
		fullscrbttn->setfunc([](){g_pFramework->Init_Video("Remarius Risation Indev 1.6", 1024, 768, true); });
		options.addItem(fullscrbttn);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 0; }, ref(menPageIndex)));
		options.addItem(quitbttn);
		menuPages.push_back(options);
	}
	{
		CMenuPage loadsave(m_pMenuBackground, "Spiel starten", defaultFont);
		CMenuButton* loadbttn = new CMenuButton(m_pMenubuttons, "Spiel fortsetzen", defaultFont);
		loadbttn->setfunc(bind([](int& slcsave){	CGame Game;
								Game.Run(slcsave);
								Game.Quit();	}, ref(selectedSave)));
		loadsave.addItem(loadbttn);
		CMenuButton* deletebttn = new CMenuButton(m_pMenubuttons, "Spielstand löschen", defaultFont);
		deletebttn->setfunc([](){});
		loadsave.addItem(deletebttn);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 1; }, ref(menPageIndex)));
		loadsave.addItem(quitbttn);
		menuPages.push_back(loadsave);
	}
}
void CMenu::Run()
{
	while (menuState)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.key.repeat == 0)
			menuPages[menPageIndex].processEvent(event.key);
		}
		menuPages[menPageIndex].render();
		g_pFramework->Render();
	}

}
void CMenu::STARTGAME(int i, bool b)
{
	CGame Game;
	Game.Run(i, b);
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
	for (int i = 0; i < menuPages.size(); i++)
		menuPages[i].freeItems();
	CMenuSlider::freeSprites();
}
