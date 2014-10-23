#ifndef MENUBUTTON_HPP
#define MENUBUTTON_HPP

#include "MenuItem.hpp"
#include "Text.hpp"
#include <functional>

class CMenuButton : public CMenuItem
{
public:
	CMenuButton(CSprite* bg, string label, TTF_Font* font);
	CMenuButton(const CMenuButton& other);
	~CMenuButton();
	CMenuButton& operator = (const CMenuButton& other);

	void render(bool b = false);
	void setPos(int x, int y);
	bool processEvent(SDL_KeyboardEvent& event);

	void setfunc(function<void()> func){ onActivate = func; }

private:
	CSprite*		background;
	CText*			text;
	function<void()> onActivate;

};

#endif