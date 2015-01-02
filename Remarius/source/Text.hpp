#ifndef TEXT_HPP
#define TEXT_HPP

#include "Renderlayer.hpp"
#include <string>
#include <map>

class CText: public CRenderable
{
public:
	CText(Renderlayers renderlayer);
	CText(const CText& other);
	CText& operator = (const CText& other);
	~CText ();

	void		SetFont(TTF_Font* font){ this->font = font; }
	void		SetColor	(int R, int G, int B);
	void		SetAlpha	(int Alpha);
	void		SetContent	(string Content);
	void		Render();
	void		RenderYourself();
	static void	ReCreateAll();
	string		Get_content() { return content; }
	int			Get_length()	{ return target_Rect.w; }
	int			Get_height()	{ return target_Rect.h; }


private:
	void		CheckContent();
	void		createTexture();
	void		reCreateTexture();

	SDL_Renderer*	renderer;
	SDL_Texture*	texture;	// da kommt das Surface rein
	TTF_Font*		font;		// Schriftart, FREMDPOINTER
	SDL_Color		color;		// Farbe des Textes
	string			content;	// Inhalt des Textes
	Renderlayers	renderlayer;
	int				id;
	static int		id_counter;
	static map<int, CText*>	allTexts;

	
};
#endif
