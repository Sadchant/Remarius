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
	all_Texture_Files[0] = "Data/Baum_1.png";
	all_Texture_Files[1] = "Data/Bombo.png";
	all_Texture_Files[2] = "Data/Explosion.bmp";
	all_Texture_Files[3] = "Data/Hauptmenubuttons.png";
	all_Texture_Files[4] = "Data/Herzleiste.png";
	all_Texture_Files[5] = "Data/Laser.bmp";
	all_Texture_Files[6] = "Data/Menubuttons.png";
	all_Texture_Files[7] = "Data/MenuCheckBox.png";
	all_Texture_Files[8] = "Data/Menuhintergrund.png";
	all_Texture_Files[9] = "Data/Pausemenuhintergrund.png";
	all_Texture_Files[10] = "Data/Player.png";
	all_Texture_Files[11] = "Data/Remarius.png";
	all_Texture_Files[12] = "Data/Soundbalken.png";
	all_Texture_Files[13] = "Data/Soundbuttons.png";
	all_Texture_Files[14] = "Data/Soundschieber.png";
	all_Texture_Files[15] = "Data/Spider.png";
	all_Texture_Files[16] = "Data/Stacelstone.png";
	all_Texture_Files[17] = "Data/Texturset_1.png";
	all_Texture_Files[18] = "Data/Wall.png";
}


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
		all_Textures[i] = new CTexture(all_Texture_Files[i]);		
	}
}
