#include "Text.hpp"

CText::CText(Renderlayers renderlayer)
{
	renderer = NULL;
	texture = NULL;
	surface = NULL;
	font = NULL;
	color = { 0 };

	this->renderlayer = renderlayer;
}

CText::CText(const CText& other) :
CRenderable(other)
{
	renderer = NULL;
	renderer = g_pFramework->GetRenderer();
	surface = NULL;
	texture = NULL;
	font = other.font;	
	color = other.color;
	renderlayer = other.renderlayer;
	SetContent(string(other.content));
}

CText& CText::operator = (const CText& other)
{
	CRenderable::operator=(other);
	renderer = NULL;
	renderer = g_pFramework->GetRenderer();
	surface = NULL;
	texture = NULL;
	font = other.font;	
	color = other.color;
	renderlayer = other.renderlayer;
	SetContent(string(other.content));
	return *this;
}

CText::~CText()																			// Surface des Sprites freigeben
{
	if (surface != NULL)
	{
		SDL_FreeSurface(surface);
	}
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
	}
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
	if (surface != NULL)
	{
		SDL_FreeSurface(surface);
	}		
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
	}
	renderer = g_pFramework->GetRenderer();
	const char* pContent = content.c_str();
	if (!content.empty())
	{
		if ((surface = TTF_RenderText_Blended(font, pContent, color)) == NULL)		// Surface wird gefüllt
		{
			cout << "Fehler beim erstellen des Text-Surface: " << TTF_GetError() << endl;
		}
		if ((texture = SDL_CreateTextureFromSurface(renderer, surface)) == 0)	// Surface wird in Textur umgewandelt
		{
			cout << "Fehler beim erstellen der Text-Textur: " << SDL_GetError() << endl;
		}
	}	
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
		cout << "CText::RenderYourself:Fehler beim Kopieren der Textur: " << SDL_GetError() << endl;
	}
}
