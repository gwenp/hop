#include "UMLMember.hpp"

UMLMember::UMLMember(Visibility visibility, std::string type, std::string name) : _visibility(visibility), _type(type), _name(name)
{

}

UMLMember::~UMLMember()
{

}

Visibility UMLMember::getVisibility()
{
	return _visibility;
}

void UMLMember::setVisibility(Visibility visibility)
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

