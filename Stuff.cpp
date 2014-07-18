#include "Stuff.hpp"


CStuff::CStuff ()														// Player und Stuffprites laden
{
	m_pPlayer = NULL;																						// Spieler erzeugen
	m_pPlayer = new CPlayer;
	m_pPlayer->Reset ();

	m_pSpriteStachelstein = NULL;																				// Stachelsteinensprite erzeugen
	m_pSpriteStachelstein = new CSprite;
	m_pSpriteStachelstein->Load ("Data/Stacelstone.png", 0, 64, 44);

	m_pSpriteHoover = NULL;																				// Staubsaugersprite erzeugen
	m_pSpriteHoover = new CSprite;
	m_pSpriteHoover->Load ("Data/Spider.png", 7, 130, 97);

	m_pSpriteBombo = NULL;																				// Bombosprite erzeugen
	m_pSpriteBombo = new CSprite;
	m_pSpriteBombo->Load ("Data/RoterSlime.png", 4, 86, 90);

	m_pSpriteExplosion = NULL;																				// Bombosprite erzeugen
	m_pSpriteExplosion = new CSprite;
	m_pSpriteExplosion->Load ("Data/Explosion.bmp", 10, 240, 240);

	m_pSpriteSpider = NULL;																				// Hexaspidersprite erzeugen
	m_pSpriteSpider = new CSprite;
	m_pSpriteSpider->Load ("Data/Spider.png", 7, 130, 97);


	m_pSpriteTile = NULL;
	m_pSpriteTile = new CSprite;
	m_pSpriteTile->Load("Data/Texturset1.png", 4, 45, 45);

	m_pSpriteWall=NULL;
	m_pSpriteWall = new CSprite;
    m_pSpriteWall->Load("Data/Wall.png", 0, 45, 45);

	m_pCamera = NULL;
	m_pCamera = new CCamera;

	m_bSpawnLock = false;

	m_pPlayer->Set_Map(LEVEL_WIDTH,LEVEL_HEIGHT);
        
    for( int t = 0; t < TOTAL_TILES; t++ )
    {
       tiles[t]=NULL;
    }
    set_tiles();
}
void CStuff::Quit ()																								// Müll freigeben
{
	 if (m_pPlayer != NULL)																				// Spieler freigeben
	{
		m_pPlayer->Quit ();
		delete (m_pPlayer);
		m_pPlayer = NULL ;
	}

	if (m_pSpriteStachelstein != NULL)																		// Stachelsteinensprite freigeben
	{
		delete (m_pSpriteStachelstein);
		m_pSpriteStachelstein = NULL;
	}

	if (m_pSpriteHoover != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pSpriteHoover);
		m_pSpriteHoover = NULL;
	}

	if (m_pSpriteBombo != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pSpriteBombo);
		m_pSpriteBombo = NULL;
	}

	if (m_pSpriteSpider != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pSpriteSpider);
		m_pSpriteSpider = NULL;
	}

	if (m_pSpriteExplosion != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pSpriteExplosion);
		m_pSpriteExplosion = NULL;
	}
	
	if (m_pSpriteTile != NULL)
    {
       delete (m_pSpriteTile);
       m_pSpriteTile = NULL;
    }
	if (m_pCamera != NULL)																			// Staubsaugersprite freigeben
	{
		delete (m_pCamera);
		m_pCamera = NULL;
	}
	
 
    for( int t = 0; t < TOTAL_TILES; t++ )
    {
		delete tiles[ t ];    
    }
 
	tiles2.clear();
	tiles3.clear();
	tiles4.clear();
}

