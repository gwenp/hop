#ifndef UMLDIAGRAMWIDGET_HPP
#define UMLDIAGRAMWIDGET_HPP

#include "UMLClassPropertiesWindow.hpp"
#include "UMLLinkPropertiesWindow.hpp"
#include "UML/UMLClass.hpp"
#include "UML/UMLLink.hpp"
#include "UML/UMLInheritanceLink.hpp"
#include "../../Debug/Dbg.hpp"

#include <vector>
#include <string>

#include <gtkmm.h>

enum PointerMode
{
	POINTER,
	LINK,
	INHERITANCELINK,
	ADDCLASS
};


class UMLDiagramWidget : public Gtk::DrawingArea
{
public:
	UMLDiagramWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder);
	~UMLDiagramWidget();

	void setPointerMode();
	void setAddClassMode();
	void setLinkMode();
	void setInheritanceLinkMode();
protected:
  //Override default signal handler:
	bool on_expose_event(GdkEventExpose* event);
	bool on_button_press_event(GdkEventButton* event);
	bool on_button_release_event(GdkEventButton* event);
	bool on_mouse_motion_event(GdkEventMotion* event);
	void on_UMLClass_openProperties();

	void startLink(int x,int y);	
	void stopLink(int x,int y);	

	DrawableElement* findElementAt(int x, int y);
	void connectElements(DrawableElement* elt1, DrawableElement* elt2);
private:	
	bool _isLinkStarted;
	int _link_x1;
	int _link_y1;

	int _mouseButtonPressed;

	std::vector<DrawableElement*> _elements;
	Gtk::Menu _classPopupMenu;

	DrawableElement* _currentlySelectedElement;

	Glib::RefPtr<Gtk::Builder> widgetBuilder;

	PointerMode _pointerMode;
};

#endif /* UMLDIAGRAMWIDGET_HPP */