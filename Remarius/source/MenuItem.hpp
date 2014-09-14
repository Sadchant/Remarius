#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "Text.hpp"
#include "Sprite.hpp"
#include "Util.hpp"
#include <string>
#include <functional>

class CMenuItem
{
public:
	CMenuItem(CSprite* bg, string label, TTF_Font* font);
	CMenuItem(const CMenuItem& other);
	~CMenuItem();
	CMenuItem& operator = (const CMenuItem& other);
	void render(int x, int y);
	void select(bool b);
	function<void()> func;

private:
	CSprite*		background;
	CText*			text;
	bool			selected;
};

#endif