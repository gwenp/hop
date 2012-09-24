#ifndef UMLMEMBER_HPP
#define UMLMEMBER_HPP

#include <string>

enum Visibility{
	PUBLIC, PROTECTED, PRIVATE
};

class UMLMember
{
public:
	UMLMember(Visibility visibility, std::string type, std::string name);
	~UMLMember();

	Visibility getVisibility();
	void setVisibility(Visibility visibility);

	std::string getType();
	void setType(std::string type);

	std::string getName();
	void setName(std::string name);

private:
	std::string _type;
	std::string _name;

	Visibility _visibility;
};

#endif /* UMLMEMBER_HPP */