#ifndef UMLLINK_HPP
#define UMLLINK_HPP


#include "../DrawableElement.hpp"
#include "../../../utils/CairoDrawer.hpp"
#include "../../../utils/Arrows.hpp"

#include <gtkmm.h>

class UMLClass;

class UMLLink : public DrawableElement
{
public:
	UMLLink(UMLClass* class1, UMLClass* class2);
	virtual void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnElement(int x, int y);

	virtual ElementType::Type getType();
protected:
	int getX1();
	int getY1();
	int getX2();
	int getY2();

private:
	UMLClass* _class1;
	UMLClass* _class2;
};

#endif /* UMLLINK_HPP */