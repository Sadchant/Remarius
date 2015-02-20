#ifndef RENDERLAYER_HPP
#define RENDERLAYER_HPP

#include "Renderable.hpp"
#include <list>

#define g_pRenderlayer CRenderlayer::Get()


class CRenderlayer : public TSingleton<CRenderlayer>
{
public:
	CRenderlayer();
	~CRenderlayer();
	void add_Renderjob(CRenderable* Renderable, Renderlayers Renderlayer);
	void Render();

private:
	SDL_Renderer*	Renderer;
	/*vector<CRenderable*>	Tile_Layer1_1;
	vector<CRenderable*>	Tile_Layer2_2;
	vector<CRenderable*>	Entity_Layer_3;
	vector<CRenderable*>	Ingametext_Layer_4;
	vector<CRenderable*>	GUI_Layer_5;
	vector<CRenderable*>	Menu_Layer_6;
	vector<CRenderable*>	Menubutton_Layer_7;
	vector<CRenderable*>	Text_Layer_8;*/
	static const int NUM_LAYERS = 8;

	list<CRenderable*>	Renderables[NUM_LAYERS]; // Array von Vectoren
};


#endif