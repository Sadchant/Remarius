#ifndef TEXT_HPP
#define TEXT_HPP


#include "Framework.hpp"
#include "Sprite.hpp"
#include <string>

class CText: public CSprite
{
	public:
		CText ();
		CText(const CText& other);
		~CText ();

		void		SetFont(TTF_Font* font){ pFont = font; }
		void		SetColor	(int R, int G, int B);
		void		SetAlpha	(int Alpha);
		void		SetContent	(string Content);
		string		GetContent() { return Content; }
		int			GetHigh()	{ return height; }
		int			GetLength()	{ return width; }

	private:
		void		CheckContent();
		void		createTexture();
		SDL_Surface*	pSurface;	// Der eigentliche Text auf dem Bildschirm
		TTF_Font*		pFont;		// Schriftart
		SDL_Color		Color;		// Farbe des Textes
		string			Content;	// Inhalt des Textes
		int				Size;		// Größe des Textes
};
#endif
