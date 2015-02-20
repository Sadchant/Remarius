#include "MenuButton.hpp"


CMenuButton::CMenuButton(string label, TTF_Font* font)
{
	background = new CSprite(g_pLoader->getTexture("T_MENUBUTTON"));
	onActivate = function<void()>([](){});
	text = new CText(TEXT_LAYER);
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(180, 180, 180);
}

CMenuButton::CMenuButton(const CMenuButton& other)
{
	background = new CSprite(*other.background);
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
	onActivate = other.onActivate;
	SAFE_DELETE(background);
	SAFE_DELETE(text);
	text = new CText(*other.text);
	background = new CSprite(*other.background);
	xPos = other.xPos;
	yPos = other.yPos;
	return *this;
}

void CMenuButton::render(bool b)
{
	background->Render(b);
	int color = (b) ? 255 : 180;
	text->SetColor(color, color, color);
	text->Render();
}

void CMenuButton::setPos(int x, int y)
{

	CMenuItem::setPos(x, y);
	background->SetPos((float)xPos - 178, (float)yPos - 33);		// texturgröße/2, bitte getter anbieten
	text->SetPos((float)x - text->Get_length()/2, (float)y - text->Get_height()/2);
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