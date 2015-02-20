#include "MenuPage.hpp"

TTF_Font* CMenuPage::captionFont = NULL;
const SDL_Color CMenuPage::captionColor = { 230, 230, 0, 0 };
const int CMenuPage::captionXPos = 640;
const int CMenuPage::captionYPos = 70;

CMenuPage::CMenuPage(string label, TTF_Font* font)
{
	if (!captionFont) captionFont = OpenFont("Data/verdana.ttf", 25);
	selected = 0;
	background = new CSprite(g_pLoader->getTexture("T_MENUBG"));
	caption = new CText(TEXT_LAYER);
	caption->SetFont(captionFont);
	caption->SetColor(captionColor.r, captionColor.g, captionColor.b);
	caption->SetContent(label);
	caption->SetPos(captionXPos - caption->Get_length()/2, captionYPos - caption->Get_height()/2);
}

CMenuPage::CMenuPage(const CMenuPage& other) :
background(other.background), selected(other.selected)
{
	caption = new CText(*other.caption);
	background = new CSprite(*other.background);
	for (unsigned int i = 0; i < other.items.size(); i++)
		items.push_back(other.items[i]);

}

CMenuPage::~CMenuPage()
{
	items.clear();
	delete caption;
	delete background;
}

CMenuPage& CMenuPage::operator = (const CMenuPage& other)
{
	selected = other.selected;
	items.clear();
	for (unsigned int i = 0; i < other.items.size(); i++)
	{
		items.push_back(other.items[i]);
	}
	SAFE_DELETE(background);
	background = new CSprite(*other.background);
	SAFE_DELETE(caption);
	caption = new CText(*other.caption);

	return *this;
}

void CMenuPage::addItem(CMenuItem* item)
{
	item->setPos(captionXPos, captionYPos + 120 + (items.size() * 100));
	items.push_back(item);
}

void CMenuPage::render()
{
	background->Render();
	caption->Render();
	for (unsigned int i = 0; i < items.size(); i++)
	{
		items[i]->render(selected == i);	
	}
}

void CMenuPage::processEvent(SDL_KeyboardEvent &event)
{
	if (event.type == SDL_KEYDOWN)
		switch (event.keysym.scancode)
		{
		case SDL_SCANCODE_DOWN:
			if (selected < items.size()-1) 
				selected++; 
			else if (selected >= items.size()-1)
				selected = 0;
			break;
		case SDL_SCANCODE_UP:
			if (selected > 0)
				selected--;
			else if (selected <= 1)
				selected = items.size()-1;
			break;
		default:
			if (items[selected]->processEvent(event))
				selected = 0;
			break;
		}
}

void CMenuPage::freeItems()
{
	for (CMenuItem* i : items)
		delete i;
	items.clear();
}