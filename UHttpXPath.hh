#ifndef UTEST_HH 
#define UTEST_HH 

// Include the UObject declarations. 
#include <urbi/uobject.hh> 

#include <iostream>

// include custom lib
#include "HttpXPath.hh"

/// A UObject wrapping a custom object. 
class UHttpXPath : public urbi::UObject
{ 
	public: 
		// C++ contructor. 
		// @param name  name given to the instance. 
		UHttpXPath(const std::string& name); 

		// Urbi constructor. 
		int init(); 

		// execute an xpath query on the requested page
                std::string xPathQuery(std::string xPathQuery);
		
		// perform an http request
		bool performRequest(std::string url);

		// set the http proxy
                bool setHttpProxy(std::string url, long port); 

	protected:
		HttpXPath httpxpath; 
}; 
#endif // ! UTEST_HH 
