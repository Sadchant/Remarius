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
	for (int i = 0; i < NUM_LAYERS; i++)
	{
		for (unsigned j = 0; j < Renderables[i].size(); j++)
		{
			Renderables[i].at(j)->RenderYourself();
			Renderables[i].erase(Renderables[i].begin()+j);
		}
	}
	g_pFramework->Render();
}