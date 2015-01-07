#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
 
#include "Sprite.hpp"
 
class CExplosion
{
  public:
	  CExplosion	(int XPos, int YPos);
	  void		Render	(float CameraX, float CameraY);
	  SDL_Rect	GetRect	(){return m_Rect;}
	  bool		IsAlive	(){return m_bIsAlive;}
	  bool		IsActive(){return m_bActive;}
	  int		GetX	(){return m_XPos;}
	  int		GetY	(){return m_YPos;}
 
  private:
	  CSprite		explosionSprite;	// Zeiger auf Explosions-Sprite
	  int			m_XPos;				// X-Position der Explosion
	  int			m_YPos;				// Y-Position der Explosion
	  SDL_Rect		m_Rect;					// Rect des Staubsaugers
	  bool			m_bIsAlive;				// zur Explosionslöschung
	  bool			m_bActive;				// Wenn die Explosion keinen Schaden mehr macht
	  float			m_fDuration;			// Dauer der Explosion
	  int			m_StateExplosion;		// Bild, das angezeigt wird; nach 16 ist schluss
};
 
#endif