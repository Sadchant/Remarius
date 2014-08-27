#include "Game.hpp"

CGame::CGame ()																									// Game initialisieren
{

	m_pMenubackground = NULL;																				// Pausemenühintergrund erzeugen
	m_pMenubackground = new CSprite;
	m_pMenubackground->Load ("Data/Pausemenuhintergrund.png", 0, 755, 570);

	m_pMenubuttons = NULL;																				// Staubsaugersprite erzeugen
	m_pMenubuttons = new CSprite;
	m_pMenubuttons->Load ("Data/Menubuttons.png", 0, 301, 65);

//	m_pBaum = NULL;																				// Staubsaugersprite erzeugen
//	m_pBaum = new CSprite;
//	m_pBaum->Load ("Data/Baum_1klein.png", 4, 260, 244);


	m_bGameRun = true;

	m_pTextMenucaption = NULL;
	m_pTextMenucaption = new CText;
	m_pTextMenucaption->Open ("Data/verdana.ttf", 40);

	m_pTextMenutext = NULL;
	m_pTextMenutext = new CText;
	m_pTextMenutext->Open ("Data/verdana.ttf", 19);

	m_pTextMenuSave = NULL;
	m_pTextMenuSave = new CText;
	m_pTextMenuSave->Open ("Data/verdana.ttf", 25);

	m_pTrack_1 = NULL;
	m_pTrack_1 = new CSound;
	m_pTrack_1->OpenMusic ("Music/Track_1.mp3");

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
	if (m_pTrack_1 != NULL)																			// Staubsaugersprite freigeben
	{
		m_pTrack_1->StopMusic ();
		delete (m_pTrack_1);
		m_pTrack_1 = NULL;
	}
	
}
void CGame::Run ()         // Hauptschleife des Spiels
{
	while (m_bGameRun == true)																		// Wenn es läuft...
	{																			// Events bearbeiten
	
	g_pFramework->Update ();																		// Framework updaten und Buffer löschen


	Rectmaster.Update();
																									// Stachelsteinen rendern
	FpsCounter ();

	ProcessEvents ();	
	m_pTrack_1->PlayMusic ();
	g_pFramework->Render ();																				// Buffer flippen
	

  }

}

void CGame::Run (int i)         // Hauptschleife des Spiels
{
	cout << "In der Game angekommen" << endl;
	Load();
	while (m_bGameRun == true)																		// Wenn es läuft...
	{																			// Events bearbeiten
	
	g_pFramework->Update ();																		// Framework updaten und Buffer löschen

	Rectmaster.Update();

	FpsCounter ();


	ProcessEvents ();	
	m_pTrack_1->PlayMusic ();
	g_pFramework->Render ();																				// Buffer flippen

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
	cout << Framecounter << "; ";
	Framecounter = 0;
	Timecounter--;
	}
}

