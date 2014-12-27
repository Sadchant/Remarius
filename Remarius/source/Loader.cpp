#include "Loader.hpp"

CLoader::CLoader()
{
	ifstream fis("Data/meta.txt");
	if (fis.is_open())
	{
		string line;
		while (!fis.eof())
		{
			getline(fis, line);
			string values[5];
			//splitstr(line, values);
			string* result = values;
			int pos = line.find(' ');
			while (pos != string::npos)
			{
				*result = line.substr(0, pos);
				result++;
				line = line.substr(pos + 1, line.length() - 1);
				pos = line.find(' ');
			}
			*result = line;
			//splitstr end (Linkerfehler bei Funktionsaufruf?)
			TextureWrapper tx = {
				values[1],							// Dateipfad
				decodeRenderlayer(values[2]),		// Renderlayer
				stoi(values[3]),					// Frame-Breite
				stoi(values[4]),					// Frame-Höhe
				NULL };								// CTexture-Pointer
			textures.insert(pair<string, TextureWrapper>(values[0], tx));
		}
		fis.close();
	}
	loadAll();
}

CLoader::~CLoader()
{
}

void CLoader::load(string id)
{
	TextureWrapper tx = textures[id];
	if (tx.texture == NULL)
		textures[id].texture = new CTexture(tx.filename, tx.renderlayer, tx.frameWidth, tx.frameHeight);
}

void CLoader::loadAll()
{
	for (map<string, TextureWrapper>::iterator it = textures.begin(); it != textures.end(); it++)
	{
		load(it->first);
	}
}

void CLoader::reloadTextures()
{
	for (map<string, TextureWrapper>::iterator it = textures.begin(); it != textures.end(); it++)
	{
		if (it->second.texture != NULL)
			it->second.texture->Load();
	}
}

void splitstr(string line, string* result)
{
	int pos = line.find(' ');
	while (pos != string::npos)
	{
		*result = line.substr(0, pos);
		result++;
		line = line.substr(pos + 1, line.length() - 1);
		pos = line.find(' ');
	}
	*result = line;
}

Renderlayers CLoader::decodeRenderlayer(string rl)
{
	if (rl == "TILE_LAYER1") return TILE_LAYER1;
	if (rl == "TILE_LAYER2") return TILE_LAYER2;
	if (rl == "ENTITY_LAYER") return ENTITY_LAYER;
	if (rl == "INGAMETEXT_LAYER") return INGAMETEXT_LAYER;
	if (rl == "GUI_LAYER") return GUI_LAYER;
	if (rl == "MENU_LAYER") return MENU_LAYER;
	if (rl == "MENUBUTTON_LAYER") return MENUBUTTON_LAYER;
	if (rl == "TEXT_LAYER") return TEXT_LAYER;
	return TEXT_LAYER;
}