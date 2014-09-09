#include "MenuItem.hpp"

CMenuItem::CMenuItem(CSprite* bg, string label, TTF_Font* font)
{
	background = bg;
	text = new CText;
	text->SetFont(font);
	text->SetContent(label);
	select(false);
}

CMenuItem::CMenuItem(const CMenuItem& other)
{
	background = other.background;
	text = new CText(*other.text);
	select(false);
}


CMenuItem::~CMenuItem()
{
	delete text;
}

CMenuItem& CMenuItem::operator = (const CMenuItem& other)
{
	background = other.background;
	text = new CText(*other.text);
	select(false);
	return *this;
}

void CMenuItem::render(int x, int y)
{
	background->SetPos((float)x, (float)y);
	background->Render(0, (selected) ? 1 : 0);
	text->SetPos((float)x + (float)(background->GetRect().w - text->GetLength())/2,
				 (float)y + (background->GetRect().h - text->GetHigh())/2);
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