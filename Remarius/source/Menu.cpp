#include "Menu.hpp"
 
CMenu::CMenu()
{
	menPageIndex = 0;
	selectedSave = 1;

	m_bFullSize=false;
	m_bMusic=false;
	m_bSound=false;
	menuState = true;

	defaultFont = OpenFont("Data/verdana.ttf", 19);

	menuMusic = new CMusic;
	menuMusic->Load("Music/Track_1.mp3");

	generateMenu();
}
void CMenu::generateMenu()
{
	menuPages.clear();
	{	// Main menu [0]
		CMenuPage mainmenu("Hauptmenü", defaultFont);
		CMenuButton* playbttn = new CMenuButton("Spielen", defaultFont);
		playbttn->setfunc(bind([](int& mpg){mpg = 1;}, ref(menPageIndex)));
		mainmenu.addItem(playbttn);
		CMenuButton* optionsbttn = new CMenuButton("Optionen", defaultFont);
		optionsbttn->setfunc(bind([](int& mpg){mpg = 2; }, ref(menPageIndex)));
		mainmenu.addItem(optionsbttn);
		CMenuButton* quitbttn = new CMenuButton("Beenden", defaultFont);
		quitbttn->setfunc(bind([](bool& ms){ms = false; }, ref(menuState)));
		mainmenu.addItem(quitbttn);
		menuPages.push_back(mainmenu);
	}
	{
		CMenuPage saveselect("Spielstand wählen", defaultFont);
		CMenuButton* savestatebttn1 = new CMenuButton("Spielstand 1", defaultFont);
		savestatebttn1->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 1; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn1);
		CMenuButton* savestatebttn2 = new CMenuButton("Spielstand 2", defaultFont);
		savestatebttn2->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 2; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn2);
		CMenuButton* savestatebttn3 = new CMenuButton("Spielstand 3", defaultFont);
		savestatebttn3->setfunc(bind([](int& mpg, int& slcsave){mpg = 3; slcsave = 3; }, ref(menPageIndex), ref(selectedSave)));
		saveselect.addItem(savestatebttn3);
		CMenuButton* quitbttn = new CMenuButton("Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 0; }, ref(menPageIndex)));
		saveselect.addItem(quitbttn);
		menuPages.push_back(saveselect);
	}
	{
		CMenuPage options("Optionen", defaultFont);
		CMenuButton* fullscrbttn = new CMenuButton("Vollbild", defaultFont);
		fullscrbttn->setfunc(bind([](CMenu* menu){	g_pOptions->fullscreen ^= 1; g_pFramework->Init_Video(g_pOptions->window_name,
																											g_pOptions->window_width,
																											g_pOptions->window_height,
																											!g_pOptions->fullscreen);
													menu->ReloadSprites(); }, this));
		options.addItem(fullscrbttn);
		CMenuSlider* testslider = new CMenuSlider("Musik", defaultFont, 16);
		testslider->setListener(bind([](CMusic* mus, int vol){mus->SetVolume(vol * 8); g_pOptions->volume = vol; }, menuMusic, placeholders::_1));
		testslider->setState(g_pOptions->volume);
		options.addItem(testslider);
		CMenuCheckBox* testbox = new CMenuCheckBox("Musik aktivieren", defaultFont);
		testbox->setListener(bind([](CMusic* mus, bool enable){mus->PauseMusic(enable); g_pOptions->music = enable; }, menuMusic, placeholders::_1));
		testbox->setState(g_pOptions->music);
		options.addItem(testbox);
		CMenuButton* quitbttn = new CMenuButton("Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){CXMLhandler xml; xml.writeoptions(); mpg = 0;  }, ref(menPageIndex)));
		options.addItem(quitbttn);
		menuPages.push_back(options);
	}
	{
		CMenuPage loadsave("Spiel starten", defaultFont);
		CMenuButton* loadbttn = new CMenuButton("Spiel fortsetzen", defaultFont);
		loadbttn->setfunc(bind([](int& slcsave){	CGame Game;
								Game.Run(slcsave);
								Game.Quit();	}, ref(selectedSave)));
		loadsave.addItem(loadbttn);
		CMenuButton* deletebttn = new CMenuButton("Spielstand löschen", defaultFont);
		deletebttn->setfunc([](){});
		loadsave.addItem(deletebttn);
		CMenuButton* quitbttn = new CMenuButton("Zurück", defaultFont);
		quitbttn->setfunc(bind([](int& mpg){mpg = 1; }, ref(menPageIndex)));
		loadsave.addItem(quitbttn);
		menuPages.push_back(loadsave);
	}
}
void CMenu::Run()
{
	menuMusic->Play();
	menuMusic->PauseMusic(g_pOptions->music);
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
	g_pLoader->reloadTextures();
}
void CMenu::Quit ()
{
	if (menuMusic != NULL) { menuMusic->StopMusic(); SAFE_DELETE(menuMusic); }
	if (defaultFont != NULL) { TTF_CloseFont(defaultFont); defaultFont = NULL; }
	for (unsigned i = 0; i < menuPages.size(); i++)
		menuPages[i].freeItems();
}
