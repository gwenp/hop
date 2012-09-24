#ifndef UMLCLASS_HPP
#define UMLCLASS_HPP

#include "UMLMethod.hpp"
#include "UMLProperty.hpp"

#include "../../../Debug/Dbg.hpp"
#include "../../../utils/CairoDrawer.hpp"

#include <gtkmm.h>

class UMLClass
{
public:
	UMLClass();
	UMLClass(int x, int y);
	void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnClass(int x, int y);

	void setName(std::string name);
	std::string getName();

	void addMethod(UMLMethod* m);
	void addPropery(UMLProperty* p);

	std::vector<UMLMethod*>* getMethods();	
	std::vector<UMLProperty*>* getProperties();
private:
	std::vector<UMLMethod*> _methods;
	std::vector<UMLProperty*> _properties;


	int _x;
	int _y;
	int _w;
	int _h;

	std::string _name;

};

#endif /* UMLCLASS_HPP */