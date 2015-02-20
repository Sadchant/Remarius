#include "Renderable.hpp"

CRenderable::CRenderable()
{
	target_Rect = { 0 };
}


// Position des Sprites festlegen
void CRenderable::SetPos(int XPos, int YPos)
{
	target_Rect.x = XPos;
	target_Rect.y = YPos;
}


// SetPos mit floats
void CRenderable::SetPos(float fXPos, float fYPos) 
{
	target_Rect.x = static_cast<int>(fXPos);
	target_Rect.y = static_cast<int>(fYPos);
}


