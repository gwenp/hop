#include "UMLClass.hpp"

UMLClass::UMLClass()
	: _x(26), _y(26), _w(56), _h(56), _name("untitled")
{
	Dbg::out("ctor") << "UMLClass::ctor1" << std::endl;

}

UMLClass::UMLClass(int x, int y)
	: _x(x), _y(y), _w(56), _h(56), _name("untitled")
{
	Dbg::out("ctor") << "UMLClass::ctor2" << std::endl;
	addMethod(new UMLMethod("ctor"));
	addMethod(new UMLMethod("addElement"));
	addPropery(new UMLProperty("getElement"));
}

void UMLClass::draw(Gtk::DrawingArea* drawingArea)
{
	Dbg::out("draw") << "UMLClass::draw" << std::endl;

 	Glib::RefPtr<Gdk::Window> window = drawingArea->get_window();

	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
	
	cr->set_source_rgb (0.5, 0.5, 1);
	CairoDrawer::drawRectangle(drawingArea->get_window(), _x,_y, _w,_h);

	CairoDrawer::drawLine(drawingArea->get_window(), _x,_y+28, _x+_w,_y+28);
	CairoDrawer::drawLine(drawingArea->get_window(), _x,_y+42, _x+_w,_y+42);
	CairoDrawer::drawLine(drawingArea->get_window(), _x,_y+42, _x+_w,_y+42);

	CairoDrawer::drawText(drawingArea->get_window(), _x+10,_y+5, getName());
}

bool UMLClass::isPointOnClass(int x, int y)
{
	if(x > _x && y > _y && x < _x + _w && y <_y + _h )
		return true;
	else
		return false;
}

void UMLClass::setName(std::string name)
{
	_name = name;	
}

std::string UMLClass::getName()
{
	return _name;
}

void UMLClass::addMethod(UMLMethod* m)
{
	_methods.push_back(m);
}

void UMLClass::addPropery(UMLProperty* p)
{
	_properties.push_back(p);
}

std::vector<UMLMethod*>* UMLClass::getMethods()
{
	return &_methods;
}

std::vector<UMLProperty*>* UMLClass::getProperties()
{
	return &_properties;
}

