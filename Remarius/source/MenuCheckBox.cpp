#include "MenuCheckBox.hpp"

CSprite* CMenuCheckBox::buttons = NULL;

CMenuCheckBox::CMenuCheckBox(string label, TTF_Font* font)
{
	text = new CText(TEXT_LAYER);
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(255, 255, 255);
	selected = false;

	listener = function<void(bool)>([](bool b){});

	if (!buttons) buttons = new CSprite(g_pLoader->getTexture("T_MENUCHECKBOX"));
}

CMenuCheckBox::CMenuCheckBox(const CMenuCheckBox& other)
{
	text = new CText(*other.text);
	selected = other.selected;
	xPos = other.xPos;
	yPos = other.yPos;

	listener = other.listener;
}

CMenuCheckBox& CMenuCheckBox:: operator = (const CMenuCheckBox& other)
{
	SAFE_DELETE(text);
	text = new CText(*other.text);
	selected = other.selected;
	listener = other.listener;
	xPos = other.xPos;
	yPos = other.yPos;
	return *this;
}

CMenuCheckBox::~CMenuCheckBox()
{
	SAFE_DELETE(text);
}

void CMenuCheckBox::render(bool b)
{
	buttons->SetPos((float)xPos, (float)yPos);
	buttons->Render(b, !selected);
	text->Render();
}

void CMenuCheckBox::setPos(int x, int y)
{
	CMenuItem::setPos(x, y);
	text->SetPos((float)x + 70, (float)y);
}

bool CMenuCheckBox::processEvent(SDL_KeyboardEvent& event)
{
	if (event.type == SDL_KEYDOWN && event.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		selected = selected ^ true;
		int c = selected ? 255 : 180;
		text->SetColor(c, c, c);
		listener(selected);
	}
	return false;
}

void CMenuCheckBox::freeSprites()
{
	SAFE_DELETE(buttons);
}