#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Framework.hpp"

class CCamera
{
	public:
		CCamera		();
		void		SetPos (float x, float y);
		void		CorrectPos (int x, int y);
		SDL_Rect	GetCameraRect () {return Camera;}

	private:
		SDL_Rect	Camera;    
};

#endif
