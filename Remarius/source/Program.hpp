#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Menu.hpp"
#include "Text.hpp"
#include "XMLhandler.hpp"
#include "Game.hpp"
#include "Programpart.hpp"
#include <vector>

class CProgram
{
public:
	CProgram ();

	void Run ();
	void Quit ();


private:
	bool	m_bEnd;
	CText	*pText;
	TTF_Font* pFont;
	int		state;
	vector<CProgrampart*> part;
	void	gamestart();
};

#endif