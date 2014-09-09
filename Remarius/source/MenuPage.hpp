#ifndef MENUPAGE_HPP
#define MENUPAGE_HPP

#include "Text.hpp"
#include "Sprite.hpp"
#include "MenuItem.hpp"
#include <vector>

class CMenuPage
{
public:
	CMenuPage(CSprite* bg, string label, TTF_Font* font);
	CMenuPage(const CMenuPage& other);
	~CMenuPage();
	CMenuPage& operator = (const CMenuPage& other);
	void addItem(CMenuItem& item);
	void render();

private:
	vector<CMenuItem>	items;
	int					selected;
	CSprite*			background;
	CText*				caption;
};

#endif