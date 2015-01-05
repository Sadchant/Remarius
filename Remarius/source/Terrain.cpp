#include "Terrain.hpp"

bool CTerrain::Set_tiles()
{
	int x = 0, y = 0;

	ifstream map("Map/Map1x1.map");

	if (!map.is_open()) //sollte es einen Fehler beim Laden gegeben haben
	{
		for (int t = 0; t < TOTAL_TILES; t++)
		{
			tiles[t] = new CTile(x, y, rand() % 4);

			x += TILE_WIDTH;

			if (x >= LEVEL_WIDTH)
			{
				x = 0;
				y += TILE_HEIGHT;
			}
		}
	}
	else
	{
		for (int t = 0; t < TOTAL_TILES; t++)
		{
			int tileType = -1;

			map >> tileType;

			if ((tileType >= 0) && (tileType < TILE_SPRITES))
			{
				tiles[t] = new CTile(x, y, tileType);
			}
			else
			{
				map.close();
				return false;
			}

			x += TILE_WIDTH;

			if (x >= LEVEL_WIDTH)
			{
				x = 0;

				y += TILE_HEIGHT;
			}
		}
	}
	map.close();

	map.open("Map/Map1x2.map");
	if (map.is_open())
	{
		int TileAmount;
		int x, y, type;

		map >> TileAmount;

		for (int i = 0; i<TileAmount; i++)
		{
			map >> type;
			map >> x;
			map >> y;
			CTile Tile(x, y, type);
			tiles2.push_back(Tile);
		}
	}
	map.close();

	map.open("Map/Map1x3.map");
	if (map.is_open())
	{
		int TileAmount;
		int x, y, type;

		map >> TileAmount;

		for (int i = 0; i<TileAmount; i++)
		{
			map >> type;
			map >> x;
			map >> y;
			CTile Tile(x, y, type);
			tiles3.push_back(Tile);
		}
	}
	map.close();

	map.open("Map/Map1x4.map");
	if (map.is_open())
	{
		int TileAmount;
		int x, y, type;

		map >> TileAmount;

		for (int i = 0; i<TileAmount; i++)
		{
			map >> type;
			map >> x;
			map >> y;
			CTile Tile(x, y, type);
			tiles4.push_back(Tile);
		}
	}
	map.close();
	return true;
}

void CTerrain::RenderTiles()
{
	//Sleep(300);
	int type;
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		type = (tiles[t]->get_type());
		//if( CkRect( m_pCamera->GetCameraRect(), tiles[t]->GetRect() ) == true )
		//{
		spriteTile->SetPos(t, tiles[t]->GetRect().x - m_pCamera->GetCameraRect().x, tiles[t]->GetRect().y - m_pCamera->GetCameraRect().y);
		spriteTile->Render(t, type % 4, static_cast<int>(type / 4));
		//}
	}

	/*list <CTile>::iterator ItTile2;
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
