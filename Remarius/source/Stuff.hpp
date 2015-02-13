#ifndef Stuff_HPP
#define Stuff_HPP

#include "Player.hpp"
#include "Stachelstein.hpp"
#include "Hoover.hpp"
#include "Bombo.hpp"
#include "Hexaspider.hpp"
#include "Explosion.hpp"
#include "Tile.hpp"
#include "Debugscreen.hpp"
#include "Renderlayer.hpp"
#include "Loader.hpp"

#include "SpriteObject.hpp"
#include <string>




class CStuff
{
	public:
		CStuff	();
		void	init(fSDL_Rect *camera, int level_width, int level_y);
		void	Quit		();
		void	Update		();
		void	SetPlayer	(int Life, float X, float Y);
		void    RenderTiles ();
        bool    set_tiles       ();
		int		GetPlayerX		(){return m_pPlayer->GetX();}
		int		GetPlayerY		(){return m_pPlayer->GetY();}
		int		GetPlayerLife	(){return m_pPlayer->GetLife();}

	private:
		int level_width;
		int level_height;
		void	RenderMonsters	();
		void	CheckCollisions	();
		void	CommandSpawns	();
		bool	CkRect		(SDL_Rect a, SDL_Rect b);

		list<CStachelstein>	m_StachelsteinList;		// alle Stachelsteine
		list<CHoover>		m_HooverList;			// alle Staubsaugern
		list<CBombo>		m_BomboList;			// alle Bombos
		list<CExplosion>	m_ExplosionList;		// alle Explosionen
		list<CSpider>		m_SpiderList;			// alle Hexaspiders

		CPlayer				*m_pPlayer;

		CSprite				*m_pSpritePlayer;		// Sprite für Spieler
		CSprite				*m_pSpriteStachelstein;	// Sprite für Stachelstein
		CSprite				*m_pSpriteBombo;		// Sprite für Bombo
		CSprite				*m_pSpriteExplosion;	// Sprite für Explosion
		CSprite				*m_pSpriteHoover;		// Sprite für Staubsauger
		CSprite				*m_pSpriteSpider;		// Sprite für die Hexaspider

		fSDL_Rect*			camera;
		bool				m_bSpawnLock;			// Spawnlock für CommandSpawns();
};

#endif
