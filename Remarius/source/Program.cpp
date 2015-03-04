#include "Program.hpp"

CProgram::CProgram ()
{
	m_bEnd=false;	
	
	/*SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);					//ignoriert alle Maus-Events
	SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
	SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
	SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
	SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_DISABLE);
	SDL_EventState(SDL_MOUSEBUTTONUP, SDL_DISABLE);*/
	pText = NULL;
	pText = new CText(TEXT_LAYER);
	pFont = OpenFont("Data/verdana.ttf", 28);
}

void CProgram::Run()
{
	int state = 0;

	CMenu* Menu = new CMenu;
	part.push_back(Menu);
	CGame* Game = new CGame;
	part.push_back(Game);
	//CPausemenu Pause;
	//part.push_back(Pause);

		// neues Game erstellen
	Menu->setfunc(bind([](CMenu* menu, CGame* game, int& state){state = 1; game->startUp(menu->selectedSave);
			}, Menu, Game, ref(state)));
		// Programm beenden
	Menu->setquitfunc(bind([](bool& end){end = true; }, ref(m_bEnd)));
		// Pausemenu aufrufen
	Game->setfunc(bind([](CProgram* program, int& state){ state = 0;										//ändern nach pausemenu
			}, this, ref(state)));


	pText->SetFont(pFont);
	
	pText->SetContent ("Drücke Enter!");
	pText->SetColor (255, 255, 255);
	pText->SetPos(10, 10);
	
	//SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);									//ignoriert Systemevents


	while (m_bEnd==false)
	{
		pText->Render();
		g_pFramework->Update();		
		g_pRenderlayer->Render();
		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN))
		{
			SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);								// beachtet Systemevents wieder
			m_bEnd=true;
		}
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE))
			m_bEnd=true;
	}
	m_bEnd = false;
	Menu->startUp();

	while (m_bEnd == false)
	{
		part[state]->Tick();
	}

	Game->Quit();
	//Pause.Quit();
	Menu->Quit();
}

void CProgram::Quit()
{
	if (pText != NULL)													
	{
		delete pText;
		pText = NULL;
	}

}