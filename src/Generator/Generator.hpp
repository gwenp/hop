#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "../Debug/Dbg.hpp"

#include <vector>
#include <string>

class Generator
{
public:
	Generator(int argc, char *argv[]);
	~Generator();

	void parseFiles();
	void compute();
	void print();
private:

	void __replace(std::string& str, const std::string& oldStr, const std::string& newStr)
	{
	  size_t pos = 0;
	  while((pos = str.find(oldStr, pos)) != std::string::npos)
	  {
	     str.replace(pos, oldStr.length(), newStr);
	     pos += newStr.length();
	  }
	};

	void _parseData();
	void _parseTemplate();

	std::string _dataFile;
	std::string _templateFile;

	std::vector<std::pair<std::string, std::string> > _dataContent;
	std::string _templateContent;

};

#endif /* GENERATOR_HPP */