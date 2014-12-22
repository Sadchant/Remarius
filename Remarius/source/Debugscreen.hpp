#ifndef DEBUGSCREEN_HPP
#define DEBUGSCREEN_HPP

#include "Text.hpp"
#include "Singleton.hpp"
#include "Util.hpp"
#include <map>
#include <string>

#define g_pDebugscreen CDebugscreen::Get ()
class CDebugscreen : public TSingleton<CDebugscreen>
{
public:
	CDebugscreen	();
	~CDebugscreen();
	void		Set			(string pText);						// erzeugt ein DebugItem für die Map und macht es bei erneutem Aufruf wieder sichtbar
	void		Set			(string pText, float Variable);		// zusätzliche Variable, die ausgegeben werden kann
	void		FPS			(int FPS);							// zum Updaten der FPS-Anzeige
	void		Render		();									// rendert die gesamte Map mit allen sicht baren DebugItems

private:
	struct DebugItem {
		CText* pTextObject = new CText(TEXT_LAYER);				// das Text-Objekt, was dann auf den Bildschirm kommt
		float fTime;									// die Zeit, die vergangen ist seitdem das Item gerendert wurde (zum Ausblenden)
		bool visible = false;							// ob es sichtbar ist oder nicht (wird nach Ablaufen einer gewissen Zeit unsichtbar)
		bool always;									// ob es jeden Tick gerendert werden soll
	};	
	int Rows;									// zählt die Zeilen
	map<string, DebugItem>					Messages;		// Map mit DebugItems
	map<string, DebugItem>::iterator		itMessages;		// Iterator für die Map	
	TTF_Font*	pFont;
};

#endif