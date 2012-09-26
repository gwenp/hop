#ifndef UMLINHERITANCELINK_HPP
#define UMLINHERITANCELINK_HPP


#include "../../../utils/CairoDrawer.hpp"
#include "../../../utils/Arrows.hpp"

#include <gtkmm.h>
#include "UMLLink.hpp"

class UMLInheritanceLink : public UMLLink
{
public:
	UMLInheritanceLink(UMLClass* class1, UMLClass* class2);

	void draw(Gtk::DrawingArea* drawingArea);
};

#endif /* UMLINHERITANCELINK_HPP */