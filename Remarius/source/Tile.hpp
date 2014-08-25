#ifndef Tile_HPP
#define Tile_HPP
 
#include "Framework.hpp"
 
class CTile
{
private:
        SDL_Rect        box;
        int                     type;
        int TILE_WIDTH;
        int TILE_HEIGHT;
 
public:
        CTile( int x, int y, int tileType );
        int get_type() {return type;}
        SDL_Rect GetRect(){return box;}
};
 
#endif