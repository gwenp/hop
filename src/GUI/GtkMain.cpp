#include "GtkMain.hpp"

GtkMain::GtkMain()
{

}

GtkMain::~GtkMain()
{

}

void GtkMain::startUI(int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);

    builder = Gtk::Builder::create_from_file("res/hop_ui.glade");

    Gtk::Window* mainWindow = 0;
	builder->get_widget("mainWindow", mainWindow);
	
	UMLDiagramWidget* diagram = 0;
	builder->get_widget_derived("mainDrawingArea", diagram);
	diagram->show();

    kit.run(*mainWindow);

}
