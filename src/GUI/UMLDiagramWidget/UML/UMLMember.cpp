#include "UMLMember.hpp"

namespace Visibility{
	std::string convertToString(Type type)
	{
		switch(type)
		{
			case PUBLIC:
				return "Public";
				break;
			case PROTECTED:
				return "Protected";
				break;
			case PRIVATE:
				return "Private";
				break;
			case PACKAGE:
				return "Package";
				break;
			case STATIC:
				return "Static";
				break;
		}
	};

	std::string convertToSymbol(Type type)
	{
		switch(type)
		{
			case PUBLIC:
				return "+";
				break;
			case PROTECTED:
				return "#";
				break;
			case PRIVATE:
				return "-";
				break;
			case PACKAGE:
				return "~";
				break;
			case STATIC:
				return "_";
				break;
		}		
	}

	Type convertFromString(std::string s)
	{
			if( s == "Public")
				return PUBLIC;
			if( s == "Protected")
				return PROTECTED;
			if( s == "Private")
				return PRIVATE;
			if( s == "Package")
				return PACKAGE;
			if( s == "Static")
				return STATIC;
	};
}
UMLMember::UMLMember(Visibility::Type visibility, std::string type, std::string name) : _visibility(visibility), _type(type), _name(name)
{

}

UMLMember::~UMLMember()
{

}

Visibility::Type UMLMember::getVisibility()
{
	return _visibility;
}

void UMLMember::setVisibility(Visibility::Type visibility)
{
	_visibility = visibility;
}

std::string UMLMember::getType()
{
	return _type;
}

void UMLMember::setType(std::string type)
{
	_type = type;
}

std::string UMLMember::getName()
{
	return _name;
}

void UMLMember::setName(std::string name)
{
	_name = name;
}

