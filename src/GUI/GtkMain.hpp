#ifndef GTKMAIN_HPP
#define GTKMAIN_HPP

#include "../Debug/Dbg.hpp"
#include "UMLDiagramWidget/UMLDiagramWidget.hpp"

#include <vector>
#include <string>

#include <gtkmm.h>

class GtkMain
{
public:
	GtkMain();
	~GtkMain();

	void startUI(int argc, char *argv[]);
private:
	Glib::RefPtr<Gtk::Builder> builder;

};

#endif /* GTKMAIN_HPP */