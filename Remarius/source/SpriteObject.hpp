#ifndef SPRITEOBJECT_HPP
#define SPRITEOBJECT_HPP

#include "Sprite.hpp"

class CSpriteObject : public CSprite
{
public:

	CSpriteObject(CTexture* temp_texture, Renderlayers renderlayer, int FrameWidth, int FrameHeight, int groesse);
	void		SetPos(int stelle, int x, int y); // setzt Position des SpriteObjekts an stelle
	void		SetPos(int stelle, float x, float y);
	void		SetSection(int stelle, float frameNumber); //muss nach SetPos aufgerufen werden
	void		SetSection(int stelle, float frameNumber, int direction);

private:
	vector<CSprite*> sprites;
	int groesse;
	CTexture* temp_texture;
};












#endif
