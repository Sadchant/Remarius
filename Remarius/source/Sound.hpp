#ifndef SOUND_HPP
#define SOUND_HPP

#include "SDL_mixer.h"
#include "Framework.hpp"


class CSound
{
	public:
		CSound ();
		~CSound ();
		void		Load		(string sFilename);
		void		Play		();
		void		SetVolume	(int Volume);

	private:
		Mix_Chunk*		pSound;
		
};


#endif
