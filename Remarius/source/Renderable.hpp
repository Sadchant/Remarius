#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "Framework.hpp"


enum Renderlayers
{
	TILE_LAYER1,
	TILE_LAYER2,
	ENTITY_LAYER,
	INGAMETEXT_LAYER,
	GUI_LAYER,
	MENU_LAYER,
	MENUBUTTON_LAYER,
	TEXT_LAYER
};

class CRenderable
{
public:
	CRenderable();
	void		SetPos(float fXPos, float fYPos);
	void		SetPos(int XPos, int YPos);

	virtual void Render() {};
	virtual void RenderYourself() {};

	SDL_Rect	Get_targetRect(){ return target_Rect; }
	

protected:
	SDL_Rect target_Rect;			// Ausschnitt auf dem Bildschirm
	Renderlayers renderlayer;
};

#endif
