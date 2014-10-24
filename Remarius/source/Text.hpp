#ifndef TEXT_HPP
#define TEXT_HPP


#include "Framework.hpp"
#include "Renderable.hpp"
#include <string>

class CText: public CRenderable
{
	public:
		CText ();
		CText(const CText& other);
		CText& operator = (const CText& other);
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
		int				Size;		// Gr��e des Textes
};
#endif
