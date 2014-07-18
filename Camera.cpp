#include "Camera.hpp"
#include <iostream>
using namespace std;


CCamera::CCamera ()
{
	Camera.x = 0;
	Camera.y = 0; 
	Camera.w = 1024;
	Camera.h = 768; 


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

	if (Camera.x > x - 1024)
		Camera.x = x - 1024;
	if (Camera.y > y - 768)
		Camera.y = y - 768;
}