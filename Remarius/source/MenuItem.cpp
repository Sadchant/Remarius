#include "MenuItem.hpp"

CMenuItem::CMenuItem(CSprite* bg, char* label, int fontsize)
{
	background = bg;
	text = new CText;
	text->OpenFont("Data/verdana.ttf", fontsize);
	text->SetContent(label);
	select(false);
}

CMenuItem::~CMenuItem()
{
	delete text;
}

void CMenuItem::render(int x, int y)
{
	background->SetPos(x, y);
	background->Render(0, (selected) ? 1 : 0);
	text->SetPos(x + (background->GetRect().w - text->GetLength())/2,
				 y + (background->GetRect().h - text->GetHigh())/2);
	text->Render();
}

void CMenuItem::select(bool b)
{
	selected = b;
	if (selected)
		text->SetColor(255, 255, 255);
	else
		text->SetColor(180, 180, 180);
}