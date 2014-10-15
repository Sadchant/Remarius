#ifndef MENUCHECKBOX_HPP
#define MENUCHECKBOX_HPP

#include "MenuItem.hpp"
#include "Text.hpp"
#include <functional>

class CMenuCheckBox : public CMenuItem
{
public:
	CMenuCheckBox(string label, TTF_Font* font);
	CMenuCheckBox(const CMenuCheckBox& other);
	~CMenuCheckBox();
	CMenuCheckBox& operator = (const CMenuCheckBox& other);

	void render(int x, int y, bool b = false);
	bool processEvent(SDL_KeyboardEvent& event);

	void setListener(function<void(bool)> func) { listener = func; }
	void setState(bool b) { selected = b; listener(selected); }

	static void freeSprites();

private:
	static CSprite*	buttons;
	CText*			text;
	bool			selected;
	function<void(bool)> listener;
};

#endif