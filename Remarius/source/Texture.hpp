#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "Framework.hpp"

class CTexture
{
public:
	CTexture(string filename);
	CTexture(const CTexture& other);
	CTexture& operator = (const CTexture& other);
	~CTexture();
	void Load();										// läd die Textur am gespeicherten Dateipfad
	void unLoad();										// entläd die Textur
	SDL_Texture* get();									// gibt die gespeicherte Textur zurück, läd neu falls NULL
	
protected:	
	SDL_Texture*	texture;							// gesamte Bilddatei als Textur

private:
	string			filename;
};

#endif
