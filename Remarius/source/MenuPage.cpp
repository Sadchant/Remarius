#include "MenuPage.hpp"

CMenuPage::CMenuPage(CSprite* bg, string label, TTF_Font* font)
{
	selected = 0;
	background = bg;
	caption = new CText();
	caption->SetFont(font);
	caption->SetColor(230, 230, 0);
	caption->SetContent(label);
	caption->SetPos((float)334, 70);
}

CMenuPage::CMenuPage(const CMenuPage& other) :
background(other.background), selected(other.selected)
{
	caption = new CText(*other.caption);
	for (unsigned int i = 0; i < other.items.size(); i++)
		items.push_back(other.items[i]);

}

CMenuPage::~CMenuPage()
{
	items.clear();
	delete caption;
}

CMenuPage& CMenuPage::operator = (const CMenuPage& other)
{
	selected = other.selected;
	items.clear();
	for (unsigned int i = 0; i < other.items.size(); i++)
	{
		items.push_back(other.items[i]);
	}
	background = other.background;
	caption = new CText(*other.caption);

	return *this;
}

void CMenuPage::addItem(CMenuItem& item)
{
	items.push_back(item);
}

void CMenuPage::render()
{
	background->Render();
	caption->Render();
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i].render(334, 274 + i * 100, (selected == i));	
	}
}

void CMenuPage::processEvent(SDL_KeyboardEvent &event)
{
	switch (event.keysym.scancode)
	{
	case SDLK_RETURN:
		items[selected].onactivate();
		break;
	case SDLK_DOWN:
		if (selected < items.size()-1) 
			selected++; 
		break;
	case SDLK_UP:
		if (selected > 0)
			selected--;
		break;
	default:
		break;
	}
}