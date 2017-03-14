// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TRIUTILITIES_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TRIUTILITIES_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#if defined(_WIN32)                   // MS Windows
	#ifdef TRIUTILITIES_EXPORTS
	#define TRIUTILITIES_API __declspec(dllexport)
	#else
	#define TRIUTILITIES_API __declspec(dllimport)
	#endif
#elif defined(__APPLE__)                 // for MAC    
	#define TRIUTILITIES_API          __attribute__((visibility("default")))
#endif


//// This class is exported from the TriUtilities.dll
class TRIUTILITIES_API CTriUtilities {
public:
	CTriUtilities(void);
};

extern TRIUTILITIES_API int nTriUtilities;

TRIUTILITIES_API int fnTriUtilities(void);
