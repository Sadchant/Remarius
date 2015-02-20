#include "Text.hpp"


// Initialisierung von static-Variablen
map<int, CText*> CText::allTexts;
int CText::id_counter = 0;

CText::CText(Renderlayers renderlayer)
{
	renderer = NULL;
	texture = NULL;
	font = NULL;
	color = { 0 };
	this->renderlayer = renderlayer;
	if (!allTexts.size())
		id_counter = 0;	
	else
		id_counter++;
	
	id = id_counter;
	allTexts[id] = this;		
}

CText::CText(const CText& other) :
CRenderable(other)
{
	renderer = NULL;
	renderer = g_pFramework->GetRenderer();
	texture = NULL;
	font = other.font;	
	color = other.color;
	renderlayer = other.renderlayer;
	SetContent(string(other.content));
	id_counter++;
	id = id_counter;
	allTexts[id] = this;
}

CText& CText::operator = (const CText& other)
{
	CRenderable::operator=(other);
	renderer = NULL;
	renderer = g_pFramework->GetRenderer();
	texture = NULL;
	font = other.font;	
	color = other.color;
	renderlayer = other.renderlayer;
	SetContent(string(other.content));
	id_counter++;
	id = id_counter;
	allTexts[id] = this;
	return *this;
}

CText::~CText()																			// Surface des Sprites freigeben
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
	}
	allTexts.erase(id);
}


// RGB-Wert der Farbe festlegen
void CText::SetColor (int r, int g, int b)										
{
	color.r = r;
	color.g = g;
	color.b = b;
	createTexture();
}


// Setzt den Alphawert der Farbe
void CText::SetAlpha(int Alpha)
{
	color.a = Alpha;
	createTexture();
}


// Inhalt festlegen und Breite und Höhe ermitteln
void CText::SetContent (string content)
{
	this->content = content;
	if (TTF_SizeText(font, content.c_str(), &target_Rect.w, &target_Rect.h))//ermittelt Breite und Höhe des Textes abhängig vom Inhalt
	{
		cout << TTF_GetError() << endl;
	}
	createTexture();
}


// Surface erzeugen und in die Textur überführen
void CText::createTexture()
{
	Uint32 startTime = SDL_GetTicks();
	//cout << "start: " << startTime << endl;

	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		//cout << SDL_GetError() << endl;
		texture = NULL;
	}
	renderer = g_pFramework->GetRenderer();
	const char* pContent = content.c_str();
	if (!content.empty())
	{
		//cout << "XXX: ";
		SDL_Surface* surface = NULL;
		if ((surface = TTF_RenderText_Blended(font, pContent, color)) == NULL)		// Surface wird gefüllt
		{
			cout << "Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
		SDL_FreeSurface(surface);
	}
	//cout << "ende: " << SDL_GetTicks()-startTime << endl;
}


// Textur in den Renderer laden
void CText::Render()
{
	g_pRenderlayer->add_Renderjob(this, renderlayer);
}

void CText::RenderYourself()
{
	if (SDL_RenderCopy(renderer, texture, NULL, &target_Rect) < 0)				// Textur wird in der Renderer kopiert
	{
		cout << "CText::RenderYourself: Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}


// läd Text neu, (nur von ReCreateAll aus aufrufen!)
void CText::reCreateTexture()
{
	renderer = g_pFramework->GetRenderer();
	const char* pContent = content.c_str();
	if (!content.empty())
	{
		SDL_Surface* surface = NULL;
		if ((surface = TTF_RenderText_Blended(font, pContent, color)) == NULL)		// Surface wird gefüllt
		{
			cout << "CText::reCreateTexture: Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "CText::reCreateTexture: Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
		SDL_FreeSurface(surface);
	}
}


// läd alle Texte neu (aufrufen, nachdem der Renderer zerstört wurde!)
void CText::ReCreateAll()
{
	map<int, CText*>::iterator it_allTexts;
	for (it_allTexts = allTexts.begin(); it_allTexts != allTexts.end(); it_allTexts++)
	{
		it_allTexts->second->reCreateTexture();
	}
}
