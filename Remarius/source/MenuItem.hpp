#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include "Text.hpp"
#include "Sprite.hpp"
#include <string>

class CMenuItem
{
public:
	CMenuItem(CSprite* bg, string label, TTF_Font* font);
	CMenuItem(const CMenuItem& other);
	~CMenuItem();
	CMenuItem& operator = (const CMenuItem& other);
	void render(int x, int y);
	void select(bool b);
	//virtual void update(SDL_Event& event);

private:
	CSprite*		background;
	CText*			text;
	bool			selected;
};

#endif