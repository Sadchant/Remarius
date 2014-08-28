#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "Text.hpp"

class CMenuItem
{
public:
	CMenuItem(CSprite* bg, char* label, int fontsize);
	~CmenuItem();
	void render(int x, int y);
	void select(bool b);

private:
	CSprite*		background;
	CText*			text;
	bool			selected;
};

#endif