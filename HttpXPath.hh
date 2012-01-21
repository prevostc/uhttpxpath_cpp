#ifndef HTTPXPATH_HH
#define HTTPXPATH_HH

#include <string>
#include <sstream>
#include <iostream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <tinyxml.h>
#include "xpath_static.h"

// Use xpath to parse http web pages
class HttpXPath {

	public:
		// execute an xpath query on the requested page
		std::string xPathQuery(std::string xPathQuery);

		// perform an http request
		void  performRequest(std::string url);
		
		// set the http proxy
		void setHttpProxy(std::string url, long port);

	protected:
		// cURLpp::Cleanup is just an utility class that does cURLpp::initialize() 
		// within the constructor and cURLpp::terminate() within the destructor.
		curlpp::Cleanup cleanup;
		
		// request handler
		curlpp::Easy request;

		// the html page using xml structures
		TiXmlDocument doc;
};

#endif // HTTPXPATH_HH
