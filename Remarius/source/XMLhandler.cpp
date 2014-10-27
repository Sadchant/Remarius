#include "XMLhandler.hpp"

CXMLhandler::CXMLhandler()
{
	XMLDocument* doc = new XMLDocument();
}

bool CXMLhandler::readoptions()
{
	XMLDocument doc;
	doc.LoadFile("Config.xml");
	if (doc.ErrorID())
		return false;

	XMLElement* titleelement = doc.FirstChildElement("Options")->FirstChildElement("Fullscreen")->FirstChildElement("v");
	const char* title = titleelement->GetText();
	g_pOptions->Fullscreen = atoi(title);
	cout << title << endl;
	cout << g_pOptions->Fullscreen << endl;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->Music = atoi(title);
	cout << title << endl;
	cout << g_pOptions->Music << endl;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->Volume = atoi(title);
	cout << title << endl;
	cout << g_pOptions->Volume << endl;
}

bool CXMLhandler::writeoptions()
{
	XMLDocument doc;
	doc.LoadFile("Config.xml");
	if (doc.ErrorID())
		return false;
	
	XMLElement* titleelement = doc.FirstChildElement("Options")->FirstChildElement("Fullscreen")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Fullscreen);
	cout << "Fullscreen saved" << endl;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Music);
	cout << "Music saved" << endl;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Volume);
	cout << "Volume saved" << endl;
	doc.SaveFile("Config.xml");
	readoptions();
}

