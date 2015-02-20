#ifndef HOOVER_HPP
#define HOOVER_HPP
 
#include "Sprite.hpp"
 
class CHoover
{
  public:
	  CHoover();
	  void		Init	();
	  void		Update	();
	  void		Render	(float CameraX, float CameraY);
 
  private:
	  CSprite		hooverSprite;		// Zeiger auf Staubsauger-Sprite
	  float			m_fXPos;				// X-Position des Staubsaugers
	  float			m_fYPos;				// Y-Position des Staubsaugers
	  float			m_fDirection;			// Richtung; nach unten ist 0 (=1), gegen den Uhrzeigersinn
	  int			m_iSpriteDirection;		// Richtung des Sprites (0 = unten, gegen den Uhrzeigersinn, 7 = unten links)
	  int			animPhase;			// Akt. Animationsphase des Staubsaugers
	  bool			m_AnimFlipper;			// hochzählen oder runterzählen
	  float			m_fAnimCounter;			// Bei bestimmten Wert Animationsphase rendern
};
 
#endif