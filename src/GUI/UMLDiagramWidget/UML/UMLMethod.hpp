#ifndef UMLMETHOD_HPP
#define UMLMETHOD_HPP

#include <string>

#include "UMLMember.hpp"

class UMLMethod : public UMLMember
{
public:
	UMLMethod(std::string name);
	~UMLMethod();

private:
};

#endif /* UMLMETHOD_HPP */