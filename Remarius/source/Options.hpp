#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "Singleton.hpp"

#define g_pOptions COptions::Get()

class COptions : public TSingleton<COptions>
{
public:
	COptions();
	bool	Fullscreen;
	bool	Music;
	int		Volume;
};
#endif