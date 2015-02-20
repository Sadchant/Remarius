#include "Stuff.hpp"
#include <windows.h>



CStuff::CStuff ()														// Player und Stuffprites laden
{	
	m_pPlayer = NULL;																						// Spieler erzeugen
	m_pPlayer = new CPlayer;
	m_pPlayer->Reset ();

	m_pSpriteStachelstein = NULL;																				// Stachelsteinensprite erzeugen
	m_pSpriteStachelstein = new CSprite(g_pLoader->getTexture("T_STACELSTONE"));

	m_pSpriteHoover = NULL;																				// Staubsaugersprite erzeugen
	m_pSpriteHoover = new CSprite(g_pLoader->getTexture("T_SPIDER"));

	m_pSpriteBombo = NULL;																				// Bombosprite erzeugen
	m_pSpriteBombo = new CSprite(g_pLoader->getTexture("T_BOMBO"));

	m_pSpriteExplosion = NULL;																				// Bombosprite erzeugen
	m_pSpriteExplosion = new CSprite(g_pLoader->getTexture("T_EXPLOSION"));

	m_pSpriteSpider = NULL;																				// Hexaspidersprite erzeugen
	m_pSpriteSpider = new CSprite(g_pLoader->getTexture("T_SPIDER"));

	m_bSpawnLock = false;	
        
}

void CStuff::init(fSDL_Rect *camera, int level_width, int level_height) // da der Konstruktor in der Initialisierungsliste zu einem unerwünschten Zeitpunkt aufgerufen wird...
{
	this->camera = camera;
	this->level_width = level_width;
	this->level_height = level_height;
	m_pPlayer->Set_Map(level_width, level_height);
}
void CStuff::Quit ()																								// Müll freigeben
{
	 if (m_pPlayer != NULL)																				// Spieler freigeben
	{
		m_pPlayer->Quit ();
		delete (m_pPlayer);
		m_pPlayer = NULL ;
	}
}

