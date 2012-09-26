#include "UMLPackage.hpp"

UMLPackage::UMLPackage(int x, int y, int w, int h)
	: _x(x), _y(y), _w(w), _h(h), _name("untitled")
{
	Dbg::out("ctor") << "UMLPackage::ctor2" << std::endl;
}

void UMLPackage::draw(Gtk::DrawingArea* drawingArea)
{
	Dbg::out("draw") << "UMLPackage::draw" << std::endl;

 	Glib::RefPtr<Gdk::Window> window = drawingArea->get_window();

	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
	
	cr->set_source_rgb (0.5, 0.5, 1);
	CairoDrawer::drawRectangle(drawingArea->get_window(), _x,_y, _w, _h);

	Rect r = CairoDrawer::drawText(drawingArea->get_window(), _x+6,_y-22, getName(), "sans 10");
	CairoDrawer::drawRectangle(drawingArea->get_window(), r.x -6 , r.y, r.w + 12, r.h+5);
	CairoDrawer::drawText(drawingArea->get_window(),_x+6,_y-20, getName(), "sans 10");

}

bool UMLPackage::isPointOnElement(int x, int y)
{
	if(x > _x && y > _y && x < _x + _w && y <_y + getHeight() )
		return true;
	else
		return false;
}

void UMLPackage::setName(std::string name)
{
	_name = name;	
}

std::string UMLPackage::getName()
{
	return _name;
}

void UMLPackage::moveTo(int x, int y)
{
	std::cout << "UMLPackage::moveTo " << x << "," << y << std::endl;
	_x = x;
	_y = y;
}

int UMLPackage::getCenterX()
{
	return _x+_w/2;
}

int UMLPackage::getCenterY()
{
	return _y+getHeight()/2;
}

int UMLPackage::getHeight()
{
	return _h;
}

int UMLPackage::getWidth()
{
	return _w;
}

ElementType::Type UMLPackage::getType()
{
	return ElementType::PACKAGE;
}
