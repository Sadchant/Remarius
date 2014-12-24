#include "Stuff.hpp"


CStuff::CStuff ()														// Player und Stuffprites laden
{
	m_pPlayer = NULL;																						// Spieler erzeugen
	m_pPlayer = new CPlayer;
	m_pPlayer->Reset ();

	m_pSpriteStachelstein = NULL;																				// Stachelsteinensprite erzeugen
	m_pSpriteStachelstein = new CSprite(g_pLoader->GetTexture(STACELSTONE),ENTITY_LAYER, 64, 44);

	m_pSpriteHoover = NULL;																				// Staubsaugersprite erzeugen
	m_pSpriteHoover = new CSprite(g_pLoader->GetTexture(SPIDER), ENTITY_LAYER, 130, 97);

	m_pSpriteBombo = NULL;																				// Bombosprite erzeugen
	m_pSpriteBombo = new CSprite(g_pLoader->GetTexture(BOMBO), ENTITY_LAYER, 86, 90);

	m_pSpriteExplosion = NULL;																				// Bombosprite erzeugen
	m_pSpriteExplosion = new CSprite(g_pLoader->GetTexture(EXPLOSION), ENTITY_LAYER, 240, 240);

	m_pSpriteSpider = NULL;																				// Hexaspidersprite erzeugen
	m_pSpriteSpider = new CSprite(g_pLoader->GetTexture(SPIDER), ENTITY_LAYER, 130, 97);


	/*m_pSpriteTile = NULL;
	m_pSpriteTile = new CSpriteObject(g_pLoader->GetTexture(TEXTURSET1), TILE_LAYER1, 45, 45, 49284);*/

	m_pSpriteWall=NULL;
	m_pSpriteWall = new CSprite(g_pLoader->GetTexture(WALL), TILE_LAYER2, 45, 45);

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
void CStuff::Quit ()																								// M�ll freigeben
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
	m_pPlayer->Render((float)m_pCamera->GetCameraRect().x, (float)m_pCamera->GetCameraRect().y);
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
		Hoover.Init(m_pSpriteHoover);
		m_HooverList.push_back (Hoover);
		m_bSpawnLock = true;
		g_pDebugscreen->Set("Hoover gespawnt");
	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_B) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zuf�llige Position
		int YPos = rand()%600;
		CBombo Bombo(m_pSpriteBombo, static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_BomboList.push_back (Bombo);
		m_bSpawnLock = true;

	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_Y) && m_bSpawnLock == false)
	{
		int XPos = rand()%800;																		// Zuf�llige Position
		int YPos = rand()%600;
		CStachelstein Stachelstein(m_pSpriteStachelstein, static_cast<float>(XPos), static_cast<float>(YPos));	// Neuer Stachelstein
		m_StachelsteinList.push_back (Stachelstein);														// Stachelstein in Liste einf�gen
		m_bSpawnLock = true;
	}
	if (g_pFramework->KeyDown(SDL_SCANCODE_P) && m_bSpawnLock == false)
	{
		int XPos = rand()%1024;																		// Zuf�llige Position
		int YPos = rand()%768;
		CSpider Spider(m_pSpriteSpider, static_cast<float>(XPos), static_cast<float>(YPos), m_pPlayer->pGetX(), m_pPlayer->pGetY());
		m_SpiderList.push_back (Spider);														// Spider in Liste einf�gen
		m_bSpawnLock = true;
	}
	if (!g_pFramework->KeyDown(SDL_SCANCODE_Y) && !g_pFramework->KeyDown(SDL_SCANCODE_H) && !g_pFramework->KeyDown(SDL_SCANCODE_B) && !g_pFramework->KeyDown(SDL_SCANCODE_P))
		m_bSpawnLock = false;
}
void CStuff::CheckCollisions ()																					// Kollisionen pr�fen
{
	list<CExplosion>::iterator ItExpl;
	list<CShot> *ShotList = m_pPlayer->GetShotList();
	list<CShot>::iterator ItShot;
	// Liste f�r Terrainobjekte laden

	list<CBombo>::iterator ItBombo = m_BomboList.begin();
	list<CSpider>::iterator ItSpid = m_SpiderList.begin();
	list<CStachelstein>::iterator ItStac = m_StachelsteinList.begin();
	// F�r weitere Monsterlisten Iteratoren erzeugen und auf Start setzen

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
	list<CStachelstein>::iterator It;																	// Iterator f�r die Monster-Liste
	for (It = m_StachelsteinList.begin (); It != m_StachelsteinList.end (); ++It)							// Monster-Liste durchlaufen
	{
		It->Render (m_pCamera->GetCameraRect().x, m_pCamera->GetCameraRect().y);																				// Monster rendern und updaten
		It->Update ();
	}

	list<CHoover>::iterator ItH;
	for (ItH = m_HooverList.begin(); ItH != m_HooverList.end(); ItH++)
	{
		ItH->Render((float)m_pCamera->GetCameraRect().x, (float)m_pCamera->GetCameraRect().y);
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
	   ItE->Render((float)m_pCamera->GetCameraRect().x, (float)m_pCamera->GetCameraRect().y);
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
    
    ifstream map( "Map/Map1x1.map" );
    
    if(!map.is_open())
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
    }
	map.close();
 
    map.open( "Map/Map1x2.map" );
	if (map.is_open())
    {
		int TileAmount;
        int x,y,type;
                
        map>>TileAmount;
 
        for(int i=0; i<TileAmount;i++)
        {
			map>>type;
			map>>x;
            map>>y;
            CTile Tile(x,y,type);
            tiles2.push_back(Tile);
        }
	}
	map.close();
 
	map.open( "Map/Map1x3.map" );
	if (map.is_open())
	{
		int TileAmount;
		int x,y,type;
                
		map>>TileAmount;
 
		for(int i=0; i<TileAmount;i++)
		{
			map>>type;
			map>>x;
			map>>y;
			CTile Tile(x,y,type);
			tiles3.push_back(Tile);
		}
	}
	map.close();
 
	map.open( "Map/Map1x4.map" );
	if (map.is_open())
	{
		int TileAmount;
		int x,y,type;
                
		map>>TileAmount;
 
		for(int i=0; i<TileAmount;i++)
		{
			map>>type;
			map>>x;
			map>>y;
			CTile Tile(x,y,type);
			tiles4.push_back(Tile);
		}
    }
	map.close();    
    return true;
}

