#include "main.h"

//initialisiert das Framework, erzeugt ein neues Programm, lässt es laufen und beendet alles wieder
int main (int argc, char *argv[])
{
	if (g_pFramework->Init() == false)
	{
		return (0);	
	}		
	CProgram Program;	
	Program.Run();														
	Program.Quit();														
	g_pFramework->Quit ();												
	g_pFramework->Del ();
	return (0);
}
