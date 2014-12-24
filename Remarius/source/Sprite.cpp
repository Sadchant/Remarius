#include "Sprite.hpp"

CSprite::CSprite(CTexture* texture, Renderlayers renderlayer, int frameWidth, int frameHeight)
{
	if (texture == NULL)
	{
		cout << "ACHTUNG: Textur ist NULL! (CSprite::CSprite)" << endl;
		return;
	}
	source_Rect = { 0 };
	source_Rect.w = frameWidth;
	source_Rect.h = frameHeight;
	target_Rect.w = frameWidth;
	target_Rect.h = frameHeight;

	this->texture = texture;
	renderer = g_pFramework->GetRenderer();

	renderlayer = this->renderlayer = renderlayer;
	int width, height = 0;
	SDL_QueryTexture(this->texture->sdl_texture, NULL, NULL, &width, &height);
	numFramesX = width / target_Rect.w;
	
}

// Sprite-Objekt an den Renderlayer geben
void CSprite::Render()
{
	g_pRenderlayer->add_Renderjob(this, renderlayer);
}



// animiertes Sprite-Objekt an den Renderlayer geben
void CSprite::Render (float frameNumber)										
{
	int Column = static_cast<int>(frameNumber) % numFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row = static_cast<int>(frameNumber) / numFramesX;

	source_Rect.x = Column * target_Rect.w;
	source_Rect.y = Row * target_Rect.h;

	g_pRenderlayer->add_Renderjob(this, renderlayer);
}



// animiertes Sprite-Objekt an den Renderlayer geben
void CSprite::Render (float frameNumber, int direction)						
{
	int Column = static_cast<int>(frameNumber)%numFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row =  direction;

	source_Rect.x = Column * target_Rect.w;
	source_Rect.y = Row * target_Rect.h;

	g_pRenderlayer->add_Renderjob(this, renderlayer);	
}


// Textur wird in den Renderer kopiert
void CSprite::RenderYourself() 
{
	if ((SDL_RenderCopy(texture->sdl_renderer, texture->sdl_texture, &source_Rect, &target_Rect)) < 0)				// Textur wird in der Renderer kopiert
	{
	cout << "Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}

// Position des Sprites festlegen
void CSprite::SetPos(int XPos, int YPos)
{
	target_Rect.x = XPos;
	target_Rect.y = YPos;
}


// SetPos mit floats
void CSprite::SetPos(float fXPos, float fYPos)
{
	target_Rect.x = static_cast<int>(fXPos);
	target_Rect.y = static_cast<int>(fYPos);
}
