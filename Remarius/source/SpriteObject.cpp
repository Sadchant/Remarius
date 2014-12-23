#include "SpriteObject.hpp"

/*	Ein Spriteobjekt ist eine Verwaltung für viele Sprites, die sich die selbe Textur teilen
	und 
	
	
	*/

CSpriteObject::CSpriteObject(CTexture* texture, Renderlayers renderlayer, int frameWidth, int frameHeight, int groesse)
{
	source_Rect = { 0 };
	source_Rect.w = frameWidth;
	source_Rect.h = frameHeight;
	target_Rect.x = -100;
	target_Rect.y = -100;
	target_Rect.w = frameWidth;
	target_Rect.h = frameHeight;

	this->texture = texture;
	renderer = texture->sdl_renderer;

	renderlayer = this->renderlayer = renderlayer;
	int width, height;
	SDL_QueryTexture(texture->sdl_texture, NULL, NULL, &width, &height);
	numFramesX = width / target_Rect.w;

	this->groesse = groesse;
	sprites.resize(groesse); // setzt die Größe des Vectors auf die gebrauchte Länge
	CSprite* default_Sprite = new CSprite(texture, renderlayer, target_Rect.w, target_Rect.h);
	fill(sprites.begin(), sprites.end(), default_Sprite);
}

void CSpriteObject::SetPos(int stelle, int x, int y)
{
	if (stelle >= groesse)
	{
		cout << "Fehler: Groesse des SpriteObjects ueberschritten du Kloppi! (CSpriteObject::SetPos)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->SetPos(x, y);
	}	
}

void CSpriteObject::SetPos(int stelle, float x, float y)
{
	SetPos(stelle, static_cast<int>(x), static_cast<int>(y));
}

void CSpriteObject::Render(int stelle)
{
	if ((stelle >= groesse) || (stelle >= (int)sprites.size())) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->Render();
	}
}

void CSpriteObject::Render(int stelle, float frameNumber)
{
	if (stelle >= groesse || stelle >= (int)sprites.size()) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->Render(frameNumber);
	}
}

void CSpriteObject::Render(int stelle, float frameNumber, int direction)
{
	if (stelle >= groesse || stelle >= (int)sprites.size()) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->Render(frameNumber, direction);
	}
}