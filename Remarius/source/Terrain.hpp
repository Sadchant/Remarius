#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "SpriteObject.hpp"
#include "Tile.hpp"
#include <fstream>
#include <sstream>

class CTerrain
{
public:
	CTerrain(string fileName);
	~CTerrain();
	bool Set_tiles();
	void RenderTiles();
private:
	static const int	TOTAL_TILES = 49284;
	static const int	LEVEL_WIDTH = 9990;
	static const int	LEVEL_HEIGHT = 9990;
	static const int	TILE_SPRITES = 32;
	int tile_width;
	int tile_height;
	CSpriteObject		*spriteTile;
	CTile				*tiles[TOTAL_TILES];
	list <CTile>		tiles2;
	list <CTile>		tiles3;
	list <CTile>		tiles4;
};

#endif