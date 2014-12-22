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
	void Load();										// l�d die Textur am gespeicherten Dateipfad
	void unLoad();										// entl�d die Textur
	SDL_Texture* get();									// gibt die gespeicherte Textur zur�ck, l�d neu falls NULL
	
protected:	
	SDL_Texture*	texture;							// gesamte Bilddatei als Textur

private:
	string			filename;
};

#endif
