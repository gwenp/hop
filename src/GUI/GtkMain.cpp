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

	
	Gtk::ToolButton* addClassButton = 0;
	builder->get_widget("addClassButton", addClassButton);
	addClassButton->signal_clicked().connect(sigc::mem_fun(*diagram, &UMLDiagramWidget::setAddClassMode));

	Gtk::ToolButton* pointerButton = 0;
	builder->get_widget("pointerButton", pointerButton);
	pointerButton->signal_clicked().connect(sigc::mem_fun(*diagram, &UMLDiagramWidget::setPointerMode));

	Gtk::ToolButton* linkButton = 0;
	builder->get_widget("linkButton", linkButton);
	linkButton->signal_clicked().connect(sigc::mem_fun(*diagram, &UMLDiagramWidget::setLinkMode));

	Gtk::ToolButton* inheritanceLinkButton = 0;
	builder->get_widget("inheritanceLinkButton", inheritanceLinkButton);
	inheritanceLinkButton->signal_clicked().connect(sigc::mem_fun(*diagram, &UMLDiagramWidget::setInheritanceLinkMode));

	Gtk::ToolButton* addPackageButton = 0;
	builder->get_widget("addPackageButton", addPackageButton);
	addPackageButton->signal_clicked().connect(sigc::mem_fun(*diagram, &UMLDiagramWidget::setAddPackageMode));

    kit.run(*mainWindow);
}
