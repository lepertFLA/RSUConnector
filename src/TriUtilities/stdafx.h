// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef __APPLE__


#elif _WIN32
    #include "targetver.h"
    #define WIN64_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
    // Windows Header Files:
    #include <windows.h>
#endif 






// reference additional headers your program requires here
