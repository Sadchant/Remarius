#include "Game.hpp"

CGame::CGame ()																									// Game initialisieren
{
	pFont = OpenFont("Data/verdana.ttf", 19);

	m_pMenubackground = NULL;																				// Pausemenühintergrund erzeugen
	m_pMenubackground = new CSprite(g_pLoader->getTexture("T_PAUSEMENUHINTERGRUND"));

	m_pMenubuttons = NULL;																				// Staubsaugersprite erzeugen
	m_pMenubuttons = new CSprite(g_pLoader->getTexture("T_MENUBUTTONS"));

//	m_pBaum = NULL;																				// Staubsaugersprite erzeugen
//	m_pBaum = new CSprite;
//	m_pBaum->Load ("Data/Baum_1klein.png", 4, 260, 244);


	m_bGameRun = true;

	m_pTextMenucaption = NULL;
	m_pTextMenucaption = new CText(TEXT_LAYER);
	m_pTextMenucaption->SetFont (pFont);

	m_pTextMenutext = NULL;
	m_pTextMenutext = new CText(TEXT_LAYER);
	m_pTextMenutext->SetFont (pFont);

	m_pTextMenuSave = NULL;
	m_pTextMenuSave = new CText(TEXT_LAYER);
	m_pTextMenuSave->SetFont (pFont);

	pTrack_1 = NULL;
	pTrack_1 = new CMusic;
	pTrack_1->Load ("Music/Track_1.mp3");

	Framecounter = 0;
	Timecounter = 0;

}
void CGame::Quit ()																								// Müll freigeben
{
	Rectmaster.Quit ();

	if (m_pMenubackground != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pMenubackground);
		m_pMenubackground = NULL;
	}

	if (m_pMenubuttons != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pMenubuttons);
		m_pMenubuttons = NULL;
	}

	if (m_pTextMenucaption != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pTextMenucaption);
		m_pTextMenucaption = NULL;
	}

	if (m_pTextMenutext != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pTextMenutext);
		m_pTextMenutext = NULL;
	}
	if (m_pTextMenuSave != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pTextMenuSave);
		m_pTextMenuSave = NULL;
	}
	if (pTrack_1 != NULL)																			// Staubsaugersprite freigeben
	{
		pTrack_1->StopMusic ();
		delete pTrack_1;
		pTrack_1 = NULL;
	}
	TTF_CloseFont(pFont);
	
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
																				// Stachelsteinen rendern
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
		g_pDebugscreen->Set("Escape wurde gedrückt");
		m_State=1;																			// Auswahl auf "Spiel fortsetzen" setzen
		m_bBreakLock=false;
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
	m_bEscapeLock=true;
	while (m_bBreakLock==false)	
	{
		m_pMenubackground->SetPos (134, 99);
		m_pMenubackground->Render (0);
		m_pTextMenucaption->SetColor (230, 230, 0);
		m_pTextMenucaption->SetContent ("Pause");
		m_pTextMenucaption->SetPos(((755 - m_pTextMenucaption->Get_length()) / 2 + 134), 200);
		m_pTextMenucaption->Render();

		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
			m_bEnterLock=false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
			m_bStateLock=false;																			
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE)==false)
			m_bEscapeLock=false;

			
		switch (m_State)
		{
		case (1):
			{
				m_pMenubuttons->SetPos (361, 274);
				m_pMenubuttons->Render (0, 1);
				m_pTextMenutext->SetColor (255, 255, 255);
				m_pTextMenutext->SetContent ("Fortsetzen");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 274));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Speichern");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 354));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Beenden");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 434));
				m_pTextMenutext->Render();

			} break;

		case (2):
			{
				m_pMenubuttons->SetPos (361, 274);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Fortsetzen");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
					static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 274));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 1);
				m_pTextMenutext->SetColor (255, 255, 255);
				m_pTextMenutext->SetContent ("Speichern");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
					static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 354));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Beenden");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 434));
				m_pTextMenutext->Render();

			} break;
		case (3):
			{
				m_pMenubuttons->SetPos (361, 274);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Fortsetzen");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 274));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetColor (180, 180, 180);
				m_pTextMenutext->SetContent ("Speichern");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 354));
				m_pTextMenutext->Render();

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 1);
				m_pTextMenutext->SetColor (255, 255, 255);
				m_pTextMenutext->SetContent ("Beenden");
				m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 434));
				m_pTextMenutext->Render();
			} break;
				
		}

		g_pFramework->Render ();

		SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);	
		SDL_WaitEvent(&event);

		switch (m_State)
		{
			case (1):
			{
				if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN))
				{
					if (m_bEnterLock == false)
					{
						m_bBreakLock = true;
					}
				}
				if (g_pFramework->KeyDown(SDL_SCANCODE_DOWN))
				{
					if (m_bStateLock == false)
					{
						m_State = 2;
						m_bStateLock = true;
					}
				}
				if (g_pFramework->KeyDown(SDL_SCANCODE_UP))
				{
					if (m_bStateLock == false)
					{
						m_State = 3;
						m_bStateLock = true;
					}
				}
				if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE))
				{
					if (m_bEscapeLock == false)
					{
						m_bBreakLock = true;
					}
				}
			}break;
		
	

		case (2):
		{
			switch (event.key.keysym.sym)
			{
				case (SDL_SCANCODE_RETURN):
				{
					if (m_bEnterLock==false)
					{
						m_bEnterLock=true;
						m_State2=1;
						m_bBreakLock2=false;
						m_pMenubackground->SetPos (134, 99);
						m_pMenubackground->Render (0);
						m_pTextMenuSave->SetColor (230, 230, 0);
						m_pTextMenuSave->SetContent ("Soll wirklich gespeichert werden?");
						m_pTextMenucaption->SetPos(((755 - m_pTextMenuSave->Get_length())/2+ 134), 240);
						m_pTextMenuSave->Render();

						while (	m_bBreakLock2==false)
						{
							if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
								m_bEnterLock=false;
							if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
								m_bStateLock=false;

							switch (m_State2)
							{
							case(1):
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetColor (255, 255, 255);
								m_pTextMenutext->SetContent ("Ja");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 304));
								m_pTextMenutext->Render();

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetColor (180, 180, 180);
								m_pTextMenutext->SetContent ("Nein");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 394));
								m_pTextMenutext->Render();
								break;

							case(2):
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetColor (180, 180, 180);
								m_pTextMenutext->SetContent ("Ja");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 304));
								m_pTextMenutext->Render();

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetColor (255, 255, 255);
								m_pTextMenutext->SetContent ("Nein");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 394));
								m_pTextMenutext->Render();
								break;
							}
							g_pFramework->Render ();

							SDL_WaitEvent(&event);
							switch (m_State2)
							{
							case (1):
							{
								switch (event.key.keysym.sym)
								{
								case (SDL_SCANCODE_RETURN):
									if (m_bEnterLock==false)
									{
										Save ();
										m_bBreakLock2=true;
										m_bEnterLock=true;
									}
								break;
								case (SDL_SCANCODE_DOWN):
									if (m_bStateLock==false)
									{
										m_State2=2;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_UP):
									if (m_bStateLock==false)
									{
										m_State2=2;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_ESCAPE):
									if (m_bEscapeLock==false)
									{
										m_bBreakLock2=true;
										m_bEscapeLock=true;
									}
								break;
								}
							} break;
							case (2):
							{
								switch (event.key.keysym.sym)
								{
								case (SDL_SCANCODE_RETURN):
									if (m_bEnterLock==false)
									{
										m_bBreakLock2=true;
										m_bEnterLock=true;
									}
								break;
								case (SDL_SCANCODE_DOWN):
									if (m_bStateLock==false)
									{
										m_State2=1;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_UP):
									if (m_bStateLock==false)
									{
										m_State2=1;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_ESCAPE):
									if (m_bEscapeLock==false)
									{
										m_bBreakLock2=true;
										m_bEscapeLock=true;
									}
								break;
								}
							} break;
							}
						}
					}
				} break;
				case (SDL_SCANCODE_DOWN):
				{
				if (m_bStateLock==false)
				{
					m_State=3;
					m_bStateLock=true;
				}
				} break;

				case (SDL_SCANCODE_UP):
				{
				if (m_bStateLock==false)
				{
					m_State=1;
					m_bStateLock=true;
				}
				} break;

				case (SDL_SCANCODE_ESCAPE):
				{
				if (m_bEscapeLock==false)															
					m_bBreakLock=true;
				} break;
			}
		} break;

		case (3):
		{
			switch (event.key.keysym.sym)
			{
			case (SDL_SCANCODE_RETURN):
				if (m_bEnterLock==false)
					{
						m_bEnterLock=true;
						m_State2=1;
						m_bBreakLock2=false;
						m_pMenubackground->SetPos (134, 99);
						m_pMenubackground->Render (0);
						m_pTextMenuSave->SetColor (230, 230, 0);
						m_pTextMenuSave->SetContent ("Soll wirklich beendet werden?");
						m_pTextMenucaption->SetPos(((755 - m_pTextMenuSave->Get_length())/2+ 134), 240);
						m_pTextMenuSave->Render();

						while (	m_bBreakLock2==false)
						{
							if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
								m_bEnterLock=false;
							if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
								m_bStateLock=false;

							switch (m_State2)
							{
							case(1):
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetColor (255, 255, 255);
								m_pTextMenutext->SetContent ("Ja");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->Get_height())/2 + 304));
								m_pTextMenutext->Render();

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetColor (180, 180, 180);
								m_pTextMenutext->SetContent ("Nein");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
									static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
								m_pTextMenutext->Render();
								break;

							case(2):
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetColor (180, 180, 180);
								m_pTextMenutext->SetContent ("Ja");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
									static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 304));
								m_pTextMenutext->Render();

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetColor (255, 255, 255);
								m_pTextMenutext->SetContent ("Nein");
								m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length())/2+ 361),
									static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
								m_pTextMenutext->Render();
								break;
							}
							g_pFramework->Render ();

							SDL_WaitEvent(&event);
							switch (m_State2)
							{
							case (1):
							{
								switch (event.key.keysym.sym)
								{
								case (SDL_SCANCODE_RETURN):
									if (m_bEnterLock==false)
									{
										SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
										m_bBreakLock=true;
										m_bGameRun=false;
										m_bBreakLock2=true;
										m_bEnterLock=true;
										pTrack_1->PauseMusic ();
									}
								break;
								case (SDL_SCANCODE_DOWN):
									if (m_bStateLock==false)
									{
										m_State2=2;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_UP):
									if (m_bStateLock==false)
									{
										m_State2=2;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_ESCAPE):
									if (m_bEscapeLock==false)
									{
										m_bBreakLock2=true;
										m_bEscapeLock=true;
									}
								break;
								}
							} break;
							case (2):
							{
								switch (event.key.keysym.sym)
								{
								case (SDL_SCANCODE_RETURN):
									if (m_bEnterLock==false)
									{
										m_bBreakLock2=true;
										m_bEnterLock=true;
									}
								break;
								case (SDL_SCANCODE_DOWN):
									if (m_bStateLock==false)
									{
										m_State2=1;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_UP):
									if (m_bStateLock==false)
									{
										m_State2=1;
										m_bStateLock=true;
									}
								break;
								case (SDL_SCANCODE_ESCAPE):
									if (m_bEscapeLock==false)
									{
										m_bBreakLock2=true;
										m_bEscapeLock=true;
									}
								break;
								}
							} break;
							}
						}
					}
			break;
			case (SDL_SCANCODE_DOWN):
			{
				if (m_bStateLock==false)
				{
					m_State=1;
					m_bStateLock=true;
				}
			} break;

			case (SDL_SCANCODE_UP):
			{
				if (m_bStateLock==false)
				{
					m_State=2;
					m_bStateLock=true;
				}
			} break;

			case (SDL_SCANCODE_ESCAPE):	
			{
				if (m_bEscapeLock==false)															
					m_bBreakLock=true;
			} break;
			}
		} break;
		}
		g_pFramework->Update ();
	}
	
}
