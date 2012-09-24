#include "PropertySignatureEditor.hpp"

PropertySignatureEditor::PropertySignatureEditor(UMLProperty* property) 
	: _property(property), Gtk::HBox()
{
	_entryName = new Gtk::Entry();
	_entryName->set_text(property->getName());
	pack_start(*_entryName, false,true);

	show_all_children();
}

PropertySignatureEditor::~PropertySignatureEditor()
{

}