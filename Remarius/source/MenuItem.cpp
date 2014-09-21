#include "MenuItem.hpp"

CMenuItem::CMenuItem(CSprite* bg, string label, TTF_Font* font)
{
	background = bg;
	activate = function<void()>([](){});
	text = new CText;
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(180, 180, 180);
}

CMenuItem::CMenuItem(const CMenuItem& other)
{
	background = other.background;
	activate = other.activate;
	text = new CText(*other.text);
}

CMenuItem::~CMenuItem()
{
	delete text;
}

CMenuItem& CMenuItem::operator = (const CMenuItem& other)
{
	background = other.background;
	activate = other.activate;
	text = new CText(*other.text);
	return *this;
}

void CMenuItem::render(int x, int y, bool b)
{
	background->SetPos((float)x, (float)y);
	background->Render(0, (b) ? 1 : 0);
	int color = (b) ? 255 : 180;
	text->SetColor(color, color, color);
	text->SetPos((float)x + (float)(background->GetRect().w - text->GetLength())/2,
				 (float)y + (background->GetRect().h - text->GetHigh())/2);
	text->Render();
}