#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include "Text.hpp"

typedef void(*MenuItemFKT)();

static TTF_Font* OpenFont(string filename, int size, bool bold = false, bool italic = false)
{
	TTF_Font* font = TTF_OpenFont(filename.c_str(), size);
	if (font == NULL)
	{
		cout << "Fehler beim Laden von: " << filename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << TTF_GetError() << endl;
		g_pFramework->Quit();
		exit(1);
	}
	if (bold) TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	if (italic) TTF_SetFontStyle(font, TTF_STYLE_ITALIC);
	return font;
}

#endif