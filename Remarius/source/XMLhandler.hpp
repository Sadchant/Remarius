#ifndef XMLHANDLER_HPP
#define XMLHANDLER_HPP

#include "tinyxml2.h"
#include "Options.hpp"
#include <iostream>

using namespace tinyxml2;
using namespace std;

class CXMLhandler
{
public:
	CXMLhandler ();

	bool readoptions ();
	bool writeoptions ();
	
};

#endif