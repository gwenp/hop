#include "UMLClass.hpp"

UMLClass::UMLClass()
	: DrawableElement(), _x(26), _y(26), _w(56), _name("untitled")
{
	Dbg::out("ctor") << "UMLClass::ctor1" << std::endl;

}

UMLClass::UMLClass(int x, int y)
	: _x(x), _y(y), _w(56), _name("untitled")
{
	Dbg::out("ctor") << "UMLClass::ctor2" << std::endl;
	addMethod(new UMLMethod(Visibility::PUBLIC, "null", "ctor"));
	addMethod(new UMLMethod(Visibility::PROTECTED, "int", "addElement"));
	addProperty(new UMLProperty(Visibility::PRIVATE, "void", "getElement"));
}

void UMLClass::draw(Gtk::DrawingArea* drawingArea)
{
	Dbg::out("draw") << "UMLClass::draw" << std::endl;

 	Glib::RefPtr<Gdk::Window> window = drawingArea->get_window();

	Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
	
	cr->set_source_rgb (0.5, 0.5, 1);
	CairoDrawer::drawRectangle(drawingArea->get_window(), _x,_y, _w, getHeight());

	int offset = 28;
	CairoDrawer::drawLine(drawingArea->get_window(), _x,_y+offset, _x+_w,_y+offset);
	
	offset +=4;

	for (std::vector<UMLProperty*>::iterator it = _properties.begin(); it != _properties.end(); ++it)
	{
		std::string row = Visibility::convertToSymbol((*it)->getVisibility()) + " " + (*it)->getName();
		CairoDrawer::drawText(drawingArea->get_window(), _x+10,_y+offset, row, "sans 7");
		offset += 16;
	}

	CairoDrawer::drawLine(drawingArea->get_window(), _x,_y+offset, _x+_w,_y+offset);

	offset += 4;

	for (std::vector<UMLMethod*>::iterator it = _methods.begin(); it != _methods.end(); ++it)
	{
		std::string row = Visibility::convertToSymbol((*it)->getVisibility()) + " " + (*it)->getName();
		CairoDrawer::drawText(drawingArea->get_window(), _x+10,_y+offset, row, "sans 7");
		offset += 16;
	}


	Rect r = CairoDrawer::drawText(drawingArea->get_window(), _x+10,_y+5, getName(), "sans 10");
	if(r.w + 20 > _w)
		_w = r.w + 20;
}

bool UMLClass::isPointOnElement(int x, int y)
{
	if(x > _x && y > _y && x < _x + _w && y <_y + getHeight() )
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

void UMLClass::addProperty(UMLProperty* p)
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

void UMLClass::moveTo(int x, int y)
{
	std::cout << "moveTo " << x << "," << y << std::endl;
	_x = x;
	_y = y;
}

int UMLClass::getCenterX()
{
	return _x+_w/2;
}

int UMLClass::getCenterY()
{
	return _y+getHeight()/2;
}

int UMLClass::getHeight()
{
	return 28 + 4 + _properties.size() * 16 + 4 + _methods.size() * 16;
}

int UMLClass::getWidth()
{
	return _w;
}

ElementType::Type UMLClass::getType()
{
	return ElementType::CLASS;
}
