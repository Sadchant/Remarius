#include "Sound.hpp"

CSound::CSound ()																				
{
	m_pMusic = NULL;
	m_pSound = NULL;
	if (Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		cout << "SDL_Mixer konnte nicht initialisiert werden" << endl;
		Quit ();
	}
}

CSound::~CSound ()
{
	Mix_FreeMusic (m_pMusic);
	Mix_FreeChunk (m_pSound);
	Mix_CloseAudio ();
	Mix_Quit();
}

void CSound::OpenMusic (const string sFilename)														
{
	m_pMusic = Mix_LoadMUS (sFilename.c_str ());										// Musik laden
	if (m_pMusic == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
	
		Quit ();																		// Sound beenden
	}

}

void CSound::OpenSound (const string sFilename)														
{
	m_pSound = Mix_LoadWAV (sFilename.c_str ());										// Musik laden
	if (m_pSound == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;
	
		Quit ();																			// Sound beenden
	}

}

void CSound::PlayMusic ()									 // Musik wird abgespielt
{
	if (Mix_PlayingMusic() == 0)
	{
		if (Mix_PlayMusic (m_pMusic, -1) == -1)
		{
			cout << "Fehler beim Abspielen von Musik" << endl;
			Quit ();
		}
	}
}

void CSound::PlaySound ()									 // Sound wird abgespielt
{
	if (Mix_PlayChannel (-1, m_pSound, 0) == -1)
	{
		cout << "Fehler beim Abspielen von Sound" << endl;
		Quit ();
	}
}

void CSound::SetVolume (int Volume)
{
	if (Volume > 128)
		Volume = 128;
	if (Volume < -1)
		Volume = -1;
	Mix_VolumeMusic (Volume);
}

void CSound::PauseMusic ()
{
	if (Mix_PlayingMusic () == 1)
		Mix_PauseMusic();		

}

void CSound::StopMusic ()
{
	if (Mix_PlayingMusic () == 1)
		Mix_HaltMusic();
}

void CSound::Quit ()
{
	Mix_FreeMusic (m_pMusic);
	Mix_FreeChunk (m_pSound);
	Mix_CloseAudio();
}