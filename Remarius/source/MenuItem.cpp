#include MenuItem.hpp

CMenuItem::CMenuItem(CSprite* bg, char* label, int fontsize)
{
	background = bg;
	text = new CText;
	text->OpenFont("Data/verdana.ttf", fontsize);
	text->SetContent(label);
	select(false);
}

CMenuItem::~CMenuItem()
{
	delete text;
}

CMenuItem::render(int x, int y)
{
	background->setPos(x, y);
	background->render(0, (selected) ? 1 : 0);
	text->setPos(x + (background->getLength() - text->getLength())/2,
				 y + (background->getlength() - text->getLength())/2);
	text->render();
}

CMenuItem::select(bool b)
{
	selected = b;
	if (selected)
		text->SetColor(255, 255, 255);
	else
		text->SetColor(180, 180, 180);
}