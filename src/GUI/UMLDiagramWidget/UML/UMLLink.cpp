#include "UMLLink.hpp"

#include "UMLClass.hpp"

UMLLink::UMLLink(UMLClass* class1, UMLClass* class2) : _class1(class1), _class2(class2)
{

}

void UMLLink::draw(Gtk::DrawingArea* drawingArea)
{
	// std::cout << "UMLLink::draw" << _class1->getCenterX() << ";" << _class1->getCenterY() << ";" << _class2->getCenterX() << ";" << _class2->getCenterY() << std::endl;
	int x1, x2;
	int y1, y2;

	if(_class1->getCenterX() > _class2->getCenterX())
		x1 = _class2->getCenterX() + _class2->getWidth()/2;
	else
		x1 = _class1->getCenterX() + _class1->getWidth()/2;

	CairoDrawer::drawLine(drawingArea->get_window(), x1,_class1->getCenterY(),_class2->getCenterX(), _class2->getCenterY());
}

bool UMLLink::isPointOnElement(int x, int y)
{
	return false;
}
