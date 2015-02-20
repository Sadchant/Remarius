#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <SDL.h>
#define SAFE_DELETE(X) {if (X != NULL) { delete (X); X = NULL;} }


class CMenuItem
{
public:
	virtual ~CMenuItem() {};
	virtual void render(bool b = false) = 0;
	virtual bool processEvent(SDL_KeyboardEvent& event) = 0;
	virtual void setPos(int x, int y) { xPos = x; yPos = y;	}

protected:
	int xPos; int yPos;
};

#endif