#include "MenuCheckBox.hpp"

CSprite* CMenuCheckBox::buttons = NULL;

CMenuCheckBox::CMenuCheckBox(string label, TTF_Font* font)
{
	text = new CText();
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(255, 255, 255);
	selected = false;

	listener = function<void(bool)>([](bool b){});

	if (!buttons) buttons = new CSprite("Data/MenuCheckBox.png", 2, 65, 65);
}

CMenuCheckBox::CMenuCheckBox(const CMenuCheckBox& other)
{
	text = new CText(*other.text);
	selected = other.selected;

	listener = other.listener;
}

CMenuCheckBox& CMenuCheckBox:: operator = (const CMenuCheckBox& other)
{
	SAFE_DELETE(text);
	text = new CText(*other.text);
	selected = other.selected;
	listener = other.listener;
	return *this;
}

CMenuCheckBox::~CMenuCheckBox()
{
	SAFE_DELETE(text);
}

void CMenuCheckBox::render(int x, int y, bool b)
{
	// test rendering, needs proper implementation
	buttons->SetPos(x, y);
	buttons->Render(b?1:0, !selected);
	text->SetPos(x + 70, y);
	text->Render();
}

bool CMenuCheckBox::processEvent(SDL_KeyboardEvent& event)
{
	if (event.type == SDL_KEYDOWN && event.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		selected = selected ^ true;
		listener(selected);
	}
	return false;
}

void CMenuCheckBox::freeSprites()
{
	SAFE_DELETE(buttons);
}