void CStuff::Update()
{
	m_pPlayer->Update();
	camera->x = m_pPlayer->GetX() - ((float)camera->w / 2);
	camera->y = m_pPlayer->GetY() - ((float)camera->h / 2);
	

	if (camera->x < 0)
		camera->x = 0;
	if (camera->y < 0)
		camera->y = 0;

	if (camera->x > level_width - camera->w)
		camera->x = level_width - camera->w;
	if (camera->y > level_height - camera->h)
		camera->y = level_height - camera->h;

	m_pPlayer->Render(camera->x, camera->y);
	m_pPlayer->LifeRender();

	list<CExplosion>::iterator ItEx = m_ExplosionList.begin();
	while (ItEx != m_ExplosionList.end())
		if (ItEx->IsAlive())
			ItEx++;
		else ItEx = m_ExplosionList.erase(ItEx);

	CommandSpawns();
	CheckCollisions();
	RenderMonsters();

}
void CStuff::SetPlayer(int Life, float X, float Y)
{
	m_pPlayer->SetLife(Life);
	m_pPlayer->Set_x(X);
	m_pPlayer->Set_y(Y);
}
void CStuff::CommandSpawns()																					// Per Tastendruck Monster erzeugen
{
	if (g_pFramework->KeyDown(SDL_SCANCODE_H) && m_bSpawnLock == false)
	{
		CHoover Hoover;
		Hoover.Init();
		m_HooverList.push_back (Hoover);
		m_bSpawnLock = true;
		g_pDebugscreen->Set("Hoover gespawnt");
	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_B) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zufällige Position
		int YPos = rand()%600;
		CBombo Bombo(static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_BomboList.push_back (Bombo);
		m_bSpawnLock = true;

	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_Y) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zufällige Position
		int YPos = rand()%600;
		CStachelstein Stachelstein(static_cast<float>(XPos), static_cast<float>(YPos));	// Neuer Stachelstein
		m_StachelsteinList.push_back (Stachelstein);														// Stachelstein in Liste einfügen
		m_bSpawnLock = true;
	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_P) && m_bSpawnLock == false)
	{
		int XPos = rand()%1024;																		// Zufällige Position
		int YPos = rand()%768;
		CSpider Spider(static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_SpiderList.push_back (Spider);														// Spider in Liste einfügen
		m_bSpawnLock = true;
	}
	if (!g_pFramework->KeyDown(SDL_SCANCODE_Y) && !g_pFramework->KeyDown(SDL_SCANCODE_H) && !g_pFramework->KeyDown(SDL_SCANCODE_B) && !g_pFramework->KeyDown(SDL_SCANCODE_P))
		m_bSpawnLock = false;
}
void CStuff::CheckCollisions ()																					// Kollisionen prüfen
{
	list<CExplosion>::iterator ItExpl;
	list<CShot> *ShotList = m_pPlayer->GetShotList();
	list<CShot>::iterator ItShot;
	// Liste für Terrainobjekte laden

	list<CBombo>::iterator ItBombo = m_BomboList.begin();
	list<CSpider>::iterator ItSpid = m_SpiderList.begin();
	list<CStachelstein>::iterator ItStac = m_StachelsteinList.begin();
	// Für weitere Monsterlisten Iteratoren erzeugen und auf Start setzen

	// Player
	for (ItExpl = m_ExplosionList.begin(); ItExpl != m_ExplosionList.end(); ItExpl++)
		if (CkRect(m_pPlayer->GetRect(), ItExpl->GetRect()))
			m_pPlayer->DoDamage(ItExpl->GetX(), ItExpl->GetY(), 5);
	// Terrain durchforsten
	// Player

	// Bombos
	while (ItBombo != m_BomboList.end())
	{
		for (ItExpl = m_ExplosionList.begin(); ItExpl != m_ExplosionList.end(); ItExpl++)
			if (CkRect(ItBombo->GetRect(), ItExpl->GetRect()))
				ItBombo->DoDamage(ItExpl->GetX(), ItExpl->GetY(), 5);
		for (ItShot = ShotList->begin(); ItShot != ShotList->end(); ItShot++)
			if (CkRect(ItBombo->GetRect(), ItShot->GetRect()))
			{
				ItBombo->DoDamage(0.5f, 1);
				ItShot->SetAlive(false);
			}
		if (m_pPlayer->IsAttack())
			if (CkRect(m_pPlayer->GetAttackRect(), ItBombo->GetRect()))
				ItBombo->DoDamage(m_pPlayer->GetX(), m_pPlayer->GetY(), 2);
		if (ItBombo->GetMode() == 5)
		{
			ItBombo->SetAlive(false);
			CExplosion Explosion(static_cast<int>(ItBombo->GetX()-77.0f), static_cast<int>(ItBombo->GetY()-75.0f));
			m_ExplosionList.push_back(Explosion);
		}
		if (ItBombo->IsAlive())
			ItBombo++;
		else ItBombo = m_BomboList.erase(ItBombo);
	}
	// Bombos

	// Stachelsteine
	while (ItStac != m_StachelsteinList.end())
	{
		for (ItExpl = m_ExplosionList.begin(); ItExpl != m_ExplosionList.end(); ItExpl++)
			if (CkRect(ItStac->GetRect(), ItExpl->GetRect()))
				ItStac->DoDamage(ItExpl->GetX(), ItExpl->GetY(), 5);
		for (ItShot = ShotList->begin(); ItShot != ShotList->end(); ItShot++)
			if (CkRect(ItStac->GetRect(), ItShot->GetRect()))
			{
				ItStac->DoDamage(0.5f, 1);
				ItShot->SetAlive(false);
			}
		if (m_pPlayer->IsAttack())
			if (CkRect(m_pPlayer->GetAttackRect(), ItStac->GetRect()))
				ItStac->DoDamage(m_pPlayer->GetX(), m_pPlayer->GetY(), 2);
		if (ItStac->IsAlive())
			ItStac++;
		else ItStac = m_StachelsteinList.erase(ItStac);
	}
	// Stachelsteine

	// Hexaspiders
	while (ItSpid != m_SpiderList.end())
	{
		for (ItExpl = m_ExplosionList.begin(); ItExpl != m_ExplosionList.end(); ItExpl++)
			if (CkRect(ItSpid->GetRect(), ItExpl->GetRect()))
				ItSpid->DoDamage(ItExpl->GetX(), ItExpl->GetY(), 5);
		for (ItShot = ShotList->begin(); ItShot != ShotList->end(); ItShot++)
			if (CkRect(ItSpid->GetRect(), ItShot->GetRect()))
			{
				ItSpid->DoDamage(0.5f, 1);
				ItShot->SetAlive(false);
			}
		if (m_pPlayer->IsAttack())
			if (CkRect(m_pPlayer->GetAttackRect(), ItSpid->GetRect()))
				ItSpid->DoDamage(m_pPlayer->GetX(), m_pPlayer->GetY(), 2);
		if (ItSpid->IsAlive())
			ItSpid++;
		else ItSpid = m_SpiderList.erase(ItSpid);
	}
	// Hexaspiders

	/*list <CTile>::iterator ItTile4;
	for (ItTile4=tiles4.begin(); ItTile4!=tiles4.end(); ItTile4++)
	{
		if (CkRect(ItTile4->GetRect(), m_pPlayer->GetRect())==true)
		{
			m_pPlayer->ProcessMoving(-255.0f);
		}
	}*/

}
void CStuff::RenderMonsters ()																			// Monster rendern und updaten	
{
	list<CStachelstein>::iterator It;																	// Iterator für die Monster-Liste
	for (It = m_StachelsteinList.begin (); It != m_StachelsteinList.end (); ++It)							// Monster-Liste durchlaufen
	{
		It->Render (camera->x, camera->y);																				// Monster rendern und updaten
		It->Update ();
	}

	list<CHoover>::iterator ItH;
	for (ItH = m_HooverList.begin(); ItH != m_HooverList.end(); ItH++)
	{
		ItH->Render(camera->x, camera->y);
		ItH->Update();
	}

	list<CBombo>::iterator ItB;
   for (ItB = m_BomboList.begin(); ItB != m_BomboList.end(); ItB++)
   {
	   ItB->Render(camera->x, camera->y);
      ItB->Update();
   }

   list<CExplosion>::iterator ItE;
   for (ItE = m_ExplosionList.begin(); ItE != m_ExplosionList.end(); ItE++)
   {
	   ItE->Render(camera->x, camera->y);
   }
   list<CSpider>::iterator ItS;
   for (ItS = m_SpiderList.begin(); ItS != m_SpiderList.end(); ItS++)
   {
	   ItS->Render(camera->x, camera->y);
	   ItS->Update();
   }
} 

bool CStuff::CkRect(SDL_Rect a, SDL_Rect b)
{
	if (a.y < (b.y + b.h) &&
		(a.y + a.h) > b.y &&
		a.x < (b.x + b.w) &&
		(a.x + a.w) > b.x)
		return true;
	else return false;
}
//aktuelle Version