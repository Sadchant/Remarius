#ifndef RENDERLAYER_HPP
#define RENDERLAYER_HPP

#include "Framework.hpp"

#define g_pRenderlayer CRenderlayer::Get()

enum TextureLayers
	{
		TILE_LAYER,
		ENTITY_LAYER,
		INGAMETEXT_LAYER,
		GUI_LAYER,
		MENU_LAYER,
		TEXT_LAYER
	};

class CRenderlayer : public TSingleton<CRenderlayer>
{
public:
	CRenderlayer();
	~CRenderlayer();	
	SDL_Texture* GetTexture(TextureLayers TextureLayer);
	void Render();

private:
	static const int numTextures = 6;
	SDL_Texture*	all_Textures[numTextures];
	SDL_Renderer*	Renderer;
	







};


#endif