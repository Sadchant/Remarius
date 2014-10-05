#ifndef MENUSLIDER_HPP
#define MENUSLIDER_HPP

#include "MenuItem.hpp"
#include "Text.hpp"

class CMenuSlider : public CMenuItem
{
public:
	CMenuSlider(string label, TTF_Font* font, int range = 10);
	CMenuSlider(const CMenuSlider& other);
	~CMenuSlider();
	CMenuSlider& operator = (const CMenuSlider& other);

	static void freeSprites();											// call to free static Sprite resource

	void render(int x, int y, bool b = false);					// render MenuSlider instance at x/y; if b, instance is selected in Menu
	bool processEvent(SDL_KeyboardEvent& event);
	bool setState(int newstate) { if (newstate >= 0 && newstate <= max) { state = newstate; return true; } return false; }
	int getState() { return state; }

private:
	static CSprite* bar;										// static Sprite resource for all Sliders
	static CSprite* slider;
	static CSprite* buttons;

	CText* text;												// text label for MenuSlider instance
	int state;
	int max;
};


#endif