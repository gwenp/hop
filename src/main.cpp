#include <string>
#include <fstream>

#include "Generator/Generator.hpp"
#include "GUI/GtkMain.hpp"

#include "Debug/Dbg.hpp"

int main(int argc, char *argv[])
{
	Dbg::init("config/debug.conf");
	Generator g(argc, argv);

	GtkMain gtkMain;

	gtkMain.startUI(argc,argv);
	
	// g.parseFiles();
	// g.compute();
	// g.print();
}
