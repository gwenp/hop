#include "UMLDiagramWidget.hpp"

UMLDiagramWidget::UMLDiagramWidget(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder): Gtk::DrawingArea(cobject)
{
	add_events( Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | Gdk::POINTER_MOTION_MASK);

	signal_expose_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_expose_event), false);
	signal_button_press_event().connect(sigc::mem_fun(*this, &UMLDiagramWidget::on_button_press_event), false);

  	std::cout << "UMLDiagramWidget::ctor" << std::endl;

  	Gtk::Menu::MenuList& menulist = _classPopupMenu.items();
	
	menulist.push_back( Gtk::Menu_Helpers::MenuElem("Properties",sigc::mem_fun(*this, &UMLDiagramWidget::on_UMLClass_openProperties) ) );

    widgetBuilder = Gtk::Builder::create_from_file("res/UMLDiagramWidget_classProperties.glade");

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
		for (std::vector<UMLClass>::iterator it = _elements.begin(); it != _elements.end(); ++it)
		{
  			std::cout << "UMLDiagramWidget::drawElt" << std::endl;

			(*it).draw(this);
		}
	}

  return true;
}

bool UMLDiagramWidget::on_button_press_event(GdkEventButton* event)
{
  	std::cout << "UMLDiagramWidget::click button=" << event->button << std::endl;

  	_currentlySelectedElement = NULL;
  	for (std::vector<UMLClass>::iterator it = _elements.begin(); it != _elements.end(); ++it)
  	{
  		if((*it).isPointOnClass(event->x, event->y))
  			_currentlySelectedElement = &(*it);
  	}

  	if(event->button == 1)
  	{
		_elements.push_back(UMLClass(event->x-28,event->y-28));
		queue_draw();
  	}
 
	if(event->button == 3 && _currentlySelectedElement != NULL)
	{
		_classPopupMenu.popup(event->button, event->time);
	}
}

void UMLDiagramWidget::on_UMLClass_openProperties()
{
	std::cout << "UMLDiagramWidget::on_UMLClass_openProperties" << std::endl;

	if(_currentlySelectedElement != NULL)
	{
		UMLClassPropertiesWindow* classPropertiesWindow = NULL;

		widgetBuilder->get_widget_derived("classPropertiesWindow", classPropertiesWindow);

		classPropertiesWindow->setMainWidget(this);
		classPropertiesWindow->show();		
		classPropertiesWindow->setUMLClass(_currentlySelectedElement);
	}
	else
		std::cout << "UMLDiagramWidget::noclassSelectedError" << std::endl;
}