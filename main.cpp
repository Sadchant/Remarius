#include "main.h"

int main (int argc, char *argv[])
{
	if (g_pFramework->Init () == false)									// (1024, 768, 32, true) für Release
		return (0);	

	cout << "Framework komplett initialisiert" << endl;
	CProgram Program;													// neues Program erstellen

	Program.Run();														// Program laufen lassen

	Program.Quit();														// Program beenden

	g_pFramework->Quit ();												// Framework beenden
	g_pFramework->Del ();

	return (0);
}
