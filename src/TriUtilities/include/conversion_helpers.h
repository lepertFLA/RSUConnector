#pragma once
 

#include "../stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>



using namespace std;

class ConversionHelpers
{
public:
//----- Construction and destruction -----------------------------------
    
    ConversionHelpers() 
    {
    }

    ~ConversionHelpers() 
    {
    }

	static bool TwosComplimentHexStrToLongLong( string sValue, long long& lValue ) 
	{ 
		int nRet = 0;
		lValue = 0;
		long long llTemp;
		long lTemp;
		long long lMax;
		if( sValue.length() <= 0 )
			return( false );

		int nSigDigit = sValue[0];
		if( nSigDigit >= 56 )
		{
			nRet = sscanf( sValue.c_str(), "%llx", &llTemp ); 
			if( nRet == 0 || nRet == EOF )
				return( false );

			nRet = sscanf( "0XFFFFFFFF", "%llx", &lMax ); 
			if( nRet == 0 || nRet == EOF )
				return( false );

			lValue = ( llTemp - lMax - 1);
		}
		else
		{
			nRet = sscanf( sValue.c_str(), "%lx", &lTemp ); 
			if( nRet == 0 || nRet == EOF )
				return( false );
			lValue = lTemp;
		}
		return( true );
	} 
	
	static bool ConvertTwosComplementHexStrToDegrees( string sValue, string& sDegrees ) 
	{ 
		long long lValue;
		double dValue;
		if( ! TwosComplimentHexStrToLongLong( sValue, lValue ) )
			return( false );
		else
		{
			std::stringstream ss; 
			dValue = ( lValue * ( 180.0 / 33554432.0 ) );
			ss << std::setprecision(std::numeric_limits<double>::digits10); 
			ss << dValue;
			sDegrees = ss.str();
		}
		return( true );
	}

	//----- Private members ----------------------------------------------
	private:

};