void CStuff::show()
{
        /*int type;
        for (int t = 0; t < TOTAL_TILES; t++ )
		{
                type=(tiles[t]->get_type());
                if( CkRect( m_pCamera->GetCameraRect(), tiles[t]->GetRect() ) == true )
                {
					m_pSpriteTile->SetPos(t, tiles[t]->GetRect().x - m_pCamera->GetCameraRect().x, tiles[t]->GetRect().y - m_pCamera->GetCameraRect().y);
					m_pSpriteTile->Render(t, static_cast<float>(type%4),static_cast<int>(type/4));
                }
        }
 
		list <CTile>::iterator ItTile2;
        for (ItTile2=tiles2.begin(); ItTile2!=tiles2.end(); ItTile2++ )
        {
                type =ItTile2->get_type();
				m_pSpriteTile->SetPos(ItTile2->GetRect().x - m_pCamera->GetCameraRect().x, ItTile2->GetRect().y - m_pCamera->GetCameraRect().y);
                m_pSpriteTile->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }
 
        list <CTile>::iterator ItTile3;
        for (ItTile3=tiles3.begin(); ItTile3!=tiles3.end(); ItTile3++ )
        {
                type =ItTile3->get_type();
				m_pSpriteTile->SetPos(ItTile3->GetRect().x - m_pCamera->GetCameraRect().x, ItTile3->GetRect().y - m_pCamera->GetCameraRect().y);
                m_pSpriteTile->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }
		list <CTile>::iterator ItTile4;
        for (ItTile4=tiles4.begin(); ItTile4!=tiles4.end(); ItTile4++ )
        {
                type =ItTile4->get_type();
				m_pSpriteWall->SetPos(ItTile4->GetRect().x - m_pCamera->GetCameraRect().x, ItTile4->GetRect().y - m_pCamera->GetCameraRect().y);
                m_pSpriteWall->Render(static_cast<float>(type%4),static_cast<int>(type/4));
        }*/
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