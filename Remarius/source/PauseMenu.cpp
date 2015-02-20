#include "PauseMenu.hpp"

void CPauseMenu::Tick()
{
	/*m_bEscapeLock = true;
	while (m_bBreakLock == false)
	{
		m_pMenubackground->SetPos(134, 99);
		m_pMenubackground->Render(0);
		m_pTextMenucaption->SetColor(230, 230, 0);
		m_pTextMenucaption->SetContent("Pause");
		m_pTextMenucaption->SetPos(((755 - m_pTextMenucaption->Get_length()) / 2 + 134), 200);
		m_pTextMenucaption->Render();

		if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN) == false)
			m_bEnterLock = false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP) == false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN) == false)
			m_bStateLock = false;
		if (g_pFramework->KeyDown(SDL_SCANCODE_ESCAPE) == false)
			m_bEscapeLock = false;


		switch (m_State)
		{
		case (1) :
		{
					 m_pMenubuttons->SetPos(361, 274);
					 m_pMenubuttons->Render(0, 1);
					 m_pTextMenutext->SetColor(255, 255, 255);
					 m_pTextMenutext->SetContent("Fortsetzen");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 274));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 354);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Speichern");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 354));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 434);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Beenden");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 434));
					 m_pTextMenutext->Render();

		} break;

		case (2) :
		{
					 m_pMenubuttons->SetPos(361, 274);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Fortsetzen");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 274));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 354);
					 m_pMenubuttons->Render(0, 1);
					 m_pTextMenutext->SetColor(255, 255, 255);
					 m_pTextMenutext->SetContent("Speichern");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 354));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 434);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Beenden");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 434));
					 m_pTextMenutext->Render();

		} break;
		case (3) :
		{
					 m_pMenubuttons->SetPos(361, 274);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Fortsetzen");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 274));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 354);
					 m_pMenubuttons->Render(0, 0);
					 m_pTextMenutext->SetColor(180, 180, 180);
					 m_pTextMenutext->SetContent("Speichern");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 354));
					 m_pTextMenutext->Render();

					 m_pMenubuttons->SetPos(361, 434);
					 m_pMenubuttons->Render(0, 1);
					 m_pTextMenutext->SetColor(255, 255, 255);
					 m_pTextMenutext->SetContent("Beenden");
					 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
						 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 434));
					 m_pTextMenutext->Render();
		} break;

		}

		g_pFramework->Render();

		SDL_EventState(SDL_SYSWMEVENT, SDL_IGNORE);
		SDL_WaitEvent(&event);

		switch (m_State)
		{
		case (1) :
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



		case (2) :
		{
					 switch (event.key.keysym.sym)
					 {
					 case (SDL_SCANCODE_RETURN) :
					 {
													if (m_bEnterLock == false)
													{
														m_bEnterLock = true;
														m_State2 = 1;
														m_bBreakLock2 = false;
														m_pMenubackground->SetPos(134, 99);
														m_pMenubackground->Render(0);
														m_pTextMenuSave->SetColor(230, 230, 0);
														m_pTextMenuSave->SetContent("Soll wirklich gespeichert werden?");
														m_pTextMenucaption->SetPos(((755 - m_pTextMenuSave->Get_length()) / 2 + 134), 240);
														m_pTextMenuSave->Render();

														while (m_bBreakLock2 == false)
														{
															if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN) == false)
																m_bEnterLock = false;
															if (g_pFramework->KeyDown(SDL_SCANCODE_UP) == false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN) == false)
																m_bStateLock = false;

															switch (m_State2)
															{
															case(1) :
																m_pMenubuttons->SetPos(361, 304);
																m_pMenubuttons->Render(0, 1);
																m_pTextMenutext->SetColor(255, 255, 255);
																m_pTextMenutext->SetContent("Ja");
																m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
																	static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 304));
																m_pTextMenutext->Render();

																m_pMenubuttons->SetPos(361, 394);
																m_pMenubuttons->Render(0, 0);
																m_pTextMenutext->SetColor(180, 180, 180);
																m_pTextMenutext->SetContent("Nein");
																m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
																	static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
																m_pTextMenutext->Render();
																break;

															case(2) :
																m_pMenubuttons->SetPos(361, 304);
																m_pMenubuttons->Render(0, 0);
																m_pTextMenutext->SetColor(180, 180, 180);
																m_pTextMenutext->SetContent("Ja");
																m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
																	static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 304));
																m_pTextMenutext->Render();

																m_pMenubuttons->SetPos(361, 394);
																m_pMenubuttons->Render(0, 1);
																m_pTextMenutext->SetColor(255, 255, 255);
																m_pTextMenutext->SetContent("Nein");
																m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
																	static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
																m_pTextMenutext->Render();
																break;
															}
															g_pFramework->Render();

															SDL_WaitEvent(&event);
															switch (m_State2)
															{
															case (1) :
															{
																		 switch (event.key.keysym.sym)
																		 {
																		 case (SDL_SCANCODE_RETURN) :
																			 if (m_bEnterLock == false)
																			 {
																				 Save();
																				 m_bBreakLock2 = true;
																				 m_bEnterLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_DOWN) :
																			 if (m_bStateLock == false)
																			 {
																				 m_State2 = 2;
																				 m_bStateLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_UP) :
																			 if (m_bStateLock == false)
																			 {
																				 m_State2 = 2;
																				 m_bStateLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_ESCAPE) :
																			 if (m_bEscapeLock == false)
																			 {
																				 m_bBreakLock2 = true;
																				 m_bEscapeLock = true;
																			 }
																			 break;
																		 }
															} break;
															case (2) :
															{
																		 switch (event.key.keysym.sym)
																		 {
																		 case (SDL_SCANCODE_RETURN) :
																			 if (m_bEnterLock == false)
																			 {
																				 m_bBreakLock2 = true;
																				 m_bEnterLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_DOWN) :
																			 if (m_bStateLock == false)
																			 {
																				 m_State2 = 1;
																				 m_bStateLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_UP) :
																			 if (m_bStateLock == false)
																			 {
																				 m_State2 = 1;
																				 m_bStateLock = true;
																			 }
																			 break;
																		 case (SDL_SCANCODE_ESCAPE) :
																			 if (m_bEscapeLock == false)
																			 {
																				 m_bBreakLock2 = true;
																				 m_bEscapeLock = true;
																			 }
																			 break;
																		 }
															} break;
															}
														}
													}
					 } break;
					 case (SDL_SCANCODE_DOWN) :
					 {
												  if (m_bStateLock == false)
												  {
													  m_State = 3;
													  m_bStateLock = true;
												  }
					 } break;

					 case (SDL_SCANCODE_UP) :
					 {
												if (m_bStateLock == false)
												{
													m_State = 1;
													m_bStateLock = true;
												}
					 } break;

					 case (SDL_SCANCODE_ESCAPE) :
					 {
													if (m_bEscapeLock == false)
														m_bBreakLock = true;
					 } break;
					 }
		} break;

		case (3) :
		{
					 switch (event.key.keysym.sym)
					 {
					 case (SDL_SCANCODE_RETURN) :
						 if (m_bEnterLock == false)
						 {
							 m_bEnterLock = true;
							 m_State2 = 1;
							 m_bBreakLock2 = false;
							 m_pMenubackground->SetPos(134, 99);
							 m_pMenubackground->Render(0);
							 m_pTextMenuSave->SetColor(230, 230, 0);
							 m_pTextMenuSave->SetContent("Soll wirklich beendet werden?");
							 m_pTextMenucaption->SetPos(((755 - m_pTextMenuSave->Get_length()) / 2 + 134), 240);
							 m_pTextMenuSave->Render();

							 while (m_bBreakLock2 == false)
							 {
								 if (g_pFramework->KeyDown(SDL_SCANCODE_RETURN) == false)
									 m_bEnterLock = false;
								 if (g_pFramework->KeyDown(SDL_SCANCODE_UP) == false && g_pFramework->KeyDown(SDL_SCANCODE_DOWN) == false)
									 m_bStateLock = false;

								 switch (m_State2)
								 {
								 case(1) :
									 m_pMenubuttons->SetPos(361, 304);
									 m_pMenubuttons->Render(0, 1);
									 m_pTextMenutext->SetColor(255, 255, 255);
									 m_pTextMenutext->SetContent("Ja");
									 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
										 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 304));
									 m_pTextMenutext->Render();

									 m_pMenubuttons->SetPos(361, 394);
									 m_pMenubuttons->Render(0, 0);
									 m_pTextMenutext->SetColor(180, 180, 180);
									 m_pTextMenutext->SetContent("Nein");
									 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
										 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
									 m_pTextMenutext->Render();
									 break;

								 case(2) :
									 m_pMenubuttons->SetPos(361, 304);
									 m_pMenubuttons->Render(0, 0);
									 m_pTextMenutext->SetColor(180, 180, 180);
									 m_pTextMenutext->SetContent("Ja");
									 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
										 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 304));
									 m_pTextMenutext->Render();

									 m_pMenubuttons->SetPos(361, 394);
									 m_pMenubuttons->Render(0, 1);
									 m_pTextMenutext->SetColor(255, 255, 255);
									 m_pTextMenutext->SetContent("Nein");
									 m_pTextMenucaption->SetPos(static_cast<float>((301 - m_pTextMenutext->Get_length()) / 2 + 361),
										 static_cast<float>((65 - m_pTextMenutext->Get_height()) / 2 + 394));
									 m_pTextMenutext->Render();
									 break;
								 }
								 g_pFramework->Render();

								 SDL_WaitEvent(&event);
								 switch (m_State2)
								 {
								 case (1) :
								 {
											  switch (event.key.keysym.sym)
											  {
											  case (SDL_SCANCODE_RETURN) :
												  if (m_bEnterLock == false)
												  {
													  SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
													  m_bBreakLock = true;
													  m_bGameRun = false;
													  m_bBreakLock2 = true;
													  m_bEnterLock = true;
													  pTrack_1->PauseMusic();
												  }
												  break;
											  case (SDL_SCANCODE_DOWN) :
												  if (m_bStateLock == false)
												  {
													  m_State2 = 2;
													  m_bStateLock = true;
												  }
												  break;
											  case (SDL_SCANCODE_UP) :
												  if (m_bStateLock == false)
												  {
													  m_State2 = 2;
													  m_bStateLock = true;
												  }
												  break;
											  case (SDL_SCANCODE_ESCAPE) :
												  if (m_bEscapeLock == false)
												  {
													  m_bBreakLock2 = true;
													  m_bEscapeLock = true;
												  }
												  break;
											  }
								 } break;
								 case (2) :
								 {
											  switch (event.key.keysym.sym)
											  {
											  case (SDL_SCANCODE_RETURN) :
												  if (m_bEnterLock == false)
												  {
													  m_bBreakLock2 = true;
													  m_bEnterLock = true;
												  }
												  break;
											  case (SDL_SCANCODE_DOWN) :
												  if (m_bStateLock == false)
												  {
													  m_State2 = 1;
													  m_bStateLock = true;
												  }
												  break;
											  case (SDL_SCANCODE_UP) :
												  if (m_bStateLock == false)
												  {
													  m_State2 = 1;
													  m_bStateLock = true;
												  }
												  break;
											  case (SDL_SCANCODE_ESCAPE) :
												  if (m_bEscapeLock == false)
												  {
													  m_bBreakLock2 = true;
													  m_bEscapeLock = true;
												  }
												  break;
											  }
								 } break;
								 }
							 }
						 }
						 break;
					 case (SDL_SCANCODE_DOWN) :
					 {
												  if (m_bStateLock == false)
												  {
													  m_State = 1;
													  m_bStateLock = true;
												  }
					 } break;

					 case (SDL_SCANCODE_UP) :
					 {
												if (m_bStateLock == false)
												{
													m_State = 2;
													m_bStateLock = true;
												}
					 } break;

					 case (SDL_SCANCODE_ESCAPE) :
					 {
													if (m_bEscapeLock == false)
														m_bBreakLock = true;
					 } break;
					 }
		} break;
		}
		g_pFramework->Update();
	}*/
}