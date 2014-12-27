#include "MenuSlider.hpp"

CSprite* CMenuSlider::bar = NULL;
CSprite* CMenuSlider::slider = NULL;
CSprite* CMenuSlider::buttons = NULL;

CMenuSlider::CMenuSlider(string label, TTF_Font* font, int range)
{
	text = new CText(TEXT_LAYER);
	text->SetFont(font);
	text->SetContent(label);
	text->SetColor(180, 180, 180);
	
	max = range-1;
	state = 0;
	baselabel = label;
	onChange = function<void(int)>([](int m){});

	if (!bar) bar = new CSprite(g_pLoader->GetTexture(SOUNDBALKEN));
	if (!slider) slider = new CSprite(g_pLoader->GetTexture(SOUNDSCHIEBER));
	if (!buttons) buttons = new CSprite(g_pLoader->GetTexture(SOUNDBUTTONS));
}

CMenuSlider::CMenuSlider(const CMenuSlider& other)
{
	text = new CText(*other.text);
	xPos = other.xPos;
	yPos = other.yPos;
	onChange = other.onChange;
}

CMenuSlider::~CMenuSlider()
{
	delete text;
}

CMenuSlider& CMenuSlider::operator = (const CMenuSlider& other)
{
	SAFE_DELETE(text);
	text = new CText(*other.text);
	onChange = other.onChange;
	xPos = other.xPos;
	yPos = other.yPos;
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
	if (event.type == SDL_KEYDOWN)
	{
		if (event.keysym.scancode == SDL_SCANCODE_LEFT && state > 0)
			onChange(--state);
		if (event.keysym.scancode == SDL_SCANCODE_RIGHT && state < max)
			onChange(++state);
	}
	return false;
}

void CMenuSlider::render(bool b)
{
	/*	rendering menuSlider at position x/y;
		text needs to be repositioned and render
		target/text color set depending on b
		(true if menuSlider is selected in Menu)
		See CMenuButton for reference			*/
	text->SetContent(baselabel + ": " + to_string(state));
	int c = b ? 255 : 180;
	text->SetColor(c, c, c);
	text->Render();
	slider->SetPos((float)xPos + state * 10, (float)yPos);
	slider->Render();
}

void CMenuSlider::setPos(int x, int y)
{
	CMenuItem::setPos(x, y);
	text->SetPos((float)x, (float)y + 20);
}