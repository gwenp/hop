#ifndef UMLCLASS_HPP
#define UMLCLASS_HPP

#include "UMLMethod.hpp"
#include "UMLProperty.hpp"

#include "../DrawableElement.hpp"
#include "../../../Debug/Dbg.hpp"
#include "../../../utils/CairoDrawer.hpp"

#include <gtkmm.h>

class UMLClass : public DrawableElement
{
public:
	UMLClass();
	UMLClass(int x, int y);
	void draw(Gtk::DrawingArea* drawingArea);
	bool isPointOnElement(int x, int y);

	void setName(std::string name);
	std::string getName();

	void addMethod(UMLMethod* m);
	void addProperty(UMLProperty* p);

	std::vector<UMLMethod*>* getMethods();	
	std::vector<UMLProperty*>* getProperties();


	void moveTo(int x, int y);

	int getCenterX();
	int getCenterY();

	int getWidth();
	int getHeight();

	virtual ElementType::Type getType();

private:
	std::vector<UMLMethod*> _methods;
	std::vector<UMLProperty*> _properties;



	int _x;
	int _y;
	int _w;

	std::string _name;

};

#endif /* UMLCLASS_HPP */