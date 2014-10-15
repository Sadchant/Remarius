#include "Music.hpp"

CMusic::CMusic()
{
	pMusic = NULL;
}

CMusic::~CMusic()
{
	Mix_FreeMusic(pMusic);
}

void CMusic::Load (const string sFilename)
{
	pMusic = Mix_LoadMUS(sFilename.c_str());										// Musik laden
	if (pMusic == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError() << endl;						// Sound beenden
	}

}

void CMusic::Play ()									 // Musik wird abgespielt
{
	if (Mix_PlayingMusic() == 0)
	{
		if (Mix_PlayMusic(pMusic, -1) == -1)
		{
			cout << "Fehler beim Abspielen von Musik" << endl;
		}
	}
}


void CMusic::SetVolume(int Volume)
{
	if (Volume > 128)
		Volume = 128;
	if (Volume < -1)
		Volume = -1;
	Mix_VolumeMusic(Volume);
}

void CMusic::PauseMusic(bool b)
{
	if (Mix_PausedMusic() && b)
		Mix_ResumeMusic();
	else if (!Mix_PausedMusic() && !b)
		Mix_PauseMusic();
}

void CMusic::StopMusic()
{
	if (Mix_PlayingMusic() == 1)
		Mix_HaltMusic();
}
