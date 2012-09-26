#ifndef UMLPROPERTY_HPP
#define UMLPROPERTY_HPP

#include <string>

#include "UMLMember.hpp"

class UMLProperty : public UMLMember
{
public:
	UMLProperty(Visibility::Type visibility, std::string type, std::string name);
	~UMLProperty();

private:
};

#endif /* UMLPROPERTY_HPP */