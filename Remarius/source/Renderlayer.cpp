#include "Renderlayer.hpp"

CRenderlayer::CRenderlayer()
{
	int window_Width = g_pFramework->Get_window_Width();
	int window_Height = g_pFramework->Get_window_Height();
	Renderer = g_pFramework->GetRenderer();
	for (int i = 0; i < numTextures; i++)
	{
		if ((all_Textures[i] = SDL_CreateTexture(Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, window_Width, window_Height)) == NULL)
		{
			cout << "Fehler beim Erzeugen von Rendertextur " << i << ": " << SDL_GetError() << endl;
		}	
	}
	cout << "g_pRenderlayer erzeugt" << endl;
}

CRenderlayer::~CRenderlayer()
{
	for (int i = 0; i < numTextures; i++)
	{
		SDL_DestroyTexture(all_Textures[i]);
	}
}

SDL_Texture* CRenderlayer::GetTexture(TextureLayers TextureLayer)
{
	cout << "GetTexture aufgerufen!" << endl;
	cout << all_Textures[TextureLayer] << endl;
	cout << all_Textures[4] << endl;
	return all_Textures[TextureLayer];
	/*switch (TextureLayer)
	{
	case TILE_LAYER:
		return all_Textures[0];
		break;
	case ENTITY_LAYER:
		return all_Textures[1];
		break;
	case INGAMETEXT_LAYER:
		return all_Textures[2];
		break;
	case GUI_LAYER:
		return all_Textures[3];
		break;
	case MENU_LAYER:
		return all_Textures[4];
		break;
	case TEXT_LAYER:
		return all_Textures[5];
		break;
	default:
		return NULL;
	}*/
}

void CRenderlayer::Render()
{
	cout << "erster Versuch g_pRenderlayer zu rendern" << endl;
	for (int i = 0; i < numTextures; i++)
	{
		if (SDL_RenderCopy(Renderer, all_Textures[i], NULL, NULL) < 0)				// Textur wird in der Renderer kopiert
		{
			cout << "Fehler beim Kopieren der Textur " << i << ": " << SDL_GetError() << endl;
		}
	}
	g_pFramework->Render();
	cout << "erster Versuch g_pRenderlayer zu rendern -- fertig!" << endl;
}