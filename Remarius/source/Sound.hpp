#ifndef SOUND_HPP
#define SOUND_HPP

#include "SDL_mixer.h"
#include "Framework.hpp"


class CSound
{
	public:
		CSound ();
		~CSound ();
		void		Quit ();
		void		OpenMusic	(const string sFilename);
		void		OpenSound	(const string sFilename);
		void		PlayMusic	();
		void		PlaySound	();
		void		SetVolume	(int Volume);
		void		PauseMusic	();
		void		StopMusic	();

	private:
		Mix_Music		*m_pMusic;
		Mix_Chunk		*m_pSound;
		
};


#endif
