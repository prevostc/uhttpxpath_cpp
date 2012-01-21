#include "HttpXPath.hh"


void HttpXPath::setHttpProxy(std::string url, long port) 
{
	curlpp::options::Url urlOpt(url);
	this->request.setOpt(urlOpt);
}

void HttpXPath::performRequest(std::string url) 
{
	// set url option
	curlpp::options::Url urlOpt(url);
	this->request.setOpt(urlOpt);

	// write html page within a string stream
	std::stringstream stream;
	curlpp::options::WriteStream ws(&stream);
	this->request.setOpt(ws);

	// With that call, the request will be done and the content of that URL
	// will be printed in a stringstream.
	this->request.perform();

	// create xml document from html stream
	stream >> this->doc;
}



std::string HttpXPath::xPathQuery(std::string xPathQuery)
{
	// process xpath query
	TIXML_STRING res;
	TinyXPath::xpath_processor xp_procedure(this->doc.RootElement(), xPathQuery.c_str());
	res = xp_procedure.S_compute_xpath();

	#ifdef HTTPXPATH_DEBUG
		std::cout << "============= HttpXPath::xPathQuery ==============" << std::endl;
		std::cout << "DOC [" << this->doc << "]" << std::endl;
		std::cout << "QUERY : [" << xPathQuery << "]" << std::endl;	
		std::cout << "RES : [" << res.c_str() << "]" << std::endl;	
		std::cout << "==================================================" << std::endl;
	#endif  // HTTPXPATH_DEBUG

	return res.c_str();
}


