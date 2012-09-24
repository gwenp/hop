#ifndef UMLMEMBER_HPP
#define UMLMEMBER_HPP

#include <string>

class UMLMember
{
public:
	UMLMember(std::string name);
	~UMLMember();

	std::string getName();
	void setName(std::string name);

private:
	std::string _name;
};

#endif /* UMLMEMBER_HPP */