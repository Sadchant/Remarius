#include "Tile.hpp"
 
CTile::CTile( int x, int y, int tileType )
{
    // Position setzen
    box.x = x;
    box.y = y;
    
    // Breite und Höhe setzen
    box.w = 45;
    box.h = 45;
    
    // den Typ festlegen
    type = tileType;
 
}