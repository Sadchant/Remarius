#include "main.h"

void InitOptions()
{
	CXMLhandler XMLhandler;
	XMLhandler.readoptions();
}

void InitMemoryChecker()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}


//initialisiert das Framework, erzeugt ein neues Programm, lässt es laufen und beendet alles wieder
int main (int argc, char *argv[])
{
	InitOptions();
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




