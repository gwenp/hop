#include "Generator.hpp"

Generator::Generator(int argc, char *argv[])
{
	Dbg::out("CLI_args_parsing") << "arguments : " << std::endl;

	for (int i = 1; i < argc; ++i)
	{
		Dbg::out("CLI_args_parsing") << argv[i] << std::endl;
	}


	if(argc > 2)
	{
		_templateFile = argv[1];
		_dataFile = argv[2];
	}
}

Generator::~Generator()
{}

void Generator::parseFiles()
{
	_parseData();
	_parseTemplate();
}

void Generator::compute()
{
	Dbg::out("methods_runned") << "compute" << std::endl;

	for (std::vector<std::pair<std::string, std::string > >::iterator it = _dataContent.begin(); it != _dataContent.end(); ++it)
	{
		std::string currentToken = "$" + (*it).first + "$";
		__replace(_templateContent, currentToken, (*it).second);
	}
}

void Generator::print()
{
	Dbg::out("methods_runned") << "print" << std::endl;
	Dbg::out("result") << _templateContent << std::endl;
}

void Generator::_parseData()
{
	Dbg::out("methods_runned") << "_parseData" << std::endl;

	std::ifstream ifs(_dataFile);

	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse( ifs, root );
	if ( !parsingSuccessful )
	{
	    // report to the user the failure and their locations in the document.
    	Dbg::out("Critical error") 	<< "Failed to parse configuration\n"
	               					<< reader.getFormattedErrorMessages()
	               					<< std::endl;
	    return;
	}

	const Json::Value data = root["data"];

	std::vector<std::string> dataMembers = data.getMemberNames();

	for (std::vector<std::string>::iterator it = dataMembers.begin(); it != dataMembers.end(); ++it)
	{
		std::pair<std::string, std::string> newPair;
		newPair.first = (*it);
		
		std::string newPairValue = data[(*it)].asString();
		newPair.second = newPairValue;

		_dataContent.push_back(newPair);
	}
}

void Generator::_parseTemplate()
{
	Dbg::out("methods_runned") << "_parseTemplate" << std::endl;

	std::ifstream ifs(_templateFile);

	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse( ifs, root );
	if ( !parsingSuccessful )
	{
	    // report to the user the failure and their locations in the document.
    	Dbg::out("Critical error") 	<< "Failed to parse configuration\n"
	               					<< reader.getFormattedErrorMessages()
	               					<< std::endl;
	    return;
	}

	_templateContent = root["listing"].asString();
}

