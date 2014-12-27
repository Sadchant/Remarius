#ifndef LOADER_HPP
#define LOADER_HPP

#include "Framework.hpp"
#include "Singleton.hpp"
#include "Texture.hpp"

#define g_pLoader CLoader::Get()

enum Textures
{
	BAUM_1,
	BOMBO,
	EXPLOSION,
	HAUPTMENUBUTTONS,
	HERZLEISTE,
	LASER,
	MENUBUTTONS,
	MENUCHECKBOX,
	MENUHINTERGRUND,
	PAUSEMENUHINTERGRUND,
	PLAYER,
	REMARIUS,
	SOUNDBALKEN,
	SOUNDBUTTONS,
	SOUNDSCHIEBER,
	SPIDER,
	STACELSTONE,
	TEXTURSET1,
	WALL
};

class CLoader : public TSingleton<CLoader>
{
public:
	CLoader();
	~CLoader();
	void Reload_Textures();
	CTexture* GetTexture(Textures Texture) { return all_Textures[Texture]; }

private:
	struct TextureKonstruktor
	{
		string filename;
		Renderlayers renderlayer;
		int frameWidth;
		int frameHeight;
	};
	void SetTextureFiles();
	void LoadTextures();
	static const int NUMTEXTURES = 19;

	CTexture* all_Textures[NUMTEXTURES];
	TextureKonstruktor all_Texture_Files[NUMTEXTURES];
	int all_Texture_NUMFRAMES[NUMTEXTURES];

};

#endif