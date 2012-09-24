#ifndef UMLDIAGRAMWIDGET_HPP
#define UMLDIAGRAMWIDGET_HPP

#include "UMLClassPropertiesWindow.hpp"
#include "UML/UMLClass.hpp"
#include "../../Debug/Dbg.hpp"

#include <vector>
#include <string>

#include <gtkmm.h>


class UMLDiagramWidget : public Gtk::DrawingArea
{
public:
	UMLDiagramWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	~UMLDiagramWidget();

protected:
  //Override default signal handler:
	bool on_expose_event(GdkEventExpose* event);
	bool on_button_press_event(GdkEventButton* event);
	void on_UMLClass_openProperties();

	std::vector<UMLClass> _elements;
	Gtk::Menu _classPopupMenu;

	UMLClass* _currentlySelectedElement;

	Glib::RefPtr<Gtk::Builder> widgetBuilder;


};

#endif /* UMLDIAGRAMWIDGET_HPP */