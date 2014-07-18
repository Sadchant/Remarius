#ifndef TEXT_HPP
#define TEXT_HPP

#include "SDL_ttf.h"
#include "Framework.hpp"
#include "Sprite.hpp"

class CText: public CSprite
{
	public:
		CText ();
		~CText ();

		void		Open		(const string sFilename, int Size);
		void		SetTextColor(int R, int G, int B);
		void		SetText		(const char *sentence);
		void		Render		(float TextxPos, float TextyPos);
		int			GetHigh() { return text_height; }
		int			GetLength()	{ return text_width; }

	private:
		SDL_Surface		*m_pTextcontent;	// Der eigentliche Text auf dem Bildschirm
		SDL_Rect		m_TextRect;			// Rect für den Text
		TTF_Font		*m_pFont;			// Schriftart
		SDL_Color		TextColor;			// Farbe des Textes
		float			text_xPos;			// x-Position des Textes
		float			text_yPos;			// y-Position des Textes
		int				text_height;
		int				text_width;
		
};






#endif
