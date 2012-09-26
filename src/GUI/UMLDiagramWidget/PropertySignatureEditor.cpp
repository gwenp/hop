#include "PropertySignatureEditor.hpp"

PropertySignatureEditor::PropertySignatureEditor(UMLProperty* property) 
	: _property(property), SignatureEditor()
{
	_comboVisibility = new Gtk::ComboBoxText();
	pack_start(*_comboVisibility, false,true);
	_comboVisibility->append_text("Public");
	_comboVisibility->append_text("Protected");
	_comboVisibility->append_text("Private");

	_comboVisibility->set_active_text(Visibility::convertToString(property->getVisibility()));
	


	_entryType = new Gtk::Entry();
	_entryType->set_text(property->getType());
	pack_start(*_entryType, false,true);

	_entryName = new Gtk::Entry();
	_entryName->set_text(property->getName());
	pack_start(*_entryName, true,true);

	show_all_children();
}

PropertySignatureEditor::~PropertySignatureEditor()
{

}

void PropertySignatureEditor::applyChanges()
{
	_property->setName(_entryName->get_text());
	_property->setType(_entryType->get_text());
}
