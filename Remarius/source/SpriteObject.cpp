#include "SpriteObject.hpp"

/*	Ein Spriteobjekt ist eine Verwaltung für viele Sprites, die sich die selbe Textur teilen
	und 
	
	
	*/


CSpriteObject::CSpriteObject(CTexture* temp_texture, Renderlayers renderlayer, int frameWidth, int frameHeight, int groesse)
{
	source_Rect = { 0 };
	source_Rect.w = frameWidth;
	source_Rect.h = frameHeight;
	target_Rect.w = frameWidth;
	target_Rect.h = frameHeight;

	this->temp_texture = temp_texture;
	renderer = temp_texture->Get_renderer();
	texture = temp_texture->Get_texture();
	renderlayer = this->renderlayer = renderlayer;

	int width, height;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
	numFramesX = width / target_Rect.w;
	this->groesse = groesse;
	sprites.reserve(groesse); // setzt die Größe des Vectors auf die gebrauchte Länge
	//fill(sprites.begin(), sprites.end(), NULL); // befüllt das gesamte Array mit NULL
}

void CSpriteObject::SetPos(int stelle, int x, int y)
{
	if (stelle >= groesse)
	{
		cout << "Fehler: Größe des SpriteObjects überschritten du Kloppi!" << endl;
		return;
	}
	if (stelle >= sprites.size())
	{
		CSprite* temp_Sprite = new CSprite(temp_texture, renderlayer, target_Rect.w, target_Rect.h);
		temp_Sprite->SetPos(x, y);
		sprites.push_back(temp_Sprite);
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


void CSpriteObject::SetSection(int stelle, float frameNumber)
{
	if (stelle >= groesse)
	{
		cout << "Fehler: Größe des SpriteObjects überschritten du Kloppi!" << endl;
		return;
	}
	if (stelle >= sprites.size())
	{
		CSprite* temp_Sprite = new CSprite(temp_texture, renderlayer, target_Rect.w, target_Rect.h);
		temp_Sprite->Render(stelle, frameNumber);
		sprites.push_back(temp_Sprite);
	}
	else
	{
		sprites.at(stelle)->Render(stelle, frameNumber);
	}
}