void CGame::ProcessEvents ()																				// Events bearbeiten
{
  SDL_Event Event;

  if (SDL_PollEvent (&Event))																		// Gab es ein Event?
  {
    switch (Event.type)																				// Ja, also schauen welches
    {
      
      case (SDL_QUIT):																				// Beenden?
      {
        m_bGameRun = false;

      } break;
      case (SDL_KEYDOWN):																			// Wurde eine Taste gedrückt?
      {
        switch (Event.key.keysym.sym)
        {
          case (SDL_SCANCODE_ESCAPE):																		// Wurde Escape gedrückt?
          {
				m_State=1;																			// Auswahl auf "Spiel fortsetzen" setzen
				m_bBreakLock=false;
				Break ();																			// Pausemenü laufen lassen	
          } break;

		   case (SDL_SCANCODE_L):
                  {
                                Load();
                  } break;
           case (SDL_SCANCODE_K):
                  {
                                Save();
                  } break;
        }
      } break;
    }
  }

}
void CGame::Break()
{
	m_bEscapeLock=true;
	while (m_bBreakLock==false)	
	{
		m_pMenubackground->SetPos (134, 99);
		m_pMenubackground->Render (0);
		m_pTextMenucaption->SetTextColor (230, 230, 0);
		m_pTextMenucaption->SetText ("Pause");
		m_pTextMenucaption->Render (static_cast<float>((755 - m_pTextMenucaption->GetLength())/2+ 134), 200);

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
				m_pTextMenutext->SetTextColor (255, 255, 255);
				m_pTextMenutext->SetText ("Fortsetzen");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Speichern");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 354));

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Beenden");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 434));

			} break;

		case (2):
			{
				
				cout<<"Speichern"<<endl;
				m_pMenubuttons->SetPos (361, 274);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Fortsetzen");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 1);
				m_pTextMenutext->SetTextColor (255, 255, 255);
				m_pTextMenutext->SetText ("Speichern");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 354));

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Beenden");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 434));

			} break;
		case (3):
			{
				m_pMenubuttons->SetPos (361, 274);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Fortsetzen");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

				m_pMenubuttons->SetPos (361, 354);
				m_pMenubuttons->Render (0, 0);
				m_pTextMenutext->SetTextColor (180, 180, 180);
				m_pTextMenutext->SetText ("Speichern");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 354));

				m_pMenubuttons->SetPos (361, 434);
				m_pMenubuttons->Render (0, 1);
				m_pTextMenutext->SetTextColor (255, 255, 255);
				m_pTextMenutext->SetText ("Beenden");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
										static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 434));
			} break;
				
		}

		g_pFramework->Render ();

		SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);	
		SDL_WaitEvent(&event);

		switch (m_State)
		{
		case (1):
		{
			switch (event.key.keysym.sym)
			{
				case (SDL_SCANCODE_RETURN):
				{
					if (m_bEnterLock==false)
					{
						SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);	
						m_bBreakLock=true;
					}
				} break;
				case (SDL_SCANCODE_DOWN):
				{
				if (m_bStateLock==false)
				{
					m_State=2;
					m_bStateLock=true;
				}
				} break;

				case (SDL_SCANCODE_UP):	
				{
				if (m_bStateLock==false)
				{
					m_State=3;
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
						cout<<"Wirklich speichern?"<<endl;
						m_pMenubackground->SetPos (134, 99);
						m_pMenubackground->Render (0);
						m_pTextMenuSave->SetTextColor (230, 230, 0);
						m_pTextMenuSave->SetText ("Soll wirklich gespeichert werden?");
						m_pTextMenuSave->Render (static_cast<float>((755 - m_pTextMenuSave->GetLength())/2+ 134), 240);

						while (	m_bBreakLock2==false)
						{
							if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
								m_bEnterLock=false;
							if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
								m_bStateLock=false;

							switch (m_State2)
							{
							case(1):
								cout<<"Ja"<<endl; 
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetTextColor (255, 255, 255);
								m_pTextMenutext->SetText ("Ja");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetTextColor (180, 180, 180);
								m_pTextMenutext->SetText ("Nein");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
								break;

							case(2):
								cout<<"Nein"<<endl;
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetTextColor (180, 180, 180);
								m_pTextMenutext->SetText ("Ja");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetTextColor (255, 255, 255);
								m_pTextMenutext->SetText ("Nein");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
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
										cout<<"Spiel wurde gespeichert"<<endl;
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
						cout<<"Wirklich beenden?"<<endl;
						m_pMenubackground->SetPos (134, 99);
						m_pMenubackground->Render (0);
						m_pTextMenuSave->SetTextColor (230, 230, 0);
						m_pTextMenuSave->SetText ("Soll wirklich beendet werden?");
						m_pTextMenuSave->Render (static_cast<float>((755 - m_pTextMenuSave->GetLength())/2+ 134), 240);

						while (	m_bBreakLock2==false)
						{
							if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
								m_bEnterLock=false;
							if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
								m_bStateLock=false;

							switch (m_State2)
							{
							case(1):
								cout<<"Ja"<<endl; 
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetTextColor (255, 255, 255);
								m_pTextMenutext->SetText ("Ja");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetTextColor (180, 180, 180);
								m_pTextMenutext->SetText ("Nein");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
								break;

							case(2):
								cout<<"Nein"<<endl;
								m_pMenubuttons->SetPos (361, 304);
								m_pMenubuttons->Render (0, 0);
								m_pTextMenutext->SetTextColor (180, 180, 180);
								m_pTextMenutext->SetText ("Ja");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

								m_pMenubuttons->SetPos (361, 394);
								m_pMenubuttons->Render (0, 1);
								m_pTextMenutext->SetTextColor (255, 255, 255);
								m_pTextMenutext->SetText ("Nein");
								m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
														static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
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
										m_pTrack_1->PauseMusic ();
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
