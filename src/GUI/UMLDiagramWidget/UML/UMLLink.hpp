#ifndef UMLLINK_HPP
#define UMLLINK_HPP


#include "../DrawableElement.hpp"
#include "../../../utils/CairoDrawer.hpp"

#include <gtkmm.h>

class UMLClass;

class UMLLink : public DrawableElement
{
public:
	UMLLink(UMLClass* class1, UMLClass* class2);
	void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnElement(int x, int y);

private:
	UMLClass* _class1;
	UMLClass* _class2;
};

#endif /* UMLLINK_HPP */