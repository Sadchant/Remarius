#include "MenuSlider.hpp"

CSprite* CMenuSlider::bar = NULL;
CSprite* CMenuSlider::slider = NULL;
CSprite* CMenuSlider::buttons = NULL;

CMenuSlider::CMenuSlider(string label, TTF_Font* font)
{
	text = new CText();
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(180, 180, 180);

	if (!bar) bar = new CSprite("Data/Soundbalken.png", 0, 140, 6);
	if (!slider) slider = new CSprite("Data/Soundschieber.png", 0, 19, 29);
	if (!buttons) buttons = new CSprite("Data/Soundbuttons.png", 2, 65, 65);
}

CMenuSlider::CMenuSlider(const CMenuSlider& other)
{
	text = new CText(*other.text);
}

CMenuSlider::~CMenuSlider()
{
	delete text;
}

CMenuSlider& CMenuSlider::operator = (const CMenuSlider& other)
{
	SAFE_DELETE(text);
	text = new CText(*other.text);
	return *this;
}

void CMenuSlider::freeSprites()
{
	SAFE_DELETE(bar);
	SAFE_DELETE(slider);
	SAFE_DELETE(buttons);
}

bool CMenuSlider::processEvent(SDL_KeyboardEvent& event)
{
	// How MenuSlider reacts to events (SDL_SCANCODE_LEFT and SDL_SCANCODE_RIGHT)
	return false;
}

void CMenuSlider::render(int x, int y, bool b)
{
	/*	rendering menuSlider at position x/y;
		text needs to be repositioned and render
		target/text color set depending on b
		(true if menuSlider is selected in Menu)
		See CMenuButton for reference			*/
}