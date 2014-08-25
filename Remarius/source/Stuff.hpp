#ifndef Stuff_HPP
#define Stuff_HPP

#include "Player.hpp"
#include "Stachelstein.hpp"
#include "Hoover.hpp"
#include "Bombo.hpp"
#include "Hexaspider.hpp"
#include "Explosion.hpp"
#include "Tile.hpp"
#include <string>
#include <fstream>
#include <sstream>

class CStuff
{
	public:
		CStuff	();

		void	Quit		();
		void	Update		();
		void	SetPlayer	(int Life, float X, float Y);
		void    show            ();
        bool    set_tiles       ();
		int		GetPlayerX		(){return m_pPlayer->GetX();}
		int		GetPlayerY		(){return m_pPlayer->GetY();}
		int		GetPlayerLife	(){return m_pPlayer->GetLife();}

	private:
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

		CSprite				*m_pSpritePlayer;		// Sprite f�r Spieler
		CSprite				*m_pSpriteStachelstein;	// Sprite f�r Stachelstein
		CSprite				*m_pSpriteBombo;		// Sprite f�r Bombo
		CSprite				*m_pSpriteExplosion;	// Sprite f�r Explosion
		CSprite				*m_pSpriteHoover;		// Sprite f�r Staubsauger
		CSprite				*m_pSpriteSpider;		// Sprite f�r die Hexaspider
		CSprite				*m_pSpriteWall;

		CCamera				*m_pCamera;
		bool				m_bSpawnLock;			// Spawnlock f�r CommandSpawns();
		static const int	TILE_WIDTH=45; 
		static const int	TILE_HEIGHT=45; 
		static const int	TOTAL_TILES=49284; 
		static const int	LEVEL_WIDTH=9990;  
		static const int	LEVEL_HEIGHT=9990; 
		static const int	TILE_SPRITES = 32; 
        CSprite				*m_pSpriteTile;
        CTile				*tiles[ TOTAL_TILES ];
        list <CTile>		tiles2;
        list <CTile>		tiles3;
        list <CTile>		tiles4;
};

#endif