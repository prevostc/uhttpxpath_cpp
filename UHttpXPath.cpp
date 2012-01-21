#include "UHttpXPath.hh"

// Register the UObject in the Urbi world. 
UStart(UHttpXPath); 
 

UHttpXPath::UHttpXPath(const std::string& name) : urbi::UObject(name) {
	// Register the Urbi constructor.  
	// This is the only mandatory part of the C++ constructor.
	UBindFunction(UHttpXPath, init); 
}
 
int UHttpXPath::init() {
	// Bind the functions, i.e., declare them to the Urbi world
	// LOCK_INSTANCE Prevent parallel call to any function of this object.. 
	UBindThreadedFunction(UHttpXPath, xPathQuery, urbi::LOCK_INSTANCE);
	UBindThreadedFunction(UHttpXPath, performRequest, urbi::LOCK_INSTANCE);
	UBindThreadedFunction(UHttpXPath, setHttpProxy, urbi::LOCK_INSTANCE);
	return 0; 
}

std::string UHttpXPath::xPathQuery(std::string xPathQuery) {
	return httpxpath.xPathQuery(xPathQuery.c_str());
}

bool UHttpXPath::performRequest(std::string url) {
	this->httpxpath.performRequest(url);
	return true;
}

bool UHttpXPath::setHttpProxy(std::string url, long port) {
	this->httpxpath.setHttpProxy(url, port);
	return true;
}

 
