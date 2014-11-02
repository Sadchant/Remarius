#include "Menu.hpp"
 
CMenu::CMenu()
{
	menPageIndex = 0;
	selectedSave = 1;

	m_bFullSize=false;
	m_bMusic=false;
	m_bSound=false;
	menuState = true;

	m_pMenuBackground = new CSprite("Data/Menuhintergrund.png", MENU_LAYER, 1280, 720);
	m_pMenubuttons = new CSprite("Data/Hauptmenubuttons.png", MENU_LAYER, 356, 66);
	m_pSoundbuttons = new CSprite("Data/Soundbuttons.png", MENU_LAYER, 65, 65);
	m_pSoundschieber = new CSprite("Data/Soundschieber.png", MENU_LAYER, 19, 29);
	m_pSoundbalken = new CSprite("Data/Soundbalken.png", MENU_LAYER, 140, 6);

	defaultFont = OpenFont("Data/verdana.ttf", 19);

	menuMusic = new CMusic;
	menuMusic->Load("Music/Track_1.mp3");

	generateMenu();
}
void CMenu::generateMenu()
{
	menuPages.clear();
	{	// Main menu [0]
		CMenuPage mainmenu(m_pMenuBackground, "Hauptmen�", defaultFont);
		CMenuButton* playbttn = new CMenuButton(m_pMenubuttons, "Spielen", defaultFont);
		playbttn->setfunc(bind([](int& mpg){mpg = 1;}, ref(menPageIndex)));
		mainmenu.addItem(playbttn);
		CMenuButton* optionsbttn = new CMenuButton(m_pMenubuttons, "Optionen", defaultFont);
		optionsbttn->setfunc(bind([](int& mpg){mpg = 2; }, ref(menPageIndex)));
		mainmenu.addItem(optionsbttn);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Beenden", defaultFont);
		quitbttn->setfunc(bind([](bool& ms){ms = false; }, ref(menuState)));
		mainmenu.addItem(quitbttn);
		menuPages.push_back(mainmenu);
	}
	{
		CMenuPage saveselect(m_pMenuBackground, "Spielstand w�hlen", defaultFont);
		CMenuButton* savestatebttn1 = new CMenuButton(m_pMenubuttons, "Spielstand 1", defaultFont);
		savestatebttn1->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 1; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn1);
		CMenuButton* savestatebttn2 = new CMenuButton(m_pMenubuttons, "Spielstand 2", defaultFont);
		savestatebttn2->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 2; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn2);
		CMenuButton* savestatebttn3 = new CMenuButton(m_pMenubuttons, "Spielstand 3", defaultFont);
		savestatebttn3->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 3; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn3);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zur�ck", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 0; }, ref(menPageIndex)));
		saveselect.addItem(quitbttn);
		menuPages.push_back(saveselect);
	}
	{
		CMenuPage options(m_pMenuBackground, "Optionen", defaultFont);
		CMenuButton* fullscrbttn = new CMenuButton(m_pMenubuttons, "Vollbild", defaultFont);
		fullscrbttn->setfunc(bind([](CMenu* menu){	g_pOptions->Fullscreen ^= 1; g_pFramework->Init_Video("Remarius Risation Indev 1.6", 1024, 768, !g_pOptions->Fullscreen); 
													menu->ReloadSprites(); }, this));
		options.addItem(fullscrbttn);
		CMenuSlider* testslider = new CMenuSlider("Lautst�rke Musik", defaultFont, 16);
		testslider->setListener(bind([](CMusic* mus, int vol){mus->SetVolume(vol * 8); g_pOptions->Volume = vol; }, menuMusic, placeholders::_1));
		testslider->setState(g_pOptions->Volume);
		options.addItem(testslider);
		CMenuCheckBox* testbox = new CMenuCheckBox("Musik aktivieren", defaultFont);
		testbox->setListener(bind([](CMusic* mus, bool enable){mus->PauseMusic(enable); g_pOptions->Music = enable; }, menuMusic, placeholders::_1));
		testbox->setState(g_pOptions->Music);
		options.addItem(testbox);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zur�ck", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){CXMLhandler xml; xml.writeoptions(); mpg = 0;  }, ref(menPageIndex)));
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
		CMenuButton* deletebttn = new CMenuButton(m_pMenubuttons, "Spielstand l�schen", defaultFont);
		deletebttn->setfunc([](){});
		loadsave.addItem(deletebttn);
		CMenuButton* quitbttn = new CMenuButton(m_pMenubuttons, "Zur�ck", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 1; }, ref(menPageIndex)));
		loadsave.addItem(quitbttn);
		menuPages.push_back(loadsave);
	}
}
void CMenu::Run()
{
	menuMusic->Play();
	menuMusic->PauseMusic(g_pOptions->Music);
	while (menuState)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.key.repeat == 0)
			menuPages[menPageIndex].processEvent(event.key);
		}
		menuMusic->Play();

		menuPages[menPageIndex].render();
		g_pRenderlayer->Render();
	}

}
void CMenu::STARTGAME(int i, bool b)
{
	CGame Game;
	Game.Run(i, b);
	Game.Quit();
}
void CMenu::ReloadSprites()
{
	m_pMenuBackground->Reload();
	m_pMenubuttons->Reload();
	m_pSoundbuttons->Reload();
	m_pSoundschieber->Reload();
	m_pSoundbalken->Reload();
}
void CMenu::Quit ()
{
	SAFE_DELETE(m_pMenuBackground);
	SAFE_DELETE(m_pMenubuttons);
	SAFE_DELETE(m_pSoundbuttons);
	SAFE_DELETE(m_pSoundschieber);
	SAFE_DELETE(m_pSoundbalken);
	if (menuMusic != NULL) { menuMusic->StopMusic(); SAFE_DELETE(menuMusic); }
	if (defaultFont != NULL) { TTF_CloseFont(defaultFont); defaultFont = NULL; }
	for (unsigned i = 0; i < menuPages.size(); i++)
		menuPages[i].freeItems();
	CMenuSlider::freeSprites();
	CMenuCheckBox::freeSprites();
}
