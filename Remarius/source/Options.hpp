#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "Singleton.hpp"
#include <string>

#define g_pOptions COptions::Get()

class COptions : public TSingleton<COptions>
{
public:
	bool	fullscreen = false;
	bool	music = true;
	int		volume = 5;
	int		window_width = 1280;
	int		window_height = 720;
	std::string	window_name = "Remarius Risation";
};
#endif