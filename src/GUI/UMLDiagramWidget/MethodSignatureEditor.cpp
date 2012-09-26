#include "MethodSignatureEditor.hpp"

MethodSignatureEditor::MethodSignatureEditor(UMLMethod* method)
	: SignatureEditor(), _method(method)
{
	_comboVisibility = new Gtk::ComboBoxText();
	pack_start(*_comboVisibility, false,true);
	_comboVisibility->append_text("Public");
	_comboVisibility->append_text("Protected");
	_comboVisibility->append_text("Private");
	_comboVisibility->append_text("Package");
	_comboVisibility->append_text("Static");

	_comboVisibility->set_active_text(Visibility::convertToString(method->getVisibility()));

	_entryType = new Gtk::Entry();
	_entryType->set_text(method->getType());
	pack_start(*_entryType, false,true);

	_entryName = new Gtk::Entry();
	_entryName->set_text(method->getName());
	pack_start(*_entryName, true,true);

	show_all_children();
}

MethodSignatureEditor::~MethodSignatureEditor()
{

}

void MethodSignatureEditor::applyChanges()
{
	_method->setName(_entryName->get_text());
	_method->setType(_entryType->get_text());
}
