#include "Sound.hpp"

CSound::CSound ()																				
{
	pSound = NULL;
}

CSound::~CSound ()
{
	Mix_FreeChunk (pSound);
}

void CSound::Load (const string sFilename)														
{
	pSound = Mix_LoadWAV (sFilename.c_str ());										// Musik laden
	if (pSound == NULL)																// Prüfen, ob alles glatt ging
	{
		cout << "Fehler beim Laden von: " << sFilename.c_str ();
		cout << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;																				// Sound beenden
	}

}


void CSound::Play ()									 // Sound wird abgespielt
{
	if (Mix_PlayChannel (-1, pSound, 0) == -1)
	{
		cout << "Fehler beim Abspielen von Sound" << endl;
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