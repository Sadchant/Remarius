#include "Tile.hpp"
 
CTile::CTile( int x, int y, int tileType )
{
    //Get the offsets
    box.x = x;
    box.y = y;
    
    //Set the collision box
    box.w = 45;
    box.h = 45;
    
    //Get the tile type
    type = tileType;
 
}