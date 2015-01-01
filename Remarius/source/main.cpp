#include "main.h"

//initialisiert das Framework, erzeugt ein neues Programm, lässt es laufen und beendet alles wieder
int main (int argc, char *argv[])
{
	CXMLhandler XMLhandler;
	XMLhandler.readoptions();
	/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);*/
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
