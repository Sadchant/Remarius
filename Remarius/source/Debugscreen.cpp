#include "Debugscreen.hpp"

CDebugscreen::CDebugscreen()
{
	Rows = 1;
	pFont = OpenFont("Data/verdana.ttf", 15, true);

	DebugItem FPS_Word;														// Die FPS-Anzeige, hier das Wort "FPS" wird erzeugt und in die Map geschrieben
	FPS_Word.pTextObject->SetFont(pFont);
	FPS_Word.pTextObject->SetContent("FPS:");
	FPS_Word.pTextObject->SetColor(255, 255, 255);
	FPS_Word.pTextObject->SetPos(930, 13);
	FPS_Word.visible = true;
	FPS_Word.fTime = 0.0f;
	FPS_Word.always = true;
	Messages["FPS:"] = FPS_Word;

	DebugItem FPS;															// Die eigentliche FPS-Zahl wird erzeugt und mit 0 initialisiert
	FPS.pTextObject->SetFont(pFont);
	FPS.pTextObject->SetContent("0");
	FPS.pTextObject->SetColor(255, 255, 255);
	FPS.pTextObject->SetPos(970, 13);
	FPS.visible = true;
	FPS.fTime = 0.0f;
	FPS.always = true;
	Messages["FPS"] = FPS;
}
CDebugscreen::~CDebugscreen()
{
	TTF_CloseFont(pFont);
}

// erzeugt ein DebugItem für die Map und macht es bei erneutem Aufruf wieder sichtbar
void CDebugscreen::Set(string Text)	
{	
	itMessages = Messages.find(Text);
	if (itMessages != Messages.end())										// Wenn sie schon in der Map, war, wird visible auf "true" gesetzt
	{
		itMessages->second.visible = true;
		itMessages->second.fTime = 0.0;
	}
	else																	// War sie noch nicht in der Map, wird sie erzeugt
	{	
		DebugItem Item;			
		Item.pTextObject->SetFont(pFont);
		const char* pText = Text.c_str();
		Item.pTextObject->SetContent(pText);
		Item.pTextObject->SetColor(255, 255, 255);
		Item.pTextObject->SetPos(13, 57+18*Rows);
		Item.visible = true;
		Item.fTime = 0.0f;
		Rows+=1;
		Item.always = false;
		Messages[Text] = Item;		
	}	
}

// SetFunktion mit zusätzlicher Variable, die ausgegeben werden kann
void CDebugscreen::Set(string Text, float Variable)
{
	string vText = "V" + Text;												// Name für die Variable in der Map
	string sVariable = to_string(Variable);
	const char* Variable_Text = sVariable.c_str();

	itMessages = Messages.find(Text);
	if (itMessages != Messages.end())
	{
		itMessages->second.visible = true;
		itMessages->second.fTime = 0.0;
		itMessages->second.pTextObject->SetColor(255, 255, 255);
	}
	else
	{
		DebugItem Item;
		Item.pTextObject->SetFont(pFont);
		const char* pText = Text.c_str();
		Item.pTextObject->SetContent(pText);
		Item.pTextObject->SetColor(255, 255, 255);
		Item.pTextObject->SetPos(13, 57 + 18 * Rows);
		Item.visible = true;
		Item.fTime = 0.0f;		
		Item.always = true;
		Messages[Text] = Item;

		DebugItem dVariable;																	// Die Variable wird als DebugItem erzeugt und in die Map gelegt
		dVariable.pTextObject->SetFont(pFont);
		dVariable.pTextObject->SetContent(Variable_Text);
		dVariable.pTextObject->SetColor(255, 255, 255);
		dVariable.pTextObject->SetPos(13 + Item.pTextObject->Get_length() + 5, 57 + 18 * Rows);
		dVariable.visible = true;
		dVariable.fTime = 0.0f;
		dVariable.always = true;		
		Messages[vText] = dVariable;
		
		Rows += 1;																				// der Zähler wird nur um 1 erhöht, da die Variable nicht in einer neuen Zeile gerndert wird
	}
	itMessages = Messages.find(vText);
	if (itMessages != Messages.end())															// Wird die Variable in der Map gefunden, muss bei erneutem Aufruf von Set nur der Wert geupdatet werden
	{
		itMessages->second.pTextObject->SetContent(Variable_Text);
	}	
}

// bringt bei jedem Aufruf der Funktion die aktuelle FPS-Zahl in die Map
void CDebugscreen::FPS(int FPS)																	
{
	itMessages = Messages.find("FPS");
	string sFPS = to_string(FPS);
	const char* pText = sFPS.c_str();
	itMessages->second.pTextObject->SetContent(pText);
}

// rendert alle Bestandteile der Map, die entweder visible sind oder jeden Gameloop gerendert werden sollen
void CDebugscreen::Render()	
{
	for (itMessages = Messages.begin(); itMessages != Messages.end(); itMessages++)	
	{
		if (itMessages->second.always || itMessages->second.visible)
		{
			itMessages->second.pTextObject->Render();
		}
		itMessages->second.fTime += g_pTimer->GetElapsed();							// rechnet die Zeit aus, die vergangen ist, seitdem die Message zum ersten mal gerendert wurde		
		if (itMessages->second.fTime > 0.7f)										// sollte der Mapeintrag vor 0.7 Sekunden das erste Mal gerendert worden sein, wird visible auf false gesetzt
		{
			itMessages->second.visible = false;
		}		
	}
}