#include "Menu.hpp"
 
CMenu::CMenu()
{
	m_State=1;
	m_State2=1;
	m_State3=1;

    m_bStateLock=false;
    m_bEscapeLock=false;
	m_bMenu1End=false;
	m_bMenu2End=false;
	m_bMenu3End=false;

	m_bFullSize=false;
	m_bMusic=false;
	m_bSound=false;

	m_pMenuBackground = NULL;																			// Hintergrundsprite erzeugen
	m_pMenuBackground = new CSprite;
	m_pMenuBackground->Load ("Data/Menuhintergrund.png");
	m_pMenubuttons = NULL;																				// Menübuttons erzeugen
	m_pMenubuttons = new CSprite;
	m_pMenubuttons->Load ("Data/Hauptmenubuttons.png", 0, 356, 66);
	m_pSoundbuttons = NULL;															
	m_pSoundbuttons = new CSprite;
	m_pSoundbuttons->Load ("Data/Soundbuttons.png", 2, 65, 65);
	m_pSoundschieber = NULL;															
	m_pSoundschieber = new CSprite;
	m_pSoundschieber->Load ("Data/Soundschieber.png", 0, 19, 29);
	m_pSoundbalken = NULL;															
	m_pSoundbalken = new CSprite;
	m_pSoundbalken->Load ("Data/Soundbalken.png", 0, 140, 6);

	m_pTextMenucaption = NULL;
	m_pTextMenucaption = new CText;
	//m_pTextMenucaption->OpenFont ("Data/verdana.ttf", 40);
	defaultFont = OpenFont("Data/verdana.ttf", 19);
	m_pTextMenucaption->SetFont(defaultFont);

	m_pTextMenutext = NULL;
	m_pTextMenutext = new CText;
	m_pTextMenutext->SetFont(defaultFont);

	m_pTextMenutextd = NULL;
	m_pTextMenutextd = new CText;
	m_pTextMenutextd->SetFont(defaultFont);

	cout << "Menüsachen geladen" << endl;

	menpage = new CMenuPage(m_pMenuBackground, "testpage", defaultFont);
	menItem = new CMenuItem(m_pMenubuttons, "testitem", defaultFont);
	menpage->addItem(*menItem);

	generateMenu();
}
void CMenu::generateMenu()
{
	CMenuPage test(m_pMenuBackground, "testpage", defaultFont);
	menuPages.push_back(test);
}
void CMenu::Run()
{
	cout << "Menu.Run aufgerufen" << endl;

	//menpage->addItem(menitem);

	menpage->render();
	g_pFramework->Render();
	Sleep(1000);
	CGame Game;
	Game.Run(false);
	Game.Quit();
}
void CMenu::Quit ()
{
	if (m_pMenuBackground != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pMenuBackground);
		m_pMenuBackground = NULL;
	}

	if (m_pMenubuttons != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pMenubuttons);
		m_pMenubuttons = NULL;
	}

	if (m_pSoundbuttons != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pSoundbuttons);
		m_pSoundbuttons = NULL;
	}
	if (m_pSoundschieber != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pSoundschieber);
		m_pSoundschieber = NULL;
	}
	if (m_pSoundbalken != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pSoundbalken);
		m_pSoundbalken = NULL;
	}

	if (m_pTextMenucaption != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pTextMenucaption);
		m_pTextMenucaption = NULL;
	}

	if (m_pTextMenutext != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pTextMenutext);
		m_pTextMenutext = NULL;
	}

	if (m_pTextMenutext != NULL)																		// Hintergrundsprite freigeben
	{
		delete (m_pTextMenutextd);
		m_pTextMenutextd = NULL;
	}
	if (defaultFont != NULL)
	{
		TTF_CloseFont(defaultFont);
		defaultFont = NULL;
	}
//	delete menpage;
//	delete menItem;
}
