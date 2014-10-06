#ifndef MENUCHECKBOX_HPP
#define MENUCHECKBOX_HPP

#include "MenuItem.hpp"
#include "Text.hpp"

class CMenuCheckBox : public CMenuItem
{
public:
	CMenuCheckBox(string label, TTF_Font* font);
	CMenuCheckBox(const CMenuCheckBox& other);
	~CMenuCheckBox();
	CMenuCheckBox& operator = (const CMenuCheckBox& other);

	void render(int x, int y, bool b = false);
	bool processEvent(SDL_KeyboardEvent& event);

	bool getState() { return selected; }
	void setState(bool b) { selected = b; }

	static void freeSprites();

private:
	static CSprite*	buttons;
	CText*			text;
	bool			selected;
};

#endif