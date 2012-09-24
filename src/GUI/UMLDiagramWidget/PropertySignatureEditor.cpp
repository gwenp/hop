#include "PropertySignatureEditor.hpp"

PropertySignatureEditor::PropertySignatureEditor(UMLProperty* property) 
	: _property(property), Gtk::HBox()
{
	_comboVisibility = new Gtk::ComboBoxText();
	pack_start(*_comboVisibility, false,true);
	_comboVisibility->append_text("Public");
	_comboVisibility->append_text("Protected");
	_comboVisibility->append_text("Private");

	_entryType = new Gtk::Entry();
	_entryType->set_text(property->getType());
	pack_start(*_entryType, false,true);

	_entryName = new Gtk::Entry();
	_entryName->set_text(property->getName());
	pack_start(*_entryName, false,true);

	show_all_children();
}

PropertySignatureEditor::~PropertySignatureEditor()
{

}