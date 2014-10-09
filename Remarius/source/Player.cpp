#include "Player.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

CPlayer::CPlayer ()													// Player initialisieren
{
	m_pSpriteMonster = NULL;												// Sprites Laden
	m_pSpriteMonster = new CSprite;
	//m_pSpriteMonster->Load ("Data/Player.png", 48, 64, 64);
	m_pSpriteMonster->Load("Data/Remarius.png", 56, 74, 100);


	m_pSpriteShot = NULL;
	m_pSpriteShot = new CSprite;
	m_pSpriteShot->Load ("Data/Laser.bmp", 0, 64, 64);

	m_pSpriteLife = NULL;
	m_pSpriteLife= new CSprite;
	m_pSpriteLife->Load("Data/Herzleiste.png", 6, 14, 30);

	Reset();
}

void CPlayer::Quit ()												// Sprites freigeben
{
	if (m_pSpriteMonster != NULL)
	{
		delete (m_pSpriteMonster);
		m_pSpriteMonster = NULL;
	}
	
	if (m_pSpriteLife != NULL)
	{
		delete (m_pSpriteLife);
		m_pSpriteLife=NULL;
	}
}

void CPlayer::Reset ()												// "Spawnen"
{
	m_fXPos = 376.0f;													// Startposition des Spielers
	m_fYPos = 520.0f;
	m_SpriteDirection = 0;
	m_fDamageTimer = 1.0f;

	m_maxLife = 16;														// Leben einstellen
	m_Life = 6;

	m_Rect.x = static_cast<int>(m_fXPos);								// Rect initialisieren
	m_Rect.y = static_cast<int>(m_fYPos);
	m_Rect.w = 64;
	m_Rect.h = 64;

	m_AttackRect.x = 0;
	m_AttackRect.y = 0;
	m_AttackRect.w = 0;
	m_AttackRect.h = 0;

	m_fAnimPhase = 0.0f;
	m_fLifeAnimphase = 0.0f;

	m_bToolLock = false;												// Locks auflösen
	m_bLifeLock = false;
}
void CPlayer::Render (float CameraX, float CameraY)												// Spieler und Schüsse rendern
{
	m_pSpriteMonster->SetScreenPos (m_fXPos, m_fYPos, CameraX, CameraY);// Spielersprite setzen
	m_SpriteDirection = static_cast<int>(m_fDirection * 8 + 0.5f) % 8;
	m_pSpriteMonster->Render (m_fAnimPhase, m_SpriteDirection);
	
	list<CShot>::iterator it = m_ShotList.begin ();						// Iterator für Schüsse
	while (it != m_ShotList.end ())
	{
		
		it->Update ();														// Schuss updaten
		if (it->IsAlive ())													// Wenn noch lebt, dann rendern
		{
			it->Render (CameraX, CameraY);
			it++;
		} else																// Sonst freigeben
			it = m_ShotList.erase (it);
	}
}
void CPlayer::LifeRender ()											// Lebensanzeige rendern
{
	m_fLifeAnimphase +=  g_pTimer->GetElapsed ();						// AnimPhase erhöhen/resetten
	if (m_fLifeAnimphase > 1.0f)
		m_fLifeAnimphase = 0.0f;

	for (int i = m_maxLife; i > m_Life; i--)							// leere Herzen rendern
	{
		m_pSpriteLife->SetPos(static_cast<float>(-1+i*14), 13.0f);
		m_pSpriteLife->Render(static_cast<float>(5-i%2));
	}

	for (int i = 1; i <= m_Life; i++)									// volle Herzen rendern
	{
		m_pSpriteLife->SetPos(static_cast<float>(-1+14*i), 13.0f);		
		if (((i == m_Life-1) && (i%2 == 1)) || (i == m_Life))				// Wenn letzte Herzhälfte oder (vorletzte und ungerade)
		{
			if (m_fLifeAnimphase < 0.5f)										// Rendern nach AnimPhase
				m_pSpriteLife->Render(static_cast<float>(1-i%2));
			else
				m_pSpriteLife->Render(static_cast<float>(3-i%2));
		} else m_pSpriteLife->Render(static_cast<float>(1- i%2));			// Ansonsten unanimierte Herzhälfte rendern
	}
}
void CPlayer::Update ()												// Spieler updaten
{
	ProcessMoving ();													// Bewegen

	m_Rect.y = static_cast<int>(m_fYPos);								// Rect anpassen
	m_Rect.x = static_cast<int>(m_fXPos);

	if (IsAttack()) m_fAttackTimer -= g_pTimer->GetElapsed();
	if (m_fKnockbackDuration >= 0.0f) m_fKnockbackDuration -= g_pTimer->GetElapsed();
	if (m_fDamageTimer > 0.0f) m_fDamageTimer -= g_pTimer->GetElapsed() / 2;

	ProcessTools ();													// Prüfen, ob geschossen wurde

	CheckPosition ();													// Position und Animationsphase überprüfen
	g_pDebugscreen->Set("x-Position: ", m_fXPos);
}
void CPlayer::ProcessMoving ()										// Spieler bewegen
{
	if ((g_pFramework->KeyDown(SDL_SCANCODE_UP) && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)) || (g_pFramework->KeyDown(SDL_SCANCODE_LEFT) && (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))))
		m_bBlock = true;
	else m_bBlock = false;

	if (!m_bBlock)
	{
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP))
			if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
				m_fDirection = 0.625f;
			else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
				m_fDirection = 0.375f;
			else m_fDirection = 0.5f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_DOWN))
			if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
				m_fDirection = 0.875f;
			else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
				m_fDirection = 0.125f;
			else m_fDirection = 0.0f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
			m_fDirection = 0.75f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
			m_fDirection = 0.25f;
		
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP) || g_pFramework->KeyDown(SDL_SCANCODE_DOWN) || g_pFramework->KeyDown(SDL_SCANCODE_LEFT) || g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
		{
			m_fXPos += static_cast<float>(170.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
			m_fYPos += static_cast<float>(170.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
			m_fAnimPhase += 10.0f * g_pTimer->GetElapsed ();
		}
	}

	if (g_pFramework->KeyDown(SDL_SCANCODE_LCTRL) && m_bLifeLock == false)								// Wenn Heiltaste
		{
			if (m_Life<m_maxLife) {m_Life++;}
			m_bLifeLock = true;
		} else if (g_pFramework->KeyDown(SDL_SCANCODE_RCTRL) && m_bLifeLock == false)					// ansonsten Wenn Schadenstaste
		{
			if (m_Life>5) {m_Life--;}
			m_bLifeLock = true;
		} 
		if (g_pFramework->KeyDown(SDL_SCANCODE_LCTRL)==false && g_pFramework->KeyDown(SDL_SCANCODE_RCTRL)==false)
			m_bLifeLock = false;																// wenn keins von beiden, dann Lifelock aus
}

