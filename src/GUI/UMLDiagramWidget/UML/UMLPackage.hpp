#ifndef UMLPACKAGE_HPP
#define UMLPACKAGE_HPP

#include "UMLMethod.hpp"
#include "UMLProperty.hpp"

#include "../DrawableElement.hpp"
#include "../../../Debug/Dbg.hpp"
#include "../../../utils/CairoDrawer.hpp"

#include <gtkmm.h>

class UMLPackage : public DrawableElement
{
public:
	UMLPackage(int x, int y, int w, int h);
	void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnElement(int x, int y);

	void setName(std::string name);
	std::string getName();

	void moveTo(int x, int y);

	int getCenterX();
	int getCenterY();

	int getWidth();
	int getHeight();

	virtual ElementType::Type getType();

private:
	int _x;
	int _y;
	int _w;
	int _h;

	std::string _name;
};

#endif /* UMLPACKAGE_HPP */