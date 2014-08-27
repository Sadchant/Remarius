#ifndef TEXT_HPP
#define TEXT_HPP


#include "Framework.hpp"
#include "Sprite.hpp"

class CText: public CSprite
{
	public:
		CText ();
		~CText ();

		void		OpenFont	(const string sFilename, int Size);
		void		SetColor	(int R, int G, int B);
		void		SetContent	(char* Content);
		void		Render		();
		int			GetHigh()	{ return height; }
		int			GetLength()	{ return width; }

	private:
		SDL_Surface*	pSurface;	// Der eigentliche Text auf dem Bildschirm
		TTF_Font*		pFont;		// Schriftart
		SDL_Color		Color;		// Farbe des Textes
		const char*		pContent;	// Inhalt des Textes
		int				Size;		// Größe des Textes
};
#endif
