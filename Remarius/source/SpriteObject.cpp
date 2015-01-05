#include "SpriteObject.hpp"

/*	Ein Spriteobjekt ist eine Verwaltung für viele Sprites, die sich die selbe Textur teilen
	und 
	
	
	*/

CSpriteObject::CSpriteObject(CTexture* texture, int groesse)
{
	this->groesse = groesse;

	sprites.reserve(groesse); // setzt die Größe des Vectors auf die gebrauchte Länge
	for (int i = 0; i < groesse; i++)
	{
		CSprite* default_Sprite = new CSprite(texture);
		sprites.push_back(default_Sprite);
	}
	textureDimensions.x = texture->frameWidth;
	textureDimensions.y = texture->frameHeight;
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
	if (stelle >= groesse) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		if (sprites.at(stelle) == NULL)
		{
			cout << "ACHTUNG HIER LAEUFT WAS SCHIEF!!!" << endl;
		}
		sprites.at(stelle)->Render();
	}
}

void CSpriteObject::Render(int stelle, int frameNumber)
{
	if (stelle >= groesse) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->Render(frameNumber);
	}
}

void CSpriteObject::Render(int stelle, int frameNumber, int direction)
{
	if (stelle >= groesse) // <-- Diese Abfrage kann später, wenns was bringt und alles klappt weg
	{
		cout << "Fehler: An der Stelle gibts kein SpriteObject du Kloppi! (CSpriteObject::Render)" << endl;
		return;
	}
	else
	{
		sprites.at(stelle)->Render(frameNumber, direction);
	}
}