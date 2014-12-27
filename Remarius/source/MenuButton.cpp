#include "MenuButton.hpp"


CMenuButton::CMenuButton(string label, TTF_Font* font)
{
	background = new CSprite(g_pLoader->getTexture("T_HAUPTMENUBUTTONS"));
	onActivate = function<void()>([](){});
	text = new CText(TEXT_LAYER);
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
	SAFE_DELETE(text);
	SAFE_DELETE(background);
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
	text->SetPos((float)x + (float)(background->Get_targetRect().w - text->Get_length()) / 2,
		(float)y + (background->Get_targetRect().h - text->Get_height()) / 2);
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