#pragma once
 

#include "../stdafx.h"
#include <string>
#include <iostream>

#ifdef __APPLE__
	#include "dlfcn.h"
#elif _WIN32

#endif 



using namespace std;


class FileHelpers
{
public:
//----- Construction and destruction -----------------------------------
    
    FileHelpers() 
    {
    }

    ~FileHelpers() 
    {
    }

	static string ExePath() 
	{ 

		#if defined(_WIN32)                   // MS Windows
			char buffer[MAX_PATH]; 
			GetModuleFileName( NULL, buffer, MAX_PATH ); 
		#elif defined(__APPLE__)                 // for MAC    
			char buffer[PATH_MAX]; 
		    Dl_info info;
    		if (dladdr((void *)ExePath, &info)) {
				strcpy( buffer, info.dli_fname );
    		}
		#endif

		string::size_type pos = string( buffer ).find_last_of( "\\/" ); 
		if( pos > 0 ) {
			return string( buffer ).substr( 0, pos);
		}
		return( "" );
	} 


//----- Private members ----------------------------------------------
private:

};
