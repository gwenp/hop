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

	int class1x1 = _class1->getCenterX() - _class1->getWidth() / 2;
	int class1x2 = _class1->getCenterX() + _class1->getWidth() / 2;
	int class2x1 = _class2->getCenterX() - _class2->getWidth() / 2;
	int class2x2 = _class2->getCenterX() + _class2->getWidth() / 2;

	int class1y1 = _class1->getCenterY() - _class1->getHeight() / 2;
	int class1y2 = _class1->getCenterY() + _class1->getHeight() / 2;
	int class2y1 = _class2->getCenterY() - _class2->getHeight() / 2;
	int class2y2 = _class2->getCenterY() + _class2->getHeight() / 2;


	if(class1x2 < class2x1)
	{
		x1 = _class2->getCenterX() - _class2->getWidth()/2;
		x2 = _class1->getCenterX() + _class1->getWidth()/2;
		std::cout << "a" << std::endl;
	}
	else if(class1x1 > class2x2)
	{
		x1 = _class2->getCenterX() + _class2->getWidth()/2;
		x2 = _class1->getCenterX() - _class1->getWidth()/2;
		std::cout << "b" << std::endl;
	}
	else
	{
		x1 = _class2->getCenterX();
		x2 = _class1->getCenterX();
		std::cout << "c" << std::endl;
	}

	if(class1y2 < class2y1)
	{
		y1 = _class2->getCenterY() - _class2->getHeight()/2;
		y2 = _class1->getCenterY() + _class1->getHeight()/2;
		std::cout << "a" << std::endl;
	}
	else if(class1y1 > class2y2)
	{
		y1 = _class2->getCenterY() + _class2->getHeight()/2;
		y2 = _class1->getCenterY() - _class1->getHeight()/2;
		std::cout << "b" << std::endl;
	}
	else
	{
		y1 = _class2->getCenterY();
		y2 = _class1->getCenterY();
		std::cout << "c" << std::endl;
	}


	CairoDrawer::drawLine(drawingArea->get_window(), x1, y1, x2, y2);
}

bool UMLLink::isPointOnElement(int x, int y)
{
	return false;
}
