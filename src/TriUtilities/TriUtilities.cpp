// TriUtilities.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TriUtilities.h"
#include "include/tri_error.h"
#include "include/file_helpers.h"
#include "include/conversion_helpers.h"

// This is an example of an exported variable
TRIUTILITIES_API int nTriUtilities=0;

 //This is an example of an exported function.
TRIUTILITIES_API int fnTriUtilities(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see TriUtilities.h for the class definition
CTriUtilities::CTriUtilities()
{
	return;
}
