#include "Sprite.hpp"

CSprite::CSprite(CTexture* texture)
{
	renderlayer = texture->renderlayer;

	source_Rect = { 0 };
	source_Rect.w = texture->frameWidth;
	source_Rect.h = texture->frameHeight;
	target_Rect.w = texture->frameWidth;
	target_Rect.h = texture->frameHeight;

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
void CSprite::Render (int frameNumber)										
{
	int Column = frameNumber % numFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
	int Row = frameNumber / numFramesX;

	source_Rect.x = Column * target_Rect.w;
	source_Rect.y = Row * target_Rect.h;

	g_pRenderlayer->add_Renderjob(this, renderlayer);
}



// animiertes Sprite-Objekt an den Renderlayer geben
void CSprite::Render (int frameNumber, int direction)						
{
	int Column = frameNumber % numFramesX;					// Ausschnitt der aktuellen Animationsphase berechnen
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
		cout << "CSprite::RenderYourself: Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}

Point CSprite::GetTextureDimensions()
{
	Point dimensions;
	SDL_QueryTexture(texture->sdl_texture, NULL, NULL, &dimensions.x, &dimensions.y);
	return dimensions;
}