#ifndef LOADER_HPP
#define LOADER_HPP

#include "Framework.hpp"
#include "Singleton.hpp"
#include "Texture.hpp"
#include <map>
#include <fstream>
#include <string>

#define g_pLoader CLoader::Get()

class CLoader : public TSingleton<CLoader>
{
public:
	CLoader();
	~CLoader();
	CTexture* getTexture(string id) { return textures[id].texture; }

	void load(string id);											// erzeugt f�r id eine CTexture-Instanz
	
	void loadAll();													// erzeugt f�r alle id's eine CTexture-Instanz
	void reloadTextures();											// L�d Texturen neu (bei �nderungen im Renderer)

private:
	struct TextureWrapper
	{
		string filename;
		Renderlayers renderlayer;
		int frameWidth;
		int frameHeight;
		CTexture* texture;
	};
	map<string, TextureWrapper> textures;
	static void splitstr(string line, string* result);				// Zerteilt Line bei jedem ' ' und schreibt die St�cke in result
	static Renderlayers decodeRenderlayer(string rl);				// Gibt zu einem String das passende Renderlayer-Enum zur�ck (Textlayer bei keinem match)
};

#endif