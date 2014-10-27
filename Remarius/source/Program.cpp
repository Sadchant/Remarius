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
	pFont = OpenFont("Data/verdana.ttf", 28);
}

void CProgram::Run()
{	
	CXMLhandler XMLhandler;
	XMLhandler.readoptions();
	if (!g_pOptions->Fullscreen)
		g_pFramework->Init_Video("Remarius Risation Indev 1.6", 1024, 768, true);

	CMenu Menu;
	cout<<"Druecke Enter"<<endl;
	pText->SetFont(pFont);
	
	pText->SetContent ("Drücke Enter!");
	pText->SetColor (255, 255, 255);
	pText->SetPos(10, 10);
	
	//SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);									//ignoriert Systemevents


	while (m_bEnd==false)
	{
		pText->Render();
		g_pFramework->Update();		
		g_pFramework->Render();
		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN))
		{
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
		pText = NULL;
	}

}