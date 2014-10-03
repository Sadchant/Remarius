#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SDL.h>

class CMenuItem
{
public:
	virtual ~CMenuItem() {};
	virtual void render(int x, int y, bool b = false) = 0;
	virtual bool processEvent(SDL_KeyboardEvent& event) = 0;
};

#endif