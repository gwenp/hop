#ifndef DRAWABLEELEMENT_HPP
#define DRAWABLEELEMENT_HPP

#include <gtkmm.h>

namespace ElementType
{
	enum Type
	{
		CLASS,
		PACKAGE,
		LINK
	};
}

class DrawableElement
{
public:
	virtual void draw(Gtk::DrawingArea* drawingArea) =0;
	virtual bool isPointOnElement(int x, int y) =0;
	void setSelected(bool selected){ _selected = selected; };

	virtual ElementType::Type getType() =0;
protected:
	bool isSelected(){ return _selected; };
private:
	bool _selected;
};

#endif /* DRAWABLEELEMENT_HPP */