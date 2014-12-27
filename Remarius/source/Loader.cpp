#include "Loader.hpp"

CLoader::CLoader()
{
	SetTextureFiles();
	LoadTextures();
}

CLoader::~CLoader()
{
	for (int i = 0; i < NUMTEXTURES; i++)
	{
		all_Textures[i]->~CTexture();
	}
}

void CLoader::SetTextureFiles()
{
	all_Texture_Files[0] = { "Data/Baum_1.png", ENTITY_LAYER, 260, 244 };

	all_Texture_Files[1] = { "Data/Bombo.png", ENTITY_LAYER, 86, 90 };
	all_Texture_Files[2] = { "Data/Explosion.bmp", ENTITY_LAYER, 240, 240 };
	all_Texture_Files[3] = { "Data/Hauptmenubuttons.png", MENUBUTTON_LAYER, 356, 66 };
	all_Texture_Files[4] = { "Data/Herzleiste.png", GUI_LAYER, 14, 30 };
	all_Texture_Files[5] = { "Data/Laser.bmp", ENTITY_LAYER, 64, 64 };
	all_Texture_Files[6] = { "Data/Menubuttons.png", MENUBUTTON_LAYER, 301, 65 };
	all_Texture_Files[7] = { "Data/MenuCheckBox.png", MENUBUTTON_LAYER, 65, 65 };
	all_Texture_Files[8] = { "Data/Menuhintergrund.png", MENU_LAYER, 1280, 720 };
	all_Texture_Files[9] = { "Data/Pausemenuhintergrund.png", MENU_LAYER, 755, 570 };
	all_Texture_Files[10] = { "Data/Player.png", ENTITY_LAYER, 64, 64 };
	all_Texture_Files[11] = { "Data/Remarius.png", ENTITY_LAYER, 74, 100 };
	all_Texture_Files[12] = { "Data/Soundbalken.png", MENUBUTTON_LAYER, 140, 6 };
	all_Texture_Files[13] = { "Data/Soundbuttons.png", MENUBUTTON_LAYER, 65, 65 };
	all_Texture_Files[14] = { "Data/Soundschieber.png", MENUBUTTON_LAYER, 19, 29 };
	all_Texture_Files[15] = { "Data/Spider.png", ENTITY_LAYER, 130, 97 };
	all_Texture_Files[16] = { "Data/Stacelstone.png", ENTITY_LAYER, 64, 44 };
	all_Texture_Files[17] = { "Data/Texturset_1.png", TILE_LAYER1, 45, 45 };
	all_Texture_Files[18] = { "Data/Wall.png", TILE_LAYER2, 45, 45 };
}

/*CTexture* GetTexture(Textures Texture)
{


}*/
// läd alle Texturen neu
void CLoader::Reload_Textures()
{
	for (int i = 0; i < NUMTEXTURES; i++)
	{
		all_Textures[i]->Load();
	}
}

// erzeugt alle Textur-Objekte
void CLoader::LoadTextures()
{
	for (int i = 0; i < NUMTEXTURES; i++)
	{
		all_Textures[i] = new CTexture(all_Texture_Files[i].filename, 
			all_Texture_Files[i].renderlayer,
			all_Texture_Files[i].frameWidth,
			all_Texture_Files[i].frameHeight);
	}
}
