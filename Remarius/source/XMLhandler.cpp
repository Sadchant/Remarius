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
	g_pOptions->Fullscreen = bool(atoi(title));

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->Music = bool(atoi(title));

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->Volume = atoi(title);
	
	return true;
}

bool CXMLhandler::writeoptions()
{
	XMLDocument doc;
	doc.LoadFile("Config.xml");
	if (doc.ErrorID())
		return false;
	
	XMLElement* titleelement = doc.FirstChildElement("Options")->FirstChildElement("Fullscreen")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Fullscreen);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Music);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->Volume);
	doc.SaveFile("Config.xml");

	return true;
}

