#ifndef UMLMEMBER_HPP
#define UMLMEMBER_HPP

#include <string>

namespace Visibility{
	enum Type{
		PUBLIC, PROTECTED, PRIVATE, PACKAGE, STATIC
	};

	std::string convertToString(Type type);
	std::string convertToSymbol(Type type);
	Type convertFromString(std::string s);
};

class UMLMember
{
public:
	UMLMember(Visibility::Type visibility, std::string type, std::string name);
	~UMLMember();

	Visibility::Type getVisibility();
	void setVisibility(Visibility::Type visibility);

	std::string getType();
	void setType(std::string type);

	std::string getName();
	void setName(std::string name);

private:
	std::string _type;
	std::string _name;

	Visibility::Type _visibility;
};

#endif /* UMLMEMBER_HPP */