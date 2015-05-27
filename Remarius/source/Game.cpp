#include "Game.hpp"

CGame::CGame():terrain("Map/Map1x1.map", &camera), Rectmaster()																						// Game initialisieren
{
	camera.x = 0;
	camera.y = 0;
	camera.w = g_pOptions->window_width;
	camera.h = g_pOptions->window_height;

	m_bGameRun = true;

	pTrack_1 = NULL;
	pTrack_1 = new CMusic;
	pTrack_1->Load ("Music/Track_1.mp3");

	Framecounter = 0;
	Timecounter = 0;

	Rectmaster.init(&camera, terrain.Get_Width(), terrain.Get_Height());

	openPause = function<void()>([](){});
}
void CGame::Quit ()																								// M�ll freigeben
{
	Rectmaster.Quit ();

	if (pTrack_1 != NULL)																			
	{
		pTrack_1->StopMusic ();
		delete pTrack_1;
		pTrack_1 = NULL;
	}
	
}

void CGame::startUp(int save)
{
	m_Savestate = save;
	Load();
}
void CGame::eventprocessing()
{
	g_pFramework->Update();												// Framework updaten und Buffer l�schen

	Rectmaster.Update();
	FpsCounter();
	ProcessEvents();

	//pTrack_1->Play ();
}
void CGame::rendering()
{
	terrain.Render();
	g_pDebugscreen->Render();
	g_pRenderlayer->Render();
}

bool CGame::Load()
{
        switch (m_Savestate)
        {
        case (1):
                {m_cSavename="Save 1";} break;
        case (2):
                {m_cSavename="Save 2";} break;
        case (3):
                {m_cSavename="Save 3";} break;
        }
 
		std::ifstream load(m_cSavename);
        if (load.is_open())
		{
                int offset1;
                float offset2;
 
                load>>offset1;
                int Life = offset1;
 
                load.ignore();
                load>>offset2;
                float X = offset2;
                load>>offset2;
                float Y = offset2;

				Rectmaster.SetPlayer(Life, X, Y); 
                load.close();
 
                return true;
		}
		else cout << "error opening file";
 
		Rectmaster.SetPlayer(6, 900.0f, 520.0f);
    return false;
}
void CGame::Save()
{
        switch (m_Savestate)
        {
        case (1):
                {m_cSavename="Save 1";} break;
        case (2):
                {m_cSavename="Save 2";} break;
        case (3):
                {m_cSavename="Save 3";} break;
        }
		ofstream save(m_cSavename);
		save << Rectmaster.GetPlayerLife();
		save << "\n";
		save << Rectmaster.GetPlayerX() << " " << Rectmaster.GetPlayerY();
 
		save.close();
 
}

void CGame::FpsCounter ()
{
	Framecounter++;
	Timecounter += g_pTimer->GetElapsed();

	if (Timecounter >= 1.0f)
	{
	g_pDebugscreen->FPS(Framecounter);
	Framecounter = 0;
	Timecounter--;
	}
}

void CGame::ProcessEvents ()																				// Events bearbeiten
{

	if (g_pFramework->KeyDown (SDL_SCANCODE_ESCAPE))																// Wurde Escape gedr�ckt?
	{
		g_pDebugscreen->Set("Escape wurde gedr�ckt");																			// Auswahl auf "Spiel fortsetzen" setzen
		//Break ();																			// Pausemen� laufen lassen	
		openPause();
	}

	if (g_pFramework->KeyDown(SDL_SCANCODE_L))																// Wurde Escape gedr�ckt?
	{
		g_pDebugscreen->Set("Spielstand geladen");
		Load();
	} 
	if (g_pFramework->KeyDown(SDL_SCANCODE_K))
	{
		g_pDebugscreen->Set("Spielstand gespeichert");
		Save();
	} 
}

void CGame::Break()
{

}
