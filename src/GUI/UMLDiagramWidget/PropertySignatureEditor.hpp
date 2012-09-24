#ifndef PROPERTYSIGNATUREEDITOR_HPP
#define PROPERTYSIGNATUREEDITOR_HPP

#include <vector>
#include <string>

#include <gtkmm.h>

#include "UML/UMLProperty.hpp"

class PropertySignatureEditor : public Gtk::HBox
{
public:
	PropertySignatureEditor(UMLProperty* property);
	~PropertySignatureEditor();

private:
	UMLProperty* _property;
	Gtk::Entry* _entryName;
};

#endif /* PROPERTYSIGNATUREEDITOR_HPP */