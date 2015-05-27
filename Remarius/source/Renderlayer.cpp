#include "Renderlayer.hpp"

CRenderlayer::CRenderlayer()
{
	Renderer = g_pFramework->GetRenderer();
}

CRenderlayer::~CRenderlayer()
{
}

void CRenderlayer::add_Renderjob(CRenderable* Renderable, Renderlayers Renderlayer)
{
	 Renderables[Renderlayer].push_back(Renderable);
}

void CRenderlayer::Render()
{
	for (int i = 0; i < NUM_LAYERS; i++) // geht durchs Array
	{
		while( Renderables[i].size() > 0) // geht durch eine liste
		{
			Renderables[i].front()->RenderYourself();
			Renderables[i].pop_front();
		}
	}
	g_pFramework->Render();
}