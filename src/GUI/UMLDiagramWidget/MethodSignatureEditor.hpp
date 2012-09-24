#ifndef METHODSIGNATUREEDITOR_HPP
#define METHODSIGNATUREEDITOR_HPP

#include <vector>
#include <string>

#include <gtkmm.h>

#include "UML/UMLMethod.hpp"

class MethodSignatureEditor : public Gtk::HBox
{
public:
	MethodSignatureEditor(UMLMethod* method);
	~MethodSignatureEditor();

private:
	UMLMethod* _method;
	
	Gtk::ComboBoxText* _comboVisibility;
	Gtk::Entry* _entryType;
	Gtk::Entry* _entryName;
};

#endif /* METHODSIGNATUREEDITOR_HPP */