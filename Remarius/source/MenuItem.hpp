#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "Text.hpp"
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
	void render(int x, int y, bool b = false);
	void setfunc(function<void()> func){ activate = func; }
	void onactivate(){ activate(); }

private:
	CSprite*		background;
	CText*			text;
	function<void()> activate;
};

#endif