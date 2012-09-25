#ifndef PROPERTYSIGNATUREEDITOR_HPP
#define PROPERTYSIGNATUREEDITOR_HPP

#include <vector>
#include <string>

#include <gtkmm.h>

#include "UML/UMLProperty.hpp"
#include "SignatureEditor.hpp"

class PropertySignatureEditor : public SignatureEditor
{
public:
	PropertySignatureEditor(UMLProperty* property);
	~PropertySignatureEditor();

	void applyChanges();
private:
	UMLProperty* _property;

	Gtk::ComboBoxText* _comboVisibility;
	Gtk::Entry* _entryName;
	Gtk::Entry* _entryType;
};

#endif /* PROPERTYSIGNATUREEDITOR_HPP */