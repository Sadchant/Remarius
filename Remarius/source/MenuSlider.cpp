#include "MenuSlider.hpp"

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

	bar = new CSprite(g_pLoader->getTexture("T_MENUSLIDERBAR"));
	slider = new CSprite(g_pLoader->getTexture("T_MENUSLIDER"));
	buttonL = new CSprite(g_pLoader->getTexture("T_MENUSLIDERBUTTON"));
	buttonR = new CSprite(g_pLoader->getTexture("T_MENUSLIDERBUTTON"));
	panel = new CSprite(g_pLoader->getTexture("T_MENUSLIDERPANEL"));
}

CMenuSlider::CMenuSlider(const CMenuSlider& other)
{
	text = new CText(*other.text);
	xPos = other.xPos;
	yPos = other.yPos;
	onChange = other.onChange;
	bar = new CSprite(*other.bar);
	slider = new CSprite(*other.slider);
	buttonL = new CSprite(*other.buttonL);
	buttonR = new CSprite(*other.buttonR);
	panel = new CSprite(*other.panel);
}

CMenuSlider::~CMenuSlider()
{
	SAFE_DELETE(text);
	SAFE_DELETE(bar);
	SAFE_DELETE(slider);
	SAFE_DELETE(buttonL);
	SAFE_DELETE(buttonR);
	SAFE_DELETE(panel);
}

CMenuSlider& CMenuSlider::operator = (const CMenuSlider& other)
{
	SAFE_DELETE(text);
	SAFE_DELETE(bar);
	SAFE_DELETE(slider);
	SAFE_DELETE(buttonL);
	SAFE_DELETE(buttonR);
	SAFE_DELETE(panel);
	text = new CText(*other.text);
	bar = new CSprite(*other.bar);
	slider = new CSprite(*other.slider);
	buttonL = new CSprite(*other.buttonL);
	buttonR = new CSprite(*other.buttonR);
	panel = new CSprite(*other.panel);
	onChange = other.onChange;
	xPos = other.xPos;
	yPos = other.yPos;
	return *this;
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
	panel->Render(b);
	text->SetContent(baselabel + ": " + to_string((int)(100 * state/max)));
	text->SetPos(xPos - (106 + 65 + 65 + 120) / 2 + 106 / 2 - text->Get_length() / 2, yPos - text->Get_height() / 2);
	int c = b ? 255 : 180;
	text->SetColor(c, c, c);
	text->Render();
	bar->Render();
	slider->SetPos(xPos - (106 + 65 + 65 + 120) / 2 + 106 + 65 - 10 + state * 140/max - 19 / 2, yPos - 29 / 2);
	slider->Render();
	buttonL->Render(b);
	buttonR->Render(2 + b);
}

void CMenuSlider::setPos(int x, int y)
{
	CMenuItem::setPos(x, y);
	panel->SetPos(x - (106 + 65 + 65 + 120) / 2, y - 66 / 2);		// x - (107 + 65 + 65 + 120) / 2 ist linke obere Ecke
	text->SetPos(x - (106 + 65 + 65 + 120) / 2 + 106/2 - (text->Get_length() + 30)/2, y - text->Get_height()/2);
	buttonL->SetPos(x - (106 + 65 + 65 + 120) / 2 + 106, y - 65 / 2);
	buttonR->SetPos(x - (106 + 65 + 65 + 120) / 2 + 106 + 65 + 120, y - 65 / 2);// 120 sind Breite des Balkens minus 10px Überlappung vom linken Button
	bar->SetPos(x - (106 + 65 + 65 + 120) / 2 + 106 + 65 - 10, y - 6 / 2);	// -10 weil Überlappung
}