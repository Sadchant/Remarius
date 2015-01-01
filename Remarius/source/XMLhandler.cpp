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
	g_pOptions->fullscreen = (atoi(title)) ? true : false;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->music = (atoi(title))? true : false ;

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->volume = atoi(title);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Resolution")->FirstChildElement("width")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->window_width = atoi(title);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Resolution")->FirstChildElement("height")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->window_height = atoi(title);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("WindowName")->FirstChildElement("v");
	title = titleelement->GetText();
	g_pOptions->window_name = title;

	return true;
}

bool CXMLhandler::writeoptions()
{
	XMLDocument doc;
	doc.LoadFile("Config.xml");
	if (doc.ErrorID())
		return false;
	
	XMLElement* titleelement = doc.FirstChildElement("Options")->FirstChildElement("Fullscreen")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->fullscreen);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Music")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->music);

	titleelement = doc.FirstChildElement("Options")->FirstChildElement("Volume")->FirstChildElement("v");
	titleelement->SetText(g_pOptions->volume);
	doc.SaveFile("Config.xml");

	return true;
}

