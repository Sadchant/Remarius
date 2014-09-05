#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "Text.hpp"
#include "Sprite.hpp"

class CMenuItem
{
public:
	CMenuItem(CSprite* bg, char* label, int fontsize);
	~CMenuItem();
	void render(int x, int y);
	void select(bool b);
	//virtual void update(SDL_Event& event);

private:
	CSprite*		background;
	CText*			text;
	bool			selected;
};

#endif