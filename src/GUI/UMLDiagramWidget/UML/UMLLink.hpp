#ifndef UMLLINK_HPP
#define UMLLINK_HPP


#include "../DrawableElement.hpp"
#include "../../../utils/CairoDrawer.hpp"
#include "../../../utils/Arrows.hpp"

#include <gtkmm.h>

namespace LinkTypes{
	enum Types
	{
		ASSOCIATION,
		COMPOSITION,
		AGGREGATION,
		NAVIGATION,
		DEPENDENCY
	};
}

class UMLClass;

class UMLLink : public DrawableElement
{
public:
	UMLLink(UMLClass* class1, UMLClass* class2);
	virtual void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnElement(int x, int y);

	virtual ElementType::Type getType();

	LinkTypes::Types getLinkTypeBegin();
	LinkTypes::Types getLinkTypeEnd();

	std::string getMultiplicityBegin();
	std::string getMultiplicityEnd();

	void setLinkTypeBegin(LinkTypes::Types linkTypeBegin);
	void setLinkTypeEnd(LinkTypes::Types linkTypeEnd);

	void setMultiplicityBegin(std::string multiplicityBegin);
	void setMultiplicityEnd(std::string multiplicityEnd);
protected:
	int getX1();
	int getY1();
	int getX2();
	int getY2();

private:
	UMLClass* _class1;
	UMLClass* _class2;

	std::string _multiplicity_begin;
	LinkTypes::Types _linkType_begin;
	std::string _multiplicity_end;
	LinkTypes::Types _linkType_end;
};

#endif /* UMLLINK_HPP */