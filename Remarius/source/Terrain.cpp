#include "Terrain.hpp"

CTerrain::CTerrain(string fileName, SDL_Rect* camera)
{
	this->camera = camera;
	ifstream map(fileName);
	if (!map.is_open()) //sollte es einen Fehler beim Laden gegeben haben
	{
		cout << fileName << " konnte nicht geladen werden! (CTerrain::CTerrain())" << endl;
		return;
	}
	map >> numTilesX;
	map >> numTilesY;
	map >> tile_width;
	map >> tile_height;
	numTiles = numTilesX*numTilesY;
	lowerSpriteTile = new CSpriteObject(g_pLoader->getTexture("T_TEXTURSET1"), numTiles);
	//upperSpriteTile = new CSpriteObject(g_pLoader->getTexture("T_TEXTURSET2"), numTiles);

	terrain = new Tiles[numTiles];

	int lowerTileType;
	int upperTileType;
	//for (int i = 0; i < numTiles*2; i++) // einkommentieren, wenn das neue Mapformat fertig ist!


	for (int i = 0; i < numTiles; i++)
	{
		lowerTileType = -1;
		upperTileType = -1;
		map >> lowerTileType;
		//map >> upperTileType; // einkommentieren, wenn das neue Mapformat fertig ist!
		terrain[i] = { lowerTileType, upperTileType };
	}
	map.close();
}

CTerrain::~CTerrain()
{

}

void CTerrain::Render()
{
	//camera->x = 28;
	//camera->y = 28;
	


	for (int i = 0; i < (camera->h / tile_height) + 1; i++) // geht über die Anzahl der Tiles in y-Richtung
	{
		for (int j = 0; j < (camera->w / tile_width) + 2; j++) // geht über die Anzahl der Tiles in x-Richtung, hier + 2, da rundungsfehler ausgefangen werden müssen
		{
			index_1 = (int)(i + camera->y / tile_height);
			index_2 = (int)(j + camera->x / tile_width);
			index = (index_1 * numTilesX) + index_2;
			if (index >= numTiles)
				break;
			temp_x = index_2 * tile_width;
			temp_y = index_1 * tile_height;
			lowerSpriteTile->SetPos(index, temp_x - camera->x, temp_y - camera->y);
			lowerSpriteTile->Render(index, terrain[index].lowerTileType % 4, terrain[index].lowerTileType / 4);
			//upperSpriteTile->SetPos(index, temp_x - camera->x, temp_y - camera->y); // einkommentieren, wenn das neue Mapformat fertig ist!			
			//upperSpriteTile->Render(index, (terrain[index]->lowerTileType) % 4, (terrain[index]->upperTileType) / 4)
			index_1 = -1;
			index_2 = -1;
			index = -1;
			temp_x = -1;
			temp_y = -1;
		}
	}
	/*int type;
	for (int t = 0; t < TOTAL_TILES; t++)
	{
		type = (tiles[t]->get_type());
		//if( CkRect( m_pCamera->GetCameraRect(), tiles[t]->GetRect() ) == true )
		//{
		spriteTile->SetPos(t, tiles[t]->GetRect().x - m_pCamera->GetCameraRect().x, tiles[t]->GetRect().y - m_pCamera->GetCameraRect().y);
		spriteTile->Render(t, type % 4, static_cast<int>(type / 4));
		//}
	}*/
}
