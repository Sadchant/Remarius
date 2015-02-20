#ifndef MENUPAGE_HPP
#define MENUPAGE_HPP

#include "Text.hpp"
#include "Sprite.hpp"
#include "MenuItem.hpp"
#include "Util.hpp"
#include <vector>

class CMenuPage
{
public:
	CMenuPage(string label, TTF_Font* font);
	CMenuPage(const CMenuPage& other);
	~CMenuPage();
	CMenuPage& operator = (const CMenuPage& other);
	void addItem(CMenuItem* item);
	void render();
	void processEvent(SDL_KeyboardEvent &event);
	void freeItems();

private:
	vector<CMenuItem*>	items;
	unsigned int		selected;
	CSprite*			background;
	CText*				caption;
	static TTF_Font*	captionFont;				// temporär und wird noch net freigegeben, passiert dann im Loader
	static const SDL_Color captionColor;
	static const int	captionXPos;
	static const int	captionYPos;
};

#endif