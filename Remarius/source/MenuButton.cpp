#include "MenuButton.hpp"


CMenuButton::CMenuButton(CSprite* bg, string label, TTF_Font* font)
{
	background = bg;
	onActivate = function<void()>([](){});
	text = new CText;
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(180, 180, 180);
}

CMenuButton::CMenuButton(const CMenuButton& other)
{
	background = other.background;
	onActivate = other.onActivate;
	text = new CText(*other.text);
	xPos = other.xPos;
	yPos = other.yPos;
}

CMenuButton::~CMenuButton()
{
	delete text;
}

CMenuButton& CMenuButton::operator = (const CMenuButton& other)
{
	background = other.background;
	onActivate = other.onActivate;
	SAFE_DELETE(text);
	text = new CText(*other.text);
	xPos = other.xPos;
	yPos = other.yPos;
	return *this;
}

void CMenuButton::render(bool b)
{
	background->SetPos((float)xPos, (float)yPos);
	background->Render(0, (b) ? 1 : 0);
	int color = (b) ? 255 : 180;
	text->SetColor(color, color, color);
	text->Render();
}

void CMenuButton::setPos(int x, int y)
{
	CMenuItem::setPos(x, y);
	text->SetPos((float)x + (float)(background->GetRect().w - text->GetLength()) / 2,
		(float)y + (background->GetRect().h - text->GetHigh()) / 2);
}

bool CMenuButton::processEvent(SDL_KeyboardEvent& event)
{
	if (event.type == SDL_KEYDOWN && event.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		onActivate();
		return true;
	}
	return false;
}