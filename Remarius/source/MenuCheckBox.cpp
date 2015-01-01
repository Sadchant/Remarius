#include "MenuCheckBox.hpp"

CMenuCheckBox::CMenuCheckBox(string label, TTF_Font* font)
{
	text = new CText(TEXT_LAYER);
	button = new CSprite(g_pLoader->getTexture("T_MENUCHECKBOX"));
	panel = new CSprite(g_pLoader->getTexture("T_MENUCHECKBOXPANEL"));
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(255, 255, 255);
	selected = false;

	listener = function<void(bool)>([](bool b){});
}

CMenuCheckBox::CMenuCheckBox(const CMenuCheckBox& other)
{
	text = new CText(*other.text);
	button = new CSprite(*other.button);
	panel = new CSprite(*other.panel);
	selected = other.selected;
	xPos = other.xPos;
	yPos = other.yPos;

	listener = other.listener;
}

CMenuCheckBox& CMenuCheckBox:: operator = (const CMenuCheckBox& other)
{
	SAFE_DELETE(text);
	SAFE_DELETE(button);
	SAFE_DELETE(panel);
	text = new CText(*other.text);
	button = new CSprite(*other.button);
	panel = new CSprite(*other.panel);
	selected = other.selected;
	listener = other.listener;
	xPos = other.xPos;
	yPos = other.yPos;
	return *this;
}

CMenuCheckBox::~CMenuCheckBox()
{
	SAFE_DELETE(text);
	SAFE_DELETE(button);
	SAFE_DELETE(panel);
}

void CMenuCheckBox::render(bool b)
{
	panel->Render(b);
	button->Render(b, !selected);
	int color = (b) ? 255 : 180;
	text->SetColor(color, color, color);
	text->Render();
}

void CMenuCheckBox::setPos(int x, int y)
{
	CMenuItem::setPos(x, y);
	panel->SetPos(x - (291 + 65) / 2, y - 66 / 2);					// x - (291 + 65) / 2 ist linke obere Ecke
	button->SetPos(x - (291 + 65) / 2 + 291, y - 65 / 2);
	text->SetPos(x - (291 + 65) / 2 + 291/2 - text->Get_length()/2, y - text->Get_height()/2);
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