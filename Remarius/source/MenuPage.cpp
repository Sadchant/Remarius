#include "MenuPage.hpp"

CMenuPage::CMenuPage(CSprite* bg, string label, TTF_Font* font)
{
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
	//CMenuItem tmp = item;
	items.push_back(item);
	items[0].select(true);
	cout << "item added" << endl;
}

void CMenuPage::render()
{
	cout << "now rendering menupage bg" << endl;
	background->Render();
	cout << "now rendering caption" << endl;
	caption->Render();
	cout << "cmenupage::render" << endl;
	for (unsigned int i = 0; i < items.size(); i++)
		items[i].render(334, 274 + i * 100);
	cout << "cmenupage:.render end" << endl;
}