void CPlayer::ProcessMoving (float Speed)										// Spieler bewegen
{
	if ((g_pFramework->KeyDown(SDL_SCANCODE_UP) && g_pFramework->KeyDown(SDL_SCANCODE_DOWN)) || (g_pFramework->KeyDown(SDL_SCANCODE_LEFT) && (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))))
		m_bBlock = true;
	else m_bBlock = false;

	if (!m_bBlock)
	{
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP))
			if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
				m_fDirection = 0.625f;
			else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
				m_fDirection = 0.375f;
			else m_fDirection = 0.5f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_DOWN))
			if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
				m_fDirection = 0.875f;
			else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
				m_fDirection = 0.125f;
			else m_fDirection = 0.0f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_LEFT))
			m_fDirection = 0.75f;
		else if (g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
			m_fDirection = 0.25f;
		
		if (g_pFramework->KeyDown(SDL_SCANCODE_UP) || g_pFramework->KeyDown(SDL_SCANCODE_DOWN) || g_pFramework->KeyDown(SDL_SCANCODE_LEFT) || g_pFramework->KeyDown(SDL_SCANCODE_RIGHT))
		{
			m_fXPos += static_cast<float>(Speed * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
			m_fYPos += static_cast<float>(Speed * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
			m_fAnimPhase += 20.0f * g_pTimer->GetElapsed ();
		}
	}

	if (g_pFramework->KeyDown(SDL_SCANCODE_LCTRL) && m_bLifeLock == false)								// Wenn Heiltaste
		{
			if (m_Life<m_maxLife) {m_Life++;}
			m_bLifeLock = true;
		} else if (g_pFramework->KeyDown(SDL_SCANCODE_RCTRL) && m_bLifeLock == false)					// ansonsten Wenn Schadenstaste
		{
			if (m_Life>5) {m_Life--;}
			m_bLifeLock = true;
		} 
		if (g_pFramework->KeyDown(SDL_SCANCODE_LCTRL)==false && g_pFramework->KeyDown(SDL_SCANCODE_RCTRL)==false)
			m_bLifeLock = false;																// wenn keins von beiden, dann Lifelock aus
}

void CPlayer::ProcessTools ()									// Schießen
{
	m_fAttackTimer -= g_pTimer->GetElapsed();

	if (!m_bToolLock)
	{
		m_bToolLock = true;
		if (g_pFramework->KeyDown(SDL_SCANCODE_C))
		{
			CShot Shot(m_pSpriteShot, m_fXPos, m_fYPos);
			m_ShotList.push_back (Shot);
		}
		else if (g_pFramework->KeyDown(SDL_SCANCODE_X))
		{
			if (m_SpriteDirection % 2 == 1)
			{
				m_AttackRect.w = 64;
				m_AttackRect.h = 64;
			} else if (m_SpriteDirection == 0 || m_SpriteDirection == 4)
			{
				m_AttackRect.w = 128;
				m_AttackRect.h = 32;
			} else
			{
				m_AttackRect.w = 32;
				m_AttackRect.h = 128;
			}

			switch (m_SpriteDirection)
			{
			case 0:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) - 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) + 64;
				} break;
			case 1:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) + 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) + 32;
				} break;
			case 2:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) + 64;
					m_AttackRect.y = static_cast<int>(m_fYPos) - 32;
				} break;
			case 3:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) + 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) - 32;
				} break;
			case 4:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) - 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) - 32;
				} break;
			case 5:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) - 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) - 32;
				} break;
			case 6:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) - 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) - 32;
				} break;
			case 7:
				{
					m_AttackRect.x = static_cast<int>(m_fXPos) - 32;
					m_AttackRect.y = static_cast<int>(m_fYPos) + 32;
				} break;
			}
			m_fAttackTimer = 0.1f;
		} else m_bToolLock = false;
	} else if (!g_pFramework->KeyDown(SDL_SCANCODE_C) && !g_pFramework->KeyDown(SDL_SCANCODE_X))
		m_bToolLock = false;

}

void CPlayer::CheckPosition ()
{
   if (m_fXPos < 0.0f)  
      m_fXPos = 0.0f;
   else if (m_fXPos > Map_Width)
      m_fXPos = static_cast<float>(Map_Width);
   if (m_fYPos < 0.0f)  
      m_fYPos = 0.0f;
   else if (m_fYPos > (Map_Height))
      m_fYPos = static_cast<float>(Map_Height);
   if   (m_fAnimPhase > 6.9f)
                m_fAnimPhase = 0.0f;
   if   (m_fAnimPhase < 0.0f)
                m_fAnimPhase = 0.0f;
   g_pDebugscreen->Set("Animphase: ", m_fAnimPhase);
 
}

void CPlayer::LifeDec()												// Leben reduzieren
{
	if (m_Life > 0)
		m_Life--;
	if (m_Life < 0)
		Reset();
}