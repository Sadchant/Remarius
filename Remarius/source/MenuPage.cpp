#include "MenuPage.hpp"

CMenuPage::CMenuPage(CSprite* bg, char* caption, int fontsize)
{
	background = bg;
	caption = new CText();
	caption->OpenFont("Data/verdana.ttf", fontsize);
	caption->setColor(230, 230, 0);
	caption->SetContent(label);
	items = new vector<CMenuPage>;
	selectedItem = NULL;
}

CMenuPage::~CMenuPage()
{
	for (CMenuItem item : items)
		delete item;
	delete items;
	delete caption;
}

CMenuPage::addItem(CMenuItem* item)
{
	if (!items.size)
		selectedItem = item;
	items.pushBack(item);
}

CMenuPage::render()
{
	background->render();
	caption->render((float) (1024 - caption->getLength()/2), 70);

	for (vector<CMenuItem>::iterator it = items.begin(), int i = 0; it != items.end(); it++, i++)
		it->render(334, 274 + i * 100);
}