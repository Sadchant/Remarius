#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "SpriteObject.hpp"
#include <fstream>
#include <sstream>

class CTerrain
{
public:
	CTerrain(string fileName, SDL_Rect* camera);
	~CTerrain();
	void Render();
	int Get_Width(){ return numTilesX*tile_width; }
	int Get_Height(){ return numTilesY*tile_height; }

private:
	struct Tiles
	{
		int lowerTileType;
		int upperTileType;
	};
	SDL_Rect* camera;			// Zeiger auf die Camera im Game
	int numTiles;				// Anzahl aller Sprites
	int tile_width;				// Breite eines Tiles
	int tile_height;			// H�he eines Tiles
	int numTilesX;
	int numTilesY;
	Tiles* terrain;			// hier kommt das Array f�r die Map rein, siehe Konstruktor

	/*static const int	TOTAL_TILES = 49284;
	static const int	LEVEL_WIDTH = 9990;
	static const int	LEVEL_HEIGHT = 9990;
	static const int	TILE_SPRITES = 32;
	
	list <CTile>		tiles2;
	list <CTile>		tiles3;
	list <CTile>		tiles4;
	*/
	
	CSpriteObject* lowerSpriteTile;	// Container f�r alle unteren Tile-Sprites
	//CSpriteObject* upperSpriteTile;	// Container f�r alle oberen Tile-Sprites
	int index_1, // erste Position im zweidimensionalen Tile-Array, repr�sentiert y
		index_2, // zweite Position im zweidimensionalen Tile-Array, repr�sentiert x
		index, // Position im eindimensionalen Array
		temp_x, // tats�chliche x-Position
		temp_y; // tats�chliche y-Position
	
};

#endif