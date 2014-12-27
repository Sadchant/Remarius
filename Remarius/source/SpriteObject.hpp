#ifndef SPRITEOBJECT_HPP
#define SPRITEOBJECT_HPP

#include "Sprite.hpp"

class CSpriteObject
{
public:

	CSpriteObject(CTexture* texture, int groesse);
	void		SetPos(int stelle, int x, int y); // setzt Position des SpriteObjekts an stelle
	void		SetPos(int stelle, float x, float y);
	void		Render(int stelle);
	void		Render(int stelle, float frameNumber); //muss nach SetPos aufgerufen werden
	void		Render(int stelle, float frameNumber, int direction);

private:
	vector<CSprite*> sprites;
	int groesse;
};












#endif
