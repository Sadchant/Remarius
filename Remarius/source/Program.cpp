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
	pText = new CText();
}

void CProgram::Run()
{	
	CMenu Menu;
	SDL_Event event;
	cout<<"Druecke Enter"<<endl;
	pText->OpenFont ("Data/verdana.ttf", 28);
	pText->SetContent ("Drücke Enter!");
	pText->SetColor (255, 255, 255);
	pText->SetPos(10, 10);
	g_pFramework->Update();
	pText->Render ();
	g_pFramework->Render();

	//SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);									//ignoriert Systemevents


	while (m_bEnd==false)
	{
		if (SDL_WaitEvent(&event) == 0)
		{
			cout << "Fehler beim Warten auf Events" << SDL_GetError() << endl;
		}
		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN))
		{
			cout << "Return wurde gedrueckt" << endl;
			SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);								// beachtet Systemevents wieder
			Menu.Run();	
			m_bEnd=true;
		}
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE))
			m_bEnd=true;
	}
	Menu.Quit();
}

void CProgram::Quit()
{
	if (pText != NULL)													
	{
		delete pText;
	}

}