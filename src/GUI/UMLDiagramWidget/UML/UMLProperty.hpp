#ifndef UMLPROPERTY_HPP
#define UMLPROPERTY_HPP

#include <string>

#include "UMLMember.hpp"

class UMLProperty : public UMLMember
{
public:
	UMLProperty(std::string name);
	~UMLProperty();

private:
};

#endif /* UMLPROPERTY_HPP */