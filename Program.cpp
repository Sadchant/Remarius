#include "Program.hpp"

CProgram::CProgram ()
{
	m_bEnd=false;	
	
	SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);					//ignoriert alle Maus-Events
	SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
	SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
	SDL_EventState(SDL_MOUSEMOTION, SDL_DISABLE);
	SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_DISABLE);
	SDL_EventState(SDL_MOUSEBUTTONUP, SDL_DISABLE);

	//SDL_WM_SetCaption( "Remarius Risation Indev 1.4", NULL ); //Fenstername

	m_pText = NULL;
	m_pText = new CText;
}

void CProgram::Run()
{	
	cout << "Program: Run gestartet" << endl;
	CMenu Menu;
	cout << "Menu erstellt" << endl;
	SDL_Event event;

	cout<<"Druecke Enter"<<endl;
	m_pText->Open ("Data/verdana.ttf", 28);
	m_pText->SetText ("Drücke Enter!");
	m_pText->SetTextColor (255, 255, 255);
	m_pText->Render (100,100);
	g_pFramework->Render();
	cout << "Text gerendert" << endl;

	SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);									//ignoriert Systemevents


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
	if (m_pText != NULL)																		// Stachelsteinensprite freigeben
	{
		delete (m_pText);
		m_pText = NULL;
	}

}