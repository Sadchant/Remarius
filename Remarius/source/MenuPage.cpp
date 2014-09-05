#include "MenuPage.hpp"

CMenuPage::CMenuPage(CSprite* bg, char* label, int fontsize)
{
	background = bg;
	caption = new CText();
	caption->OpenFont("Data/verdana.ttf", fontsize);
	caption->SetColor(230, 230, 0);
	caption->SetContent(label);
	caption->SetPos(((float)1024 - caption->GetLength() / 2), 70);
	items = new vector<CMenuItem>;
}

CMenuPage::~CMenuPage()
{
	for (vector<CMenuItem>::iterator it = items->begin(); it != items->end(); it++)
		items->erase(it);
	delete items;
	delete caption;
}

void CMenuPage::addItem(CMenuItem& item)
{
	CMenuItem tmp = item;
	items->push_back(tmp);
	cout << "item added" << endl;
}

void CMenuPage::render()
{
	background->Render();
	caption->Render();
	cout << "cmenupage::render" << endl;
	for (int i = 0; i < items->size(); i++)
		(*items)[i].render(334, 274 + i * 100);
	cout << "cmenupage:.render end" << endl;
}