void CStuff::Update()
{
	m_pPlayer->Update();
	m_pCamera->SetPos (static_cast<float>(m_pPlayer->GetX()) - 512, static_cast<float>(m_pPlayer->GetY()) - 384);
	m_pCamera->CorrectPos (LEVEL_WIDTH, LEVEL_HEIGHT);
	show();
	m_pPlayer->Render(m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);
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
	if (g_pFramework->KeyDown(SDLK_h) && m_bSpawnLock == false)
	{
		CHoover Hoover;
		Hoover.Init(m_pSpriteHoover);
		m_HooverList.push_back (Hoover);
		m_bSpawnLock = true;

	}
	if (g_pFramework->KeyDown(SDLK_b) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zufällige Position
		int YPos = rand()%600;
		CBombo Bombo(m_pSpriteBombo, static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_BomboList.push_back (Bombo);
		m_bSpawnLock = true;

	}
	if (g_pFramework->KeyDown(SDLK_y) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zufällige Position
		int YPos = rand()%600;
		CStachelstein Stachelstein(m_pSpriteStachelstein, static_cast<float>(XPos), static_cast<float>(YPos));	// Neuer Stachelstein
		m_StachelsteinList.push_back (Stachelstein);														// Stachelstein in Liste einfügen
		m_bSpawnLock = true;
	}
	if (g_pFramework->KeyDown(SDLK_p) && m_bSpawnLock == false)
	{
		int XPos = rand()%1024;																		// Zufällige Position
		int YPos = rand()%768;
		CSpider Spider(m_pSpriteSpider, static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_SpiderList.push_back (Spider);														// Spider in Liste einfügen
		m_bSpawnLock = true;
	}
	if (!g_pFramework->KeyDown(SDLK_y) && !g_pFramework->KeyDown(SDLK_h) && !g_pFramework->KeyDown(SDLK_b) && !g_pFramework->KeyDown(SDLK_p))
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
			CExplosion Explosion(m_pSpriteExplosion, static_cast<int>(ItBombo->GetX()-77.0f), static_cast<int>(ItBombo->GetY()-75.0f));
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

	list <CTile>::iterator ItTile4;
	for (ItTile4=tiles4.begin(); ItTile4!=tiles4.end(); ItTile4++)
	{
		if (CkRect(ItTile4->GetRect(), m_pPlayer->GetRect())==true)
		{
			m_pPlayer->ProcessMoving(-255.0f);
		}
	}

}
void CStuff::RenderMonsters ()																			// Monster rendern und updaten	
{
	list<CStachelstein>::iterator It;																	// Iterator für die Monster-Liste
	for (It = m_StachelsteinList.begin (); It != m_StachelsteinList.end (); ++It)							// Monster-Liste durchlaufen
	{
		It->Render (m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);																				// Monster rendern und updaten
		It->Update ();
	}

	list<CHoover>::iterator ItH;
	for (ItH = m_HooverList.begin(); ItH != m_HooverList.end(); ItH++)
	{
		ItH->Render(m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);
		ItH->Update();
	}

	list<CBombo>::iterator ItB;
   for (ItB = m_BomboList.begin(); ItB != m_BomboList.end(); ItB++)
   {
      ItB->Render(m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);
      ItB->Update();
   }

   list<CExplosion>::iterator ItE;
   for (ItE = m_ExplosionList.begin(); ItE != m_ExplosionList.end(); ItE++)
   {
      ItE->Render(m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);
   }
   list<CSpider>::iterator ItS;
   for (ItS = m_SpiderList.begin(); ItS != m_SpiderList.end(); ItS++)
   {
	   ItS->Render(m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);
	   ItS->Update();
   }
}
bool CStuff::set_tiles()
{
    int x = 0, y = 0;
    
    std::ifstream map( "Map/Map1x1.map" );
    
    if(! map == NULL )
    {
        for( int t = 0; t < TOTAL_TILES; t++ )
        {
            tiles[ t ] = new CTile( x, y, rand()%4);
 
            x += TILE_WIDTH;
 
            if( x >= LEVEL_WIDTH )
            {
                x = 0;
 
                y += TILE_HEIGHT;    
            }
        }
    }
    else
    {
        for( int t = 0; t < TOTAL_TILES; t++ )
        {
            int tileType = -1;
 
            map >> tileType;
 
            if( ( tileType >= 0 ) && ( tileType < TILE_SPRITES ) )
            {
                tiles[ t ] = new CTile( x, y, tileType );    
            }
            else 
            {
                map.close();
                return false;
            }
        
            x += TILE_WIDTH;
        
            if( x >= LEVEL_WIDTH )
            {
                x = 0;
            
                y += TILE_HEIGHT;    
            }
        }
    
        map.close();
    }
 
        std::ifstream mapx2( "Map/Map1x2.map" );
        if (!mapx2 != NULL)
        {
                int TileAmount;
                int x,y,type;
                
                mapx2>>TileAmount;
 
                for(int i=0; i<TileAmount;i++)
                {
                        mapx2>>type;
                        mapx2>>x;
                        mapx2>>y;
                        CTile Tile(x,y,type);
                        tiles2.push_back(Tile);
                }
        }
 
        std::ifstream mapx3( "Map/Map1x3.map" );
        if (!mapx3 != NULL)
        {
                int TileAmount;
                int x,y,type;
                
                mapx3>>TileAmount;
 
                for(int i=0; i<TileAmount;i++)
                {
                        mapx3>>type;
                        mapx3>>x;
                        mapx3>>y;
                        CTile Tile(x,y,type);
                        tiles3.push_back(Tile);
                }
        }
 
        std::ifstream mapx4( "Map/Map1x4.map" );
        if (!mapx4 != NULL)
        {
                int TileAmount;
                int x,y,type;
                
                mapx4>>TileAmount;
 
                for(int i=0; i<TileAmount;i++)
                {
                        mapx4>>type;
                        mapx4>>x;
                        mapx4>>y;
                        CTile Tile(x,y,type);
                        tiles4.push_back(Tile);
                }
        }
    
    return true;
}

void CStuff::show()
{
        int type;
        for (int t = 0; t < TOTAL_TILES; t++ )
		{
                type=(tiles[t]->get_type());
 
                if( CkRect( m_pCamera->GetCameraRect(), tiles[t]->GetRect() ) == true )
                {
                        m_pSpriteTile->SetScreenPos(tiles[t]->GetRect().x,tiles[t]->GetRect().y,
                                        m_pCamera->GetCameraRect().x,m_pCamera->GetCameraRect().y);
                        m_pSpriteTile->Render(static_cast<float>(type%4),static_cast<int>(type/4));
                }
        }
 
		list <CTile>::iterator ItTile2;
        for (ItTile2=tiles2.begin(); ItTile2!=tiles2.end(); ItTile2++ )
        {
                type =ItTile2->get_type();
                m_pSpriteTile->SetScreenPos(ItTile2->GetRect().x,ItTile2->GetRect().y,
                                m_pCamera->GetCameraRect().x,m_pCamera->GetCameraRect().y);
                m_pSpriteTile->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }
 
        list <CTile>::iterator ItTile3;
        for (ItTile3=tiles3.begin(); ItTile3!=tiles3.end(); ItTile3++ )
        {
                type =ItTile3->get_type();
                m_pSpriteTile->SetScreenPos(ItTile3->GetRect().x,ItTile3->GetRect().y,
                                m_pCamera->GetCameraRect().x,m_pCamera->GetCameraRect().y);
                m_pSpriteTile->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }
		list <CTile>::iterator ItTile4;
        for (ItTile4=tiles4.begin(); ItTile4!=tiles4.end(); ItTile4++ )
        {
                type =ItTile4->get_type();
                m_pSpriteWall->SetScreenPos(ItTile4->GetRect().x,ItTile4->GetRect().y,
                                m_pCamera->GetCameraRect().x,m_pCamera->GetCameraRect().y);
                m_pSpriteWall->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }
}   

bool CStuff::CkRect(SDL_Rect a, SDL_Rect b)
{
	if (a.y < b.y + b.h &&
		a.y + a.h > b.y &&
		a.x < b.x + b.w &&
		a.x + a.w > b.x)
		return true;
	else return false;
}
//aktuelle Version