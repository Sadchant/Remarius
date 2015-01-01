#include "Game.hpp"

CGame::CGame ()																									// Game initialisieren
{

//	m_pBaum = NULL;																				// Staubsaugersprite erzeugen
//	m_pBaum = new CSprite;
//	m_pBaum->Load ("Data/Baum_1klein.png", 4, 260, 244);


	m_bGameRun = true;

	pTrack_1 = NULL;
	pTrack_1 = new CMusic;
	pTrack_1->Load ("Music/Track_1.mp3");

	Framecounter = 0;
	Timecounter = 0;

}
void CGame::Quit ()																								// Müll freigeben
{
	Rectmaster.Quit ();

	if (pTrack_1 != NULL)																			// Staubsaugersprite freigeben
	{
		pTrack_1->StopMusic ();
		delete pTrack_1;
		pTrack_1 = NULL;
	}
	
}
void CGame::Run (int save, bool Safegame)         // Hauptschleife des Spiels
{
	int ticks = 0;
	m_Savestate = save;
	if (Safegame)	
		Load();
	while (m_bGameRun == true)													// Wenn es läuft...
	{																			// Events bearbeiten	
		g_pFramework->Update ();												// Framework updaten und Buffer löschen
	
		Rectmaster.Update();
		FpsCounter ();
	
		ProcessEvents ();	
		//pTrack_1->Play ();
		g_pDebugscreen->Render();
		g_pRenderlayer->Render ();
		/*if (ticks == 0)
		{
			while (true){}
			cout << ":)";
		}*/
		ticks += 1;
	}
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
        if (!load != NULL)
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
		std::ofstream save(m_cSavename);
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

	if (g_pFramework->KeyDown (SDL_SCANCODE_ESCAPE))																// Wurde Escape gedrückt?
	{
		g_pDebugscreen->Set("Escape wurde gedrückt");																			// Auswahl auf "Spiel fortsetzen" setzen
		Break ();																			// Pausemenü laufen lassen	
	}

	if (g_pFramework->KeyDown(SDL_SCANCODE_L))																// Wurde Escape gedrückt?
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
