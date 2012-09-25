#ifndef METHODSIGNATUREEDITOR_HPP
#define METHODSIGNATUREEDITOR_HPP

#include <vector>
#include <string>

#include <gtkmm.h>

#include "UML/UMLMethod.hpp"
#include "SignatureEditor.hpp"

class MethodSignatureEditor : public SignatureEditor
{
public:
	MethodSignatureEditor(UMLMethod* method);
	~MethodSignatureEditor();

	void applyChanges();

private:
	UMLMethod* _method;
	
	Gtk::ComboBoxText* _comboVisibility;
	Gtk::Entry* _entryType;
	Gtk::Entry* _entryName;
};

#endif /* METHODSIGNATUREEDITOR_HPP */