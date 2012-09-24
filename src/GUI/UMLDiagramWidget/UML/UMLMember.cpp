#include "UMLMember.hpp"

UMLMember::UMLMember(std::string name) : _name(name)
{

}

UMLMember::~UMLMember()
{

}

std::string UMLMember::getName()
{
	return _name;
}

void UMLMember::setName(std::string name)
{
	_name = name;
}

