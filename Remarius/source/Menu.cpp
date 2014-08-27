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
	m_pTextMenucaption->Open ("Data/verdana.ttf", 40);

	m_pTextMenutext = NULL;
	m_pTextMenutext = new CText;
	m_pTextMenutext->Open ("Data/verdana.ttf", 19);

	m_pTextMenutextd = NULL;
	m_pTextMenutextd = new CText;
	m_pTextMenutextd->Open ("Data/verdana.ttf", 19);

	cout << "Menüsachen geladen" << endl;
}
void CMenu::Run()
{
	cout << "Menu: Run gestartet" << endl;
        SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);
		m_bEnterLock=true;
        while  (m_bMenu1End==false)
        {
			m_pMenuBackground->Render ();
			m_pTextMenucaption->SetTextColor (230, 230, 0);
			m_pTextMenucaption->SetText ("Hauptmenü");
			m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
               
                if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
                        m_bEnterLock=false;

                switch (m_State)
                {
                case (1):
                    m_pMenubuttons->SetPos (334, 274);
					m_pMenubuttons->Render (0, 1);
					m_pTextMenutext->SetTextColor (255, 255, 255);
					m_pTextMenutext->SetText ("Spielen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

					m_pMenubuttons->SetPos (334, 374);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Optionen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

					m_pMenubuttons->SetPos (334, 474);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Beenden");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
                        break;
                case (2):
					m_pMenubuttons->SetPos (334, 274);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Spielen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

					m_pMenubuttons->SetPos (334, 374);
					m_pMenubuttons->Render (0, 1);
					m_pTextMenutext->SetTextColor (255, 255, 255);
					m_pTextMenutext->SetText ("Optionen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

					m_pMenubuttons->SetPos (334, 474);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Beenden");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
                       
					break;
                case (3):
					m_pMenubuttons->SetPos (334, 274);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Spielen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

					m_pMenubuttons->SetPos (334, 374);
					m_pMenubuttons->Render (0, 0);
					m_pTextMenutext->SetTextColor (180, 180, 180);
					m_pTextMenutext->SetText ("Optionen");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

					m_pMenubuttons->SetPos (334, 474);
					m_pMenubuttons->Render (0, 1);
					m_pTextMenutext->SetTextColor (255, 255, 255);
					m_pTextMenutext->SetText ("Beenden");
					m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
                       
                    break;
                } 
				m_pTextMenutextd->SetTextColor (210, 210, 0);
				m_pTextMenutextd->SetText ("Remarius Risation InDev 1.6");
				m_pTextMenutextd->Render (30, static_cast<float>(768 - 25 - m_pTextMenutextd->GetHigh()));
				m_pTextMenutextd->SetText ("2012 - 2014, Karsadlan Corporation");
				m_pTextMenutextd->Render (static_cast<float>(1024 - 30 - m_pTextMenutextd->GetLength()), static_cast<float>(768 - 25 - m_pTextMenutext->GetHigh()));
				g_pFramework->Render ();

				 
				SDL_WaitEvent(&event);
                if (m_State==1)
                {          
					switch (event.type)
					{
					case (SDL_KEYDOWN):
					switch (event.key.keysym.sym)
                    {
					case (SDLK_DOWN):
						{
							if (m_bStateLock==false)
							{
								m_State=2;
							    m_bStateLock=true;
							}
						} break;

					case (SDLK_UP):
						{
							if (m_bStateLock==false)
							{
								m_State=3;
							    m_bStateLock=true;
							}
						} break;
 
					case(SDLK_ESCAPE) :
						{
							if (m_bEscapeLock==false)
							{
							m_bMenu1End=true;
							m_bEscapeLock=true;
							}
						} break;
					}
					break;
					case (SDL_KEYUP):
					switch (event.key.keysym.sym)
					{
						case (SDLK_RETURN):
                        {
							if (m_bEnterLock==false)
								Play ();
						} break;
					}
					break;
					}					 
				}
 
            if (m_State==2)
            {               
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
                {
					case (SDLK_UP):
					{
						if (m_bStateLock==false)
						{
							m_State=1;
							m_bStateLock=true;
						}
					} break;
 
					case (SDLK_DOWN):
					{
						if (m_bStateLock==false)
						{
							m_State=3;
							m_bStateLock=true;
						}
					} break;
 
					case (SDLK_ESCAPE) :
					{
						if (m_bEscapeLock==false)
						{
						m_bMenu1End=true;
						m_bEscapeLock=true;
						}
					} break;
				}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
					case (SDLK_RETURN):
					{
							Options();
					} break;
				}
				break;
				}
			}
 
			if (m_State==3)
			{
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
                {	
					case (SDLK_UP):
					{
						if (m_bStateLock==false)
						{
							m_State=2;
							m_bStateLock=true;
						}
					} break;

					case (SDLK_DOWN):
					{
						if (m_bStateLock==false)
						{
							m_State=1;
							m_bStateLock=true;
						}
					} break;
 
					case (SDLK_ESCAPE) :
					{
						if (m_bEscapeLock==false)
						{
						m_bMenu1End=true;
						m_bEscapeLock=true;
						}
					} break;
				}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
					case (SDLK_RETURN):
					{
							SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
							m_bMenu1End=true;
					} break;
				}
				break;
				}
			}
 
			if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
				m_bEscapeLock=false;
 
			if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
				m_bStateLock=false;
 
		}        
}

