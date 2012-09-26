#include "UMLDiagramWidget.hpp"

UMLDiagramWidget::UMLDiagramWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder): Gtk::DrawingArea(cobject), _isLinkStarted(false), _mouseButtonPressed(0)
{
	add_events( Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | Gdk::POINTER_MOTION_MASK);

	signal_expose_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_expose_event), false);
	signal_button_press_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_button_press_event), false);
	signal_button_release_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_button_release_event), false);
	signal_motion_notify_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_mouse_motion_event), false);

  	std::cout << "UMLDiagramWidget::ctor" << std::endl;

  	Gtk::Menu::MenuList& menulist = _classPopupMenu.items();
	
	menulist.push_back( Gtk::Menu_Helpers::MenuElem("Properties",sigc::mem_fun(*this, &UMLDiagramWidget::on_UMLClass_openProperties) ) );

    widgetBuilder = Gtk::Builder::create_from_file("res/UMLDiagramWidget_PropertiesWindows.glade");
}

UMLDiagramWidget::~UMLDiagramWidget()
{
}

bool UMLDiagramWidget::on_expose_event(GdkEventExpose* event)
{
 	Glib::RefPtr<Gdk::Window> window = get_window();
	
	if (window)
	{		
		Gtk::Allocation a = get_allocation();
		const int w = a.get_width();
		const int h = a.get_height();
		
		int xc, yc;
		xc = w/2;
		yc = h/2;
		
		Cairo::RefPtr<Cairo::Context> cr = window->create_cairo_context();
		cr->set_line_width(1.0);
		
		int wx = 0;
		int wy = 0;
		translate_coordinates(*(get_toplevel()),0, -20,wx,wy);

		Cairo::RefPtr< Cairo::LinearGradient > background_gradient_ptr = Cairo::LinearGradient::create (0, 0, 0, a.get_height());
		background_gradient_ptr->add_color_stop_rgb (0,.70,0.70,0.70);
		background_gradient_ptr->add_color_stop_rgb (1,0.55,0.55,0.55);

		// Draw a rectangle and fill with gradient
		cr->set_source (background_gradient_ptr);
		cr->rectangle (0, 0, w, h); 
		cr->fill();
	
		cr->set_source_rgb(0.86, 0.85, 0.47);
		for (std::vector<DrawableElement*>::iterator it = _elements.begin(); it != _elements.end(); ++it)
		{
  			std::cout << "UMLDiagramWidget::drawElt" << std::endl;

			(*it)->draw(this);
		}

	}

  return true;
}

bool UMLDiagramWidget::on_button_press_event(GdkEventButton* event)
{
  	std::cout << "UMLDiagramWidget::click button=" << event->button << std::endl;

  	_currentlySelectedElement = NULL;
  	for (std::vector<DrawableElement*>::iterator it = _elements.begin(); it != _elements.end(); ++it)
  	{
  		(*it)->setSelected(false);

  		if((*it)->isPointOnElement(event->x, event->y))
  		{
  			_currentlySelectedElement = (*it);
  			(*it)->setSelected(true);
  		}
  	}

  	if(event->button == 1)
  	{
  		switch(_pointerMode)
		{
			case ADDCLASS:
				_elements.push_back(new UMLClass(event->x-28,event->y-28));
				break;
			case LINK:
				startLink(event->x,event->y);
				break;
			case INHERITANCELINK:
				startLink(event->x,event->y);
				break;
		}

		queue_draw();
  	}
 
	if(event->button == 3 && _currentlySelectedElement != NULL)
	{
		_classPopupMenu.popup(event->button, event->time);
	}

	_mouseButtonPressed = event->button;
}

bool UMLDiagramWidget::on_button_release_event(GdkEventButton* event)
{
	std::cout << "UMLDiagramWidget::release button=" << event->button << std::endl;

	if(event->button == 1)
	{
		switch(_pointerMode)
		{
			case ADDCLASS:
				break;
			case LINK:
				stopLink(event->x,event->y);
				break;
			case INHERITANCELINK:
				stopLink(event->x,event->y);
				break;
		}

		queue_draw();
	}
	_mouseButtonPressed = 0;
}

bool UMLDiagramWidget::on_mouse_motion_event(GdkEventMotion* event)
{
	if(_isLinkStarted)
	{
		CairoDrawer::drawLine(get_window(), _link_x1,_link_y1,event->x, event->y);
		// queue_draw();
	}

	switch(_pointerMode)
	{
		case POINTER:
			if(_mouseButtonPressed == 1 && _currentlySelectedElement != NULL )
			{
				UMLClass* selectedClass = (UMLClass*) _currentlySelectedElement;
				selectedClass->moveTo(event->x, event->y);
				queue_draw();
			}
			break;
	}

}

void UMLDiagramWidget::on_UMLClass_openProperties()
{
	std::cout << "UMLDiagramWidget::on_UMLClass_openProperties" << std::endl;

	if(_currentlySelectedElement != NULL)
	{
		if(_currentlySelectedElement->getType() == ElementType::BOX)
		{
			UMLClassPropertiesWindow* classPropertiesWindow = NULL;

			widgetBuilder->get_widget_derived("classPropertiesWindow", classPropertiesWindow);

			classPropertiesWindow->setMainWidget(this);
			classPropertiesWindow->show();		
			//FIXME this will bug if the selected object is not a class
			classPropertiesWindow->setUMLClass((UMLClass*)_currentlySelectedElement);
		}
		else
		{
			UMLLinkPropertiesWindow* linkPropertiesWindow = NULL;

			widgetBuilder->get_widget_derived("linkPropertiesWindow", linkPropertiesWindow);

			linkPropertiesWindow->setMainWidget(this);
			linkPropertiesWindow->show();		

			linkPropertiesWindow->setUMLLink((UMLLink*)_currentlySelectedElement);
		}
	}
	else
		std::cout << "UMLDiagramWidget::noclassSelectedError" << std::endl;
}

void UMLDiagramWidget::setPointerMode()
{
	_pointerMode = POINTER;
}

void UMLDiagramWidget::setAddClassMode()
{
	_pointerMode = ADDCLASS;
}

void UMLDiagramWidget::setLinkMode()
{
	_pointerMode = LINK;
}

void UMLDiagramWidget::setInheritanceLinkMode()
{
	_pointerMode = INHERITANCELINK;
}


void UMLDiagramWidget::startLink(int x,int y)
{
	_isLinkStarted = true;
	_link_x1 = x;
	_link_y1 = y;
}

void UMLDiagramWidget::stopLink(int x,int y)
{
	_isLinkStarted = false;

	DrawableElement* elt1 = findElementAt(_link_x1, _link_y1);
	DrawableElement* elt2 = findElementAt(x, y);

	if(elt1 != NULL && elt2 != NULL)
	{
		connectElements(elt1, elt2);
	}
}

DrawableElement* UMLDiagramWidget::findElementAt(int x, int y)
{
	for (std::vector<DrawableElement*>::iterator it = _elements.begin(); it != _elements.end(); ++it)
	{
		if((*it)->isPointOnElement(x,y))
		{
			return (*it);
		}
	}
	return NULL;
}

void UMLDiagramWidget::connectElements(DrawableElement* elt1, DrawableElement* elt2)
{
	switch(_pointerMode)
	{
		case LINK:
			_elements.push_back(new UMLLink((UMLClass*)elt1,(UMLClass*)elt2));
			break;
		case INHERITANCELINK:
			if(elt1 != elt2)
				_elements.push_back(new UMLInheritanceLink((UMLClass*)elt1,(UMLClass*)elt2));
			break;
	}

}
