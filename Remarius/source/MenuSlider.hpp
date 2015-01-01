#ifndef MENUSLIDER_HPP
#define MENUSLIDER_HPP

#include "MenuItem.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "Loader.hpp"
#include <functional>

class CMenuSlider : public CMenuItem
{
public:
	CMenuSlider(string label, TTF_Font* font, int range = 10);
	CMenuSlider(const CMenuSlider& other);
	~CMenuSlider();
	CMenuSlider& operator = (const CMenuSlider& other);

	void render(bool b = false);					// render MenuSlider instance at x/y; if b, instance is selected in Menu
	void setPos(int x, int y);
	bool processEvent(SDL_KeyboardEvent& event);
	bool setState(int newstate) { if (newstate >= 0 && newstate <= max) { state = newstate; onChange(state); return true; } return false; }
	int getState() { return state; }
	void setListener(function<void(int)> func) { onChange = func; }

private:
	CSprite* bar;
	CSprite* slider;
	CSprite* buttonL;
	CSprite* buttonR;
	CSprite* panel;
	CText* text;												// text label for MenuSlider instance
	string baselabel;
	int state;
	int max;
	function<void(int)> onChange;
};


#endif