void CMenu::Options()
{
	m_bEnterLock=true;
	m_bMenu2End=false;
	m_State=1;
	m_State2=1;
	m_bEnterLock=true;
	m_bFullSize = false;
	while (m_bMenu2End==false)
	{
		m_pMenuBackground->Render ();
		m_pTextMenucaption->SetTextColor (230, 230, 0);
		m_pTextMenucaption->SetText ("Optionen");
		m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 70);
		switch (m_State2)
		{
		case (1):
			m_pMenubuttons->SetPos (334, 174);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			if (m_bFullSize == true)
			{
				m_pTextMenutext->SetText ("Vollbildmodus: an");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, true) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
			else 
			{
				m_pTextMenutext->SetText ("Vollbildmodus: aus");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, false) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
	

			m_pSoundbuttons->SetPos (334, 274);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 274);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 344);
			m_pSoundbuttons->Render (0, 4);			
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Musik");
			m_pTextMenutext->Render (420, 364);
			m_pSoundbalken-> SetPos (442, 304);
			m_pSoundbalken->Render ();
			m_pSoundschieber-> SetPos (442, 293);
			m_pSoundschieber->Render ();

			m_pSoundbuttons->SetPos (334, 444);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 444);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 514);
			m_pSoundbuttons->Render (0, 4);
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Sound");
			m_pTextMenutext->Render (420, 534);
			m_pSoundbalken-> SetPos (442, 474);
			m_pSoundbalken->Render ();

			m_pMenubuttons->SetPos (334, 614);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 614));
			break;
		case (2):
			cout<<"Musik"<<endl;
			m_pMenubuttons->SetPos (334, 174);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			if (m_bFullSize == true)
			{
				m_pTextMenutext->SetText ("Vollbildmodus: an");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, true) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
			else 
			{
				m_pTextMenutext->SetText ("Vollbildmodus: aus");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, false) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
	

			m_pSoundbuttons->SetPos (334, 274);
			m_pSoundbuttons->Render (0, 1);
			m_pSoundbuttons->SetPos (625, 274);
			m_pSoundbuttons->Render (0, 3);

			m_pSoundbuttons->SetPos (334, 344);
			m_pSoundbuttons->Render (0, 4);			
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Musik");
			m_pTextMenutext->Render (420, 364);
			m_pSoundbalken-> SetPos (442, 304);
			m_pSoundbalken->Render ();
			m_pSoundschieber-> SetPos (442, 293);
			m_pSoundschieber->Render ();

			m_pSoundbuttons->SetPos (334, 444);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 444);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 514);
			m_pSoundbuttons->Render (0, 4);
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Sound");
			m_pTextMenutext->Render (420, 534);
			m_pSoundbalken-> SetPos (442, 474);
			m_pSoundbalken->Render ();

			m_pMenubuttons->SetPos (334, 614);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 614));
			break;
			
			break;
		case (3):
			cout<<"Sound"<<endl;

			m_pMenubuttons->SetPos (334, 174);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			if (m_bFullSize == true)
			{
				m_pTextMenutext->SetText ("Vollbildmodus: an");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, true) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
			else 
			{
				m_pTextMenutext->SetText ("Vollbildmodus: aus");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, false) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
	

			m_pSoundbuttons->SetPos (334, 274);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 274);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 344);
			m_pSoundbuttons->Render (0, 4);			
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Musik");
			m_pTextMenutext->Render (420, 364);
			m_pSoundbalken-> SetPos (442, 304);
			m_pSoundbalken->Render ();
			m_pSoundschieber-> SetPos (442, 293);
			m_pSoundschieber->Render ();

			m_pSoundbuttons->SetPos (334, 444);
			m_pSoundbuttons->Render (0, 1);
			m_pSoundbuttons->SetPos (625, 444);
			m_pSoundbuttons->Render (0, 3);
			m_pSoundbuttons->SetPos (334, 514);
			m_pSoundbuttons->Render (0, 4);
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Sound");
			m_pTextMenutext->Render (420, 534);
			m_pSoundbalken-> SetPos (442, 474);
			m_pSoundbalken->Render ();

			m_pMenubuttons->SetPos (334, 614);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 614));
			break;


			break;
		case (4):
			m_pMenubuttons->SetPos (334, 174);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			if (m_bFullSize == true)
			{
				m_pTextMenutext->SetText ("Vollbildmodus: an");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, true) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
			else 
			{
				m_pTextMenutext->SetText ("Vollbildmodus: aus");
				m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 174));
				//if (g_pFramework->Init (1024, 768, 32, false) == false)
							//cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
			}
	

			m_pSoundbuttons->SetPos (334, 274);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 274);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 344);
			m_pSoundbuttons->Render (0, 4);			
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Musik");
			m_pTextMenutext->Render (420, 364);
			m_pSoundbalken-> SetPos (442, 304);
			m_pSoundbalken->Render ();
			m_pSoundschieber-> SetPos (442, 293);
			m_pSoundschieber->Render ();

			m_pSoundbuttons->SetPos (334, 444);
			m_pSoundbuttons->Render (0, 0);
			m_pSoundbuttons->SetPos (625, 444);
			m_pSoundbuttons->Render (0, 2);
			m_pSoundbuttons->SetPos (334, 514);
			m_pSoundbuttons->Render (0, 4);
			m_pTextMenutext->SetTextColor (230, 230, 0);
			m_pTextMenutext->SetText ("Sound");
			m_pTextMenutext->Render (420, 534);
			m_pSoundbalken-> SetPos (442, 474);
			m_pSoundbalken->Render ();

			m_pMenubuttons->SetPos (334, 614);
			m_pMenubuttons->Render (0, 1);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 614));
			break;
		
		}  
		g_pFramework->Render ();
										
		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
			m_bEnterLock=false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
			m_bStateLock=false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
			m_bEscapeLock=false;

		SDL_WaitEvent(&event);
									
		switch (m_State2)
		{
		case (1):
			{
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{
				case (SDLK_DOWN):
					{
						if (m_bStateLock==false)
						{
							m_State2=2;
							m_bStateLock=true;
						}
					} break;
				case (SDLK_UP):
					{
						if (m_bStateLock==false)
						{
							m_State2=4;
							m_bStateLock=true;
						}
					} break;
				case (SDLK_ESCAPE) :
					{
						if (m_bEscapeLock==false)
						{
						m_bMenu2End=true;
						m_bEscapeLock=true;
						}
					} break;
				}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
					case (SDLK_RETURN):
					{
							if(m_bFullSize==true)
							{
								cout<<"Vollbild: aus"<<endl;
								// Vollbildmodus deaktivieren
								if (g_pFramework->Init_Video("Remarius Risation Indev 1.6", 1024, 768, false) == false)				//hier aus Datei einlesen und in Datei schreiben!
								cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
								m_bFullSize=false;
								
							} else
							{
								cout<<"Vollbild: an"<<endl;
								if (g_pFramework->Init_Video("Remarius Risation Indev 1.6", 1024, 768, true) == false)				//hier aus Datei einlesen und in Datei schreiben!
								cout << "Fehler beim Umschalten in Vollbildmodus" << endl;	
								m_bFullSize=true;
							}
					} break;
				}
				break;
				}
			} break;
		case (2):
			{
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{
				case (SDLK_UP):
					{
						if (m_bStateLock==false)
						{
							m_State2=1;
							m_bStateLock=true;
						}
					} break;
				case (SDLK_DOWN):
					{
						if (m_bStateLock==false)
						{
							m_State2=3;
							m_bStateLock=true;
						}
					} break;
				case (SDLK_ESCAPE) :
					{
						if (m_bEscapeLock==false)
						{
						m_bMenu2End=true;
						m_bEscapeLock=true;
						}
					} break;
				}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
					case (SDLK_RETURN):
					{
						if(m_bMusic==true)
						{
							cout<<"Musik: aus"<<endl;
							m_bMusic=false;
						} else
						{
							cout<<"Musik: an"<<endl;
							m_bMusic=true;
						}
					} break;
				}
				break;
				}
			} break;
			case (3):
				{
					switch (event.type)
					{
					case (SDL_KEYDOWN):
					switch (event.key.keysym.sym)
					{
					case (SDLK_UP):
						{
							if (m_bStateLock==false)
							{
								m_State2=2;
								m_bStateLock=true;
							}
						} break;
					case (SDLK_DOWN):
						{
							if (m_bStateLock==false)
							{
								m_State2=4;
								m_bStateLock=true;
							}
						} break;
					case (SDLK_ESCAPE) :
						{
							if (m_bEscapeLock==false)
							{
							m_bMenu2End=true;
							m_bEscapeLock=true;
							}
						} break;
					}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
					case (SDLK_RETURN):
					{
						if(m_bSound==true)
						{
							cout<<"Sound: aus"<<endl;
							m_bSound=false;
						} else
						{
							cout<<"Sound: an"<<endl;
							m_bSound=true;
						}
					} break;
				}
				break;
				}
				} break;
				case (4):
				{
				switch (event.type)
				{
					case (SDL_KEYDOWN):
					switch (event.key.keysym.sym)
					{
					case (SDLK_UP):
						{
							if (m_bStateLock==false)
							{
								m_State2=3;
								m_bStateLock=true;
							}
						} break;
					case (SDLK_DOWN):
						{
							if (m_bStateLock==false)
							{
								m_State2=1;
								m_bStateLock=true;
							}
						} break;
					case (SDLK_ESCAPE) :
						{
							if (m_bEscapeLock==false)
							{
							m_bMenu2End=true;
							m_bEscapeLock=true;
							}
						} break;
					}
					break;
					case (SDL_KEYUP):
					switch (event.key.keysym.sym)
					{
						case (SDLK_RETURN):
						{
							m_bMenu2End=true;
							m_bEnterLock=true;
						} break;
					}
					break;
				}
				} break;
			}
			 
		}
}
void CMenu::Play()
{
	m_bEnterLock=true;
	m_bMenu2End=false;
	m_State=1;
	m_State2=1;
	while (m_bMenu2End==false)
	{
		m_pMenuBackground->Render ();
		m_pMenuBackground->Render ();
		m_pTextMenucaption->SetTextColor (230, 230, 0);
		m_pTextMenucaption->SetText ("Wähle einen Spielstand");
		m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
		switch (m_State2)
		{
		case (1):
			cout<<"Spielstand 1"<<endl;
			m_pMenubuttons->SetPos (334, 274);
			m_pMenubuttons->Render (0, 1);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			m_pTextMenutext->SetText ("Spielstand 1");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

			m_pMenubuttons->SetPos (334, 374);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 2");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

			m_pMenubuttons->SetPos (334, 474);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 3");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));

			m_pMenubuttons->SetPos (334, 574);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 574));
			break;
		case (2):
			cout<<"Spielstand 2"<<endl;
			m_pMenubuttons->SetPos (334, 274);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 1");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

			m_pMenubuttons->SetPos (334, 374);
			m_pMenubuttons->Render (0, 1);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			m_pTextMenutext->SetText ("Spielstand 2");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

			m_pMenubuttons->SetPos (334, 474);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 3");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));

			m_pMenubuttons->SetPos (334, 574);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 574));
			break;
		case (3):
			cout<<"Spielstand 3"<<endl; 
			m_pMenubuttons->SetPos (334, 274);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 1");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

			m_pMenubuttons->SetPos (334, 374);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 2");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

			m_pMenubuttons->SetPos (334, 474);
			m_pMenubuttons->Render (0, 1);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			m_pTextMenutext->SetText ("Spielstand 3");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));

			m_pMenubuttons->SetPos (334, 574);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 574));
			break;
		case (4):
			cout<<"Zurück"<<endl; 
			m_pMenubuttons->SetPos (334, 274);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 1");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

			m_pMenubuttons->SetPos (334, 374);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 2");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

			m_pMenubuttons->SetPos (334, 474);
			m_pMenubuttons->Render (0, 0);
			m_pTextMenutext->SetTextColor (180, 180, 180);
			m_pTextMenutext->SetText ("Spielstand 3");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));

			m_pMenubuttons->SetPos (334, 574);
			m_pMenubuttons->Render (0, 1);
			m_pTextMenutext->SetTextColor (255, 255, 255);
			m_pTextMenutext->SetText ("Zurück");
			m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
											static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 574));
			break;
		}
		g_pFramework->Render ();
		 
		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
			m_bEnterLock=false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
			m_bStateLock=false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
			m_bEscapeLock=false;

		SDL_WaitEvent(&event);
									
		switch (m_State2)
		{
		case (1):
			{
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{	
				case (SDLK_DOWN):
				{
					if (m_bStateLock==false)
					{
						m_State2=2;
						m_bStateLock=true;
					}
				} break;
				case (SDLK_UP):
				{
					if (m_bStateLock==false)
					{
					m_State2=4;
					m_bStateLock=true;
					}
				} break;
				case (SDLK_ESCAPE) :
				{
					if (m_bEscapeLock==false)
					{
					m_bMenu2End=true;
					m_bEscapeLock=true;
					}
				} break;
				}
				break;
				case (SDL_KEYUP):
				switch (event.key.keysym.sym)
				{
				case (SDLK_RETURN):
				{
					CGame Game;
					Game.m_Savestate=1;
								m_bEnterLock=true;
								m_bMenu3End=false;
								m_State3=1;
								if (Game.Load()==false)
								{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 1");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
										switch (m_State3)
										{
											case (1):
												cout<<"Neues Spiel"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

												break;
											case (2):
												cout<<"Zurück"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));
												break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);

										switch (m_State3)
										{
										case(1):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{	
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case (SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run ();
															Game.Quit();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case (SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEnterLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
									}
									}
									else
									{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 1");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
																		switch (m_State3)
										{
										case (1):
											cout<<"Spiel fortsetzen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (2):
											cout<<"Spielstand löschen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (3):
											cout<<"zurück"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);
										switch (m_State3)
										{				
										case (1):			
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run (1);
															Game.Quit ();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															m_bEnterLock=true;
															m_State4=1;
															m_bMenu4End=false;
															cout<<"Wirklich loeschen?"<<endl;
															m_pMenuBackground->Render ();
															m_pTextMenutext->SetTextColor (230, 230, 0);
															m_pTextMenutext->SetText ("Soll wirklich gelöscht werden?");
															m_pTextMenutext->Render (static_cast<float>((755 - m_pTextMenutext->GetLength())/2+ 134), 240);
	
															while (	m_bMenu4End==false)
															{
																if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
																	m_bEnterLock=false;
																if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
																	m_bStateLock=false;

																switch (m_State4)
																{
																case(1):
																	cout<<"Ja"<<endl; 
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
	
																case(2):
																	cout<<"Nein"<<endl;
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
																}
																g_pFramework->Render ();

																SDL_WaitEvent(&event);
																switch (m_State4)
																{
																case (1):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case (SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case (SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case (SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																		case (SDLK_RETURN):
																			cout<<"Spiel wurde geloescht"<<endl;
																			m_bMenu4End=true;
																			m_bMenu3End=true;
																			m_State2=1;
																			m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;
																case (2):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case (SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case (SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case (SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																	case (SDLK_RETURN):
																		m_bMenu4End=true;
																		m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;	
																}
															}
													} break;
												}
												break;
												}
											} break;
										case (3):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;								
													}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;												
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
										}
										}
											} break;
										}
										break;
										}
									} break;
									
		case (2):
			{
				switch (event.type)
				{
				case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{
										case (SDLK_DOWN):
											{
												if (m_bStateLock==false)
												{
													m_State2=3;
													m_bStateLock=true;
												}
											} break;
										case (SDLK_UP):
											{
												if (m_bStateLock==false)
												{
													m_State2=1;
													m_bStateLock=true;
												}
											} break;
										case (SDLK_ESCAPE) :
											{
												if (m_bEscapeLock==false)
												{
												m_bMenu2End=true;
												m_bEscapeLock=true;
												}
											} break;
										}
										break;
										case (SDL_KEYUP):
										switch (event.key.keysym.sym)
										{
											case (SDLK_RETURN):
						{
								CGame Game;
								Game.m_Savestate=2;
								m_bEnterLock=true;
								m_bMenu3End=false;
								m_State3=1;
								if (Game.Load()==false)
								{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 2");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
										switch (m_State3)
										{
											case (1):
												cout<<"Neues Spiel"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

												break;
											case (2):
												cout<<"Zurück"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));
												break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);

										switch (m_State3)
										{
										case(1):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{	
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case (SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run ();
															Game.Quit();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case (SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEnterLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
									}
									}
									else
									{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 2");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
																		switch (m_State3)
										{
										case (1):
											cout<<"Spiel fortsetzen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (2):
											cout<<"Spielstand löschen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (3):
											cout<<"zurück"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);
										switch (m_State3)
										{				
										case (1):			
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{
												case (SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case (SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run (1);
															Game.Quit ();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															m_bEnterLock=true;
															m_State4=1;
															m_bMenu4End=false;
															cout<<"Wirklich loeschen?"<<endl;
															m_pMenuBackground->Render ();
															m_pTextMenutext->SetTextColor (230, 230, 0);
															m_pTextMenutext->SetText ("Soll wirklich gelöscht werden?");
															m_pTextMenutext->Render (static_cast<float>((755 - m_pTextMenutext->GetLength())/2+ 134), 240);
	
															while (	m_bMenu4End==false)
															{
																if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
																	m_bEnterLock=false;
																if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
																	m_bStateLock=false;

																switch (m_State4)
																{
																case(1):
																	cout<<"Ja"<<endl; 
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
	
																case(2):
																	cout<<"Nein"<<endl;
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
																}
																g_pFramework->Render ();

																SDL_WaitEvent(&event);
																switch (m_State4)
																{
																case (1):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case(SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																		case(SDLK_RETURN):
																			cout<<"Spiel wurde geloescht"<<endl;
																			m_bMenu4End=true;
																			m_bMenu3End=true;
																			m_State2=1;
																			m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;
																case (2):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case(SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																	case(SDLK_RETURN):
																		m_bMenu4End=true;
																		m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;	
																}
															}
													} break;
												}
												break;
												}
											} break;
										case (3):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;								
													}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;												
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
										}
										}
											} break;
										}
										break;
										}
									} break;
									case (3):
										{
										switch (event.type)
										{
										case (SDL_KEYDOWN):
										switch (event.key.keysym.sym)
										{
										case(SDLK_DOWN):
											{
												if (m_bStateLock==false)
												{
													m_State2=4;
													m_bStateLock=true;
												}
											} break;
										case(SDLK_UP):
											{
												if (m_bStateLock==false)
												{
													m_State2=2;
													m_bStateLock=true;
												}
											} break;
										case(SDLK_ESCAPE) :
											{
												if (m_bEscapeLock==false)
												{
												m_bMenu2End=true;
												m_bEscapeLock=true;
												}
											} break;
										}
										break;
										case (SDL_KEYUP):
										switch (event.key.keysym.sym)
										{
											case(SDLK_RETURN):
											{
								CGame Game;
								Game.m_Savestate=3;
								m_bEnterLock=true;
								m_bMenu3End=false;
								m_State3=1;
								if (Game.Load()==false)
								{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 3");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
										switch (m_State3)
										{
											case (1):
												cout<<"Neues Spiel"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

												break;
											case (2):
												cout<<"Zurück"<<endl;
												m_pMenubuttons->SetPos (334, 274);
												m_pMenubuttons->Render (0, 0);
												m_pTextMenutext->SetTextColor (180, 180, 180);
												m_pTextMenutext->SetText ("Neues Spiel");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

												m_pMenubuttons->SetPos (334, 374);
												m_pMenubuttons->Render (0, 1);
												m_pTextMenutext->SetTextColor (255, 255, 255);
												m_pTextMenutext->SetText ("Zurück");
												m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																				static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));
												break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);

										switch (m_State3)
										{
										case(1):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{	
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run ();
															Game.Quit();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEnterLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
									}
									}
									else
									{
									while (m_bMenu3End==false)
									{
										m_pMenuBackground->Render ();
										m_pMenuBackground->Render ();
										m_pTextMenucaption->SetTextColor (230, 230, 0);
										m_pTextMenucaption->SetText ("Spielstand 3");
										m_pTextMenucaption->Render (static_cast<float>((1024 - m_pTextMenucaption->GetLength())/2), 170);
																		switch (m_State3)
										{
										case (1):
											cout<<"Spiel fortsetzen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (2):
											cout<<"Spielstand löschen"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										case (3):
											cout<<"zurück"<<endl;
											m_pMenubuttons->SetPos (334, 274);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand fortsetzen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 274));

											m_pMenubuttons->SetPos (334, 374);
											m_pMenubuttons->Render (0, 0);
											m_pTextMenutext->SetTextColor (180, 180, 180);
											m_pTextMenutext->SetText ("Spielstand löschen");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 374));

											m_pMenubuttons->SetPos (334, 474);
											m_pMenubuttons->Render (0, 1);
											m_pTextMenutext->SetTextColor (255, 255, 255);
											m_pTextMenutext->SetText ("Zurück");
											m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																			static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 474));
										break;
										}
										g_pFramework->Render ();
										if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
											m_bEnterLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
											m_bStateLock=false;
										if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
											m_bEscapeLock=false;
										SDL_WaitEvent(&event);
										switch (m_State3)
										{				
										case (1):			
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
															Game.Run (1);
															Game.Quit ();
															m_bEscapeLock=true;
															m_bEnterLock=true;
															m_bMenu3End=true;
															m_bMenu2End=true;
													} break;
												}
												break;
												}
											} break;
										case (2):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=3;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
															m_bEnterLock=true;
															m_State4=1;
															m_bMenu4End=false;
															cout<<"Wirklich loeschen?"<<endl;
															m_pMenuBackground->Render ();
															m_pTextMenutext->SetTextColor (230, 230, 0);
															m_pTextMenutext->SetText ("Soll wirklich gelöscht werden?");
															m_pTextMenutext->Render (static_cast<float>((755 - m_pTextMenutext->GetLength())/2+ 134), 240);
	
															while (	m_bMenu4End==false)
															{
																if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN)==false)
																	m_bEnterLock=false;
																if (g_pFramework->KeyDown(SDL_SCANCODE_UP)==false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)==false)
																	m_bStateLock=false;

																switch (m_State4)
																{
																case(1):
																	cout<<"Ja"<<endl; 
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
	
																case(2):
																	cout<<"Nein"<<endl;
																	m_pMenubuttons->SetPos (334, 274);
																	m_pMenubuttons->Render (0, 0);
																	m_pTextMenutext->SetTextColor (180, 180, 180);
																	m_pTextMenutext->SetText ("Ja");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 304));

																	m_pMenubuttons->SetPos (334, 374);
																	m_pMenubuttons->Render (0, 1);
																	m_pTextMenutext->SetTextColor (255, 255, 255);
																	m_pTextMenutext->SetText ("Nein");
																	m_pTextMenutext->Render (static_cast<float>((301 - m_pTextMenutext->GetLength())/2+ 361),
																							static_cast<float>((65 - m_pTextMenutext->GetHigh())/2 + 394));
																break;
																}
																g_pFramework->Render ();

																SDL_WaitEvent(&event);
																switch (m_State4)
																{
																case (1):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case(SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=2;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																		case(SDLK_RETURN):
																			cout<<"Spiel wurde geloescht"<<endl;
																			m_bMenu4End=true;
																			m_bMenu3End=true;
																			m_State2=1;
																			m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;
																case (2):
																{
																	switch (event.type)
																	{
																	case (SDL_KEYDOWN):
																	switch (event.key.keysym.sym)
																	{																	
																	case(SDLK_DOWN):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_UP):
																		if (m_bStateLock==false)
																		{
																			m_State4=1;
																			m_bStateLock=true;
																		}
																	break;
																	case(SDLK_ESCAPE) :
																		if (m_bEscapeLock==false)
																		{
																			m_bMenu4End=true;
																			m_bEscapeLock=true;
																		}
																	break;
																	}
																	break;
																	case (SDL_KEYUP):
																	switch (event.key.keysym.sym)
																	{
																	case(SDLK_RETURN):
																		m_bMenu4End=true;
																		m_bEnterLock=true;
																	break;
																	}
																	break;
																	}
																} break;	
																}
															}
													} break;
												}
												break;
												}
											} break;
										case (3):
											{
												switch (event.type)
												{
												case (SDL_KEYDOWN):
												switch (event.key.keysym.sym)
												{												
												case(SDLK_DOWN):
													{
														if (m_bStateLock==false)
														{
															m_State3=1;
															m_bStateLock=true;								
													}
													} break;
												case(SDLK_UP):
													{
														if (m_bStateLock==false)
														{
															m_State3=2;
															m_bStateLock=true;
														}
													} break;
												case(SDLK_ESCAPE) :
													{
														if (m_bEscapeLock==false)
														{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
														}
													} break;												
												}
												break;
												case (SDL_KEYUP):
												switch (event.key.keysym.sym)
												{
													case(SDLK_RETURN):
													{
														m_bMenu3End=true;
														m_bEscapeLock=true;
														m_State2=1;
													} break;
												}
												break;
												}
											} break;
										}
										}
										}
											} break;
										}
										break;
										}
									} break;						
						case (4):
						{	
						switch (event.type)
						{
						case (SDL_KEYDOWN):
						switch (event.key.keysym.sym)
						{						
						case(SDLK_DOWN):
						{
							if (m_bStateLock==false)
							{
								m_State2=1;
								m_bStateLock=true;
							}
						} break;
						case(SDLK_UP):
						{
							if (m_bStateLock==false)
							{
								m_State2=3;
								m_bStateLock=true;
							}
						} break;
						case(SDLK_ESCAPE) :
						{
							if (m_bEscapeLock==false)
							{
								m_bMenu2End=true;
								m_bEscapeLock=true;
							}
						} break;
						}
						break;
						case (SDL_KEYUP):
						switch (event.key.keysym.sym)
						{
						case(SDLK_RETURN):
						{
							m_bMenu2End=true;
							m_bEscapeLock=true;
							m_bEnterLock=true;
						} break;
						}
						break;
						}
				} break;
		}	
	}	
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
}
