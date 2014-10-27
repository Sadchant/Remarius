#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Menu.hpp"
#include "Text.hpp"
#include "XMLhandler.hpp"

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

};

#endif