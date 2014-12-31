#ifndef Tile_HPP
#define Tile_HPP
 
#include "Framework.hpp"
 
class CTile
{
public:
        CTile( int x, int y, int tileType );
        int get_type() {return type;}
        SDL_Rect GetRect(){return box;}

private:
        SDL_Rect	box;
        int			type;
 

};
 
#endif