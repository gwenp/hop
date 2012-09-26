#include "UMLInheritanceLink.hpp"

#include "UMLClass.hpp"

UMLInheritanceLink::UMLInheritanceLink(UMLClass* class1, UMLClass* class2) : UMLLink(class1, class2)
{

}

void UMLInheritanceLink::draw(Gtk::DrawingArea* drawingArea)
{
	Cairo::RefPtr<Cairo::Context> cr = drawingArea->get_window()->create_cairo_context();

	Arrows::draw_arrow(cr, getX1(), getY1(), getX2(), getY2(), Arrow::NORMAL, Arrow::NONE, isSelected());
}