#include "Camera.hpp"
#include <iostream>
using namespace std;


CCamera::CCamera ()
{
	Camera.x = 0;
	Camera.y = 0; 
	Camera.w = 1280;
	Camera.h = 720; 


}

void CCamera::SetPos (float x, float y)
{
	Camera.x = static_cast<Sint16>(x);
	Camera.y = static_cast<Sint16>(y);
}

void CCamera::CorrectPos (int x, int y)
{
	if (Camera.x < 0)
		Camera.x = 0;
	if (Camera.y < 0)
		Camera.y = 0;

	if (Camera.x > x - 1280)
		Camera.x = x - 1280;
	if (Camera.y > y - 720)
		Camera.y = y - 720;
}