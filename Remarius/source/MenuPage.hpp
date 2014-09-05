#ifndef MENUPAGE_HPP
#define MENUPAGE_HPP

#include "Text.hpp"
#include "Sprite.hpp"
#include "MenuItem.hpp"
#include <vector>

class CMenuPage
{
public:
	CMenuPage(CSprite* bg, char* label, int fontsize);
	~CMenuPage();
	void addItem(CMenuItem* item);
	void render();

private:
	vector<CMenuItem>*	items;
	int					selected;
	CSprite*			background;
	CText*				caption;
	CMenuItem*			selectedItem;
};

#endif