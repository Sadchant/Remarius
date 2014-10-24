#ifndef MUSIC_HPP
#define MUSIC_HPP

#include "Framework.hpp"


class CMusic
{
public:
	CMusic();
	~CMusic();
	void		Load		(string sFilename);
	void		Play		();
	void		SetVolume	(int Volume);
	void		PauseMusic(bool b = false);	// true to resume music, false (default) to pause music
	void		StopMusic();

private:
	Mix_Music*		pMusic;

};


#endif
