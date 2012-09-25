#ifndef DRAWABLEELEMENT_HPP
#define DRAWABLEELEMENT_HPP

#include <gtkmm.h>

class DrawableElement
{
public:
	virtual void draw(Gtk::DrawingArea* drawingArea) =0;
	virtual bool isPointOnElement(int x, int y) =0;
private:
};

#endif /* DRAWABLEELEMENT_HPP */