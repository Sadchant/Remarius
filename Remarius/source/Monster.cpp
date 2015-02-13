#include "Monster.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
 
CMonster::CMonster() :
monsterSprite(g_pLoader->getTexture("T_PLAYER"))
{
}
void CMonster::Update ()
{
	if (m_fDamageTimer > 0.0f) m_fDamageTimer -= g_pTimer->GetElapsed();
	switch (m_MoveMode)
	{
	case 1:
		{
			Knockback();
		} break;
	case 2:
		{
			Orientate();
		} break;
	case 3:
		{
			Move3();
		} break;
	case 4:
		{
			Move4();
		} break;
	case 5:
		{
			Move5();
		}
	};
	m_Rect.y = static_cast<int>(m_fYPos);															// Rect bewegen
	m_Rect.x = static_cast<int>(m_fXPos);

	/*if ((m_fYPos > 768.0f) || (m_fYPos < 0.0f))														// Deaktivieren, falls außerhalb des Bildschirms
		m_bIsAlive = false;
	if ((m_fXPos > 1024.0f) || (m_fXPos < 0.0f))
		m_bIsAlive = false;*/
}
void CMonster::Render (float CameraX, float CameraY)
{
	if (m_bAnimFlipper == 0)
		m_fAnimCounter += 15.0f * g_pTimer->GetElapsed ();
	if  (m_bAnimFlipper == 1)
		m_fAnimCounter -= 15.0f * g_pTimer->GetElapsed ();

	if ((m_fAnimCounter > 0.0f) && (m_fAnimCounter <=1.0f))
		animPhase = 0;


	if ((m_fAnimCounter <= 0.0f))
		m_bAnimFlipper = 0;

	if ((m_fAnimCounter >1.0f) && (m_fAnimCounter <=3.0f))
		animPhase = 1;

	if ((m_fAnimCounter >3.0f) && (m_fAnimCounter <=5.0f))
		animPhase = 2;

	if ((m_fAnimCounter >5.0f) && (m_fAnimCounter <=6.0f))
		animPhase = 3;


	if ((m_fAnimCounter > 6.0f))
	{
		animPhase = 3;
		m_bAnimFlipper = 1;
	}

	monsterSprite.SetPos(m_fXPos - CameraX, m_fYPos - CameraY);
	monsterSprite.Render (animPhase, m_SpriteDirection);
}
void CMonster::DoDamage(int Damage)
{
	if (life - Damage >= 0)
		if (m_fDamageTimer <= 0.0f)
		{
			life -= Damage;
			m_fDamageTimer = 0.2f;
		} else {}
	else OnDeath();
}
void CMonster::DoDamage(int X, int Y, int Damage)
{
	DoDamage(static_cast<float>(1.0f + atan((m_fXPos - X)/(m_fYPos - Y)) / (M_PI * 2)), Damage);
}
void CMonster::DoDamage(float Direction, int Damage)
{
	DoDamage(Damage);
	m_fDirection = Direction;
	m_fKnockbackDuration = 0.2f;
	m_MoveMode = 1;
}
void CMonster::Knockback()
{
	m_fXPos += static_cast<float>(500.0f * sin(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
	m_fYPos += static_cast<float>(500.0f * cos(m_fDirection * 2 * M_PI) * g_pTimer->GetElapsed());
	m_fKnockbackDuration -= g_pTimer->GetElapsed();
	if (m_fKnockbackDuration <= 0.0f) m_MoveMode = 2;
}
void CMonster::Orientate()
{
	m_MoveMode = 3;
}
void CMonster::Move3()
{
}
void CMonster::Move4()
{
}
void CMonster::Move5